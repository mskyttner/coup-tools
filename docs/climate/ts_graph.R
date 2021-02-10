#!/usr/bin/env Rscript

library(readxl)
library(dplyr)
library(lubridate)
library(dygraphs)
library(htmltools)
library(purrr)
library(rlang)

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

ts <- as_date(ymd_hm(climate$Date))
rownames(climate) <- ts

dy1 <- as.data.frame(climate %>% select(-Date))
rownames(dy1) <- ts

ts_plot <- function(title, label, hue)
  dygraph(dy1 %>% select(any_of(title)), main = label, group = "coup") %>%
  dyRangeSelector(dateWindow = range(ts)) %>%
  dyOptions(colors = hue) %>%
  dyAxis("x", drawGrid = FALSE)

dy_graphs <-
  fields %>% slice(-1) %>%
  bind_cols(color = RColorBrewer::brewer.pal(5, "Set2")) %>%
  purrr::pmap(~ ts_plot(..1, ..2, ..3))

swap_ext <- function(fn, from = "xls", to = "html")
  gsub(
    pattern = paste0("(.*?)\\.", from, "$"),
    replacement = paste0("\\1\\.", to),
    x = fn
)

save_html(
  browsable(tagList(dy_graphs)),
  file = "index.html"
)

