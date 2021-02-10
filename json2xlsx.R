#!/usr/bin/env Rscript

library(jsonlite)
library(ndjson, quietly = TRUE)
library(writexl, quietly = TRUE)
library(dplyr, quietly = TRUE)

args <- commandArgs(trailingOnly = TRUE)

#TODO: fix stream in and stream out
stream <- FALSE

if (length(args) == 0) {
  stream <- TRUE
  input <- file('stdin', 'r')
  on.exit(close(input))
  tf <- tempfile()
  writeLines(c(readLines(input, n = -1, warn = FALSE), "\n"), tf)
  d1 <- stream_in(tf, cls = "tbl")
}

if (length(args) == 1) {
  file <- normalizePath(args[1], mustWork = TRUE)
  message("Input file is ", file)
  stopifnot(file.exists(file))
  if (!grepl("(.*?)\\.json$", basename(file)))
    stop("Please provide a .json file as input...")
  if (!validate(file))
    stop("Invalid input, pls validate JSON first")
  d1 <- stream_in(file, cls = "tbl")
  message("Parsed JSON, building key value store...")
}

parse_coup <- function(data) {

  d1 <- data

  kv <-
    tibble(key = rownames(t(d1)), val = t(d1)[,1])

  # utility fcn to generate sequences of columns
  colgroup <- function(n = 10, prefix = "col")
    paste0(rep(prefix, n), sprintf(paste0("%0", log(n, 10) + 1, "d"), 1:n))

  message("Extracting data in order to generate xlsx file...")

  # Run Info
  sh1 <-
    kv %>% filter(grepl("Run_Info", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(4)) %>%
    select(Group = col3, Setting = col4, Value = val)

  # Switches appear to come from Model_Options?
  # for example
  sh2 <-
    kv %>% filter(grepl("Model_Options.*?", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(6)) %>%
    select(Group = col4, Name = col5, col6, val) %>%
    tidyr::pivot_wider(names_from = "col6", values_from = "val") %>%
    select(Group, Name, Current, Default, everything(), starts_with("Condition"))

  # Parameters, for example
  sh3 <-
    kv %>% filter(grepl("node\\.Parameters\\.", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(6)) %>%
    select(Group = col4, col5, col6, val) %>%
    tidyr::pivot_wider(names_from = "col6", values_from = "val") %>%
    select(Group, Name = col5, starts_with("Condition"), everything())


  # Parameter Tables, appear to come from Parameters_Arrays?
  sh4 <-
    kv %>% filter(grepl("node\\.Parameters_Arrays.*SoilHydraulic", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(6)) %>%
    select(Group = col4, col5, col6, val) %>%
    tidyr::separate(col = "col6", sep = "_", into = colgroup(3), fill = "right") %>%
    filter(is.na(col2)) %>%
    tidyr::pivot_wider(names_from = "col1", values_from = "val") %>%
    filter(ArrayName != "NoMeasuredLayers") %>%
    select(Group, Name = col5, NumberOfLayers = SizeofArray)

  # Model files appear to come from Model_Files
  sh5 <-
    kv %>% filter(grepl("Model_Files.*?PF_File", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(6)) %>%
    select(Group = col4, Option = col5, FileName = val)

  # Output Variables, for example driving variables
  sh6 <-
    kv %>% filter(grepl("Output_Variables.*?Driving\\.", key)) %>%
    tidyr::separate(col = "key", sep = "\\.", into = colgroup(7)) %>%
    select(col3, col5, col6, col7, val) %>%
    tidyr::pivot_wider(names_from = col7, values_from = val) %>%
    select(Type = col3, Group = col5, Name = col6, OutSingle, OutMulti)

  wb <- list(
    "Run Info" = sh1,
    "Switches" = sh2,
    "Parameters" = sh3,
    "Parameter Tables" = sh4,
    "Model Files" = sh5,
    "Output Variables" = sh6
  )

  return(wb)
}

wb <- parse_coup(d1)

write_coup <- function(wb, stream = FALSE) {

  swap_ext <- function(fn, from = "json", to = "xlsx")
    gsub(
      pattern = paste0("(.*?)\\.", from, "$"),
      replacement = paste0("\\1\\.", to),
      x = fn
    )

  if (!stream) {
    outfile <- file.path(normalizePath(dirname(file)), swap_ext(basename(file)))
    writexl::write_xlsx(wb, path = outfile)
  } else {
    outfile <- tempfile()
    writexl::write_xlsx(wb, path = outfile)
    write(readBin(outfile, what = "raw"), "")
  }

}

write_coup(wb, stream)
