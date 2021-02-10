#!/usr/bin/env Rscript

library(jsonlite)
library(xml2)

args <- commandArgs(trailingOnly = TRUE)

if (length(args) >= 1)
	file <- args[1]

stopifnot(file.exists(file))

xml <- as_list(read_xml(file))

xl <- lapply(xml, attributes)

toJSON(xl, pretty = TRUE, auto_unbox = TRUE)

