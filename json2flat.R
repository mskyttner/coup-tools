#!/usr/bin/env Rscript

library(ndjson, quietly = TRUE)
library(arrow)
library(dplyr)

args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
	stop("Please provide a valid input file in JSON format")
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

rename_ext <- function(fn, from = "json", to = "parquet") {

  swap_ext <- function(fn, from, to)
    gsub(
      pattern = paste0("(.*?)\\.", from, "$"),
      replacement = paste0("\\1\\.", to),
      x = fn
    )
  outfile <- file.path(normalizePath(dirname(file)),
    swap_ext(basename(file), from, to))

  return(outfile)
}

kv <-
  tibble(key = rownames(t(d1)), val = t(d1)[,1])

write_parquet_gz <- function(data, outfile) {

  if (codec_is_available("snappy")) {
    write_parquet(data, outfile, compression = "snappy", compression_level = 5)
  } else {
    message("Pls install arrow lib with compression support")
    write_parquet(data, outfile)
  }
}

write_parquet_gz(kv, rename_ext(file, to = "parquet"))
readr::write_excel_csv(kv, rename_ext(file, to = "csv"))

