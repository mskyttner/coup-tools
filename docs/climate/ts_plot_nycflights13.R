# use tools from https://tidyverts.org/
# tutorial at https://education.rstudio.com/blog/2020/02/conf20-ts/

library(tsibble)
library(dplyr)
library(units)
library(tidyr)
library(fable)
library(plotly)

# load some timeseries data
weather <-
  nycflights13::weather %>%
  select(origin, time_hour, temp, humid, precip)

weather_tsbl <-
  as_tsibble(weather, key = origin, index = time_hour)

# hourly interval, but could be yearly etc
interval(weather_tsbl)

# where there are missings, we can fill gaps
# with explicit value or use the "last known"
full_weather <-
  weather_tsbl %>%
  fill_gaps(precip = 0) %>%
  group_by_key() %>%
  tidyr::fill(temp, humid, .direction = "down")

# calculate montly aggregates
monthly <-
  full_weather %>%
  group_by_key() %>%
  index_by(year_month = ~ yearmonth(.)) %>% # monthly aggregates
  summarise(
    avg_temp = mean(temp, na.rm = TRUE),
    ttl_precip = sum(precip, na.rm = TRUE)
  )

precip <-
  monthly %>%
  pull(ttl_precip) %>%
  set_units("mm")

units(precip) <- with(ud_units, "in")

# we now have the monthly precipitation in inches instead of mm
# we can proceed to plot it in a HTML-friendly interactive format

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

htmlwidgets::saveWidget(my_widget, "~/mywidget.html")
browseURL("~/mywidget.html")
