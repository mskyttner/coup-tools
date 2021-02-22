#!/usr/bin/env Rscript

# use tools from https://tidyverts.org/
# tutorial at https://education.rstudio.com/blog/2020/02/conf20-ts/

library(tsibble)
library(dplyr)
library(units)
library(tidyr)
library(fable)
library(plotly)
library(readxl)
library(lubridate)
library(dygraphs)
library(htmltools)
library(htmlwidgets)
library(purrr)
library(rlang)

# # example using nycflights13 to load some timeseries data
# weather <-
#   nycflights13::weather %>%
#   select(origin, time_hour, temp, humid, precip)
#
# weather_tsbl <-
#   as_tsibble(weather, key = origin, index = time_hour)
#
# # hourly interval, but could be yearly etc
# interval(weather_tsbl)
#
# # where there are missings, we can fill gaps
# # with explicit value or use the "last known"
# full_weather <-
#   weather_tsbl %>%
#   fill_gaps(precip = 0) %>%
#   group_by_key() %>%
#   tidyr::fill(temp, humid, .direction = "down")
#
# # calculate monthly aggregates
# monthly <-
#   full_weather %>%
#   group_by_key() %>%
#   index_by(year_month = ~ yearmonth(.)) %>% # monthly aggregates
#   summarise(
#     avg_temp = mean(temp, na.rm = TRUE),
#     ttl_precip = sum(precip, na.rm = TRUE)
#   )
#
# precip <-
#   monthly %>%
#   pull(ttl_precip) %>%
#   set_units("mm")
#
# units(precip) <- with(ud_units, "in")
#
# # we now have the monthly precipitation in inches instead of mm
# # we can proceed to plot it in a HTML-friendly interactive format
#
# my_ts <-
#   monthly %>%
#   bind_cols(tibble(rain = as.numeric(precip))) %>%
#   select(year_month, rain)
#
# my_plot <-
#   my_ts %>%
#   fabletools::autoplot(rain)
#
# themed <- my_plot +
#   ggplot2::ylab(label = "rain (inches)") +
#   ggplot2::xlab(label = "month") +
#   ggthemes::theme_wsj()
#
# my_html <- plotly::ggplotly(themed)
#
# my_widget <- plotly::as_widget(my_html)
#
# htmlwidgets::saveWidget(my_widget, "~/mywidget.html")
# browseURL("~/mywidget.html")

args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
  stop("Please provide a valid xls file path as input")
}

if (length(args) == 1) {
  file <- normalizePath(args[1], mustWork = TRUE)
  message("Input file is ", file)
  stopifnot(file.exists(file))
  if (!grepl("(.*?)\\.xls$", basename(file)))
    stop("Please provide an .xls file as input...")
}

read_xls_climate <- function(xlsfile) {
  climate <-
    readxl::read_xls(file, skip = 3)

  header <-
    readxl::read_xls(file, n_max = 3)

  header <-
    header %>%
    setNames(nm = gsub("...1", "Date", names(header), fixed = TRUE))

  fields <-
    header %>%
    summarise(across(everything(), .fns = list(
      function(x) trimws(paste0(collapse = " ", ifelse(is.na(x), "", x)))))
    ) %>% t() %>% as.data.frame() %>%
    tibble(field = names(header), title = as.character(.data$V1)) %>%
    mutate(label = sprintf("%s (%s)", field, title)) %>%
    select(title = field, label)

  names(climate) <- fields$title

  return(climate)

}

monthly <-
  read_xls_climate(file) %>%
  # use two columns - precipitation and temperature
  select(Date, precip = Precipitation, temp = Temperature) %>%
  mutate(origin = "excel") %>%
  mutate(date = as_date(ymd_hm(Date))) %>%
  as_tsibble(key = origin, index = date) %>%
  # fill in 0 for missing rain, use latest value for temp
  fill_gaps(precip = 0) %>%
  group_by_key() %>%
  tidyr::fill(temp, .direction = "down") %>%
  # monthly aggregates
  group_by_key() %>%
  index_by(year_month = ~ yearmonth(.)) %>%
  summarise(
    avg_temp = mean(temp, na.rm = TRUE),
    ttl_precip = sum(precip, na.rm = TRUE)
  )

# example conversion; monthly precipitation in inches instead of mm

precip <-
  monthly %>%
  pull(ttl_precip) %>%
  set_units("mm")

units(precip) <- with(ud_units, "in")

# we can proceed to plot it in a HTML-friendly interactive format
# this can be made into a function that takes a data (frame) input

my_ts <-
  monthly %>%
  bind_cols(tibble(rain = as.numeric(precip))) %>%
  select(year_month, rain)

my_plot <-
  my_ts %>%
  fabletools::autoplot(rain)

themed <- my_plot +
  ggplot2::ylab(label = "rain (inches)") +
  ggplot2::xlab(label = "month") +
  ggthemes::theme_wsj()

my_html <- plotly::ggplotly(themed)

my_widget <- plotly::as_widget(my_html)

out <- "monthly.html"
htmlwidgets::saveWidget(my_widget, out)
