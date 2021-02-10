#!/usr/bin/env Rscript
library(duckdb)
library(dplyr)
library(data.tree)
library(jsonify)

args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
  stop("Please provide a valid parquet file path as input")
}

if (length(args) == 1) {
  file <- normalizePath(args[1], mustWork = TRUE)
  message("Input file is ", file)
  stopifnot(file.exists(file))
  if (!grepl("(.*?)\\.parquet$", basename(file)))
    stop("Please provide a .parquet file as input...")
}

# read parquet using duckdb; create the view and get the data

sql <- sprintf("-- create a view over the parquet file
CREATE VIEW coup AS SELECT * FROM parquet_scan('%s')", file)

con <- dbConnect(duckdb())
res <- DBI::dbExecute(con, sql)
data <- dbGetQuery(con, "SELECT * from coup;")
on.exit(dbDisconnect(con, shutdown = TRUE))

# the graph as "materialized path" tree (could be labeled)
# df1 <-
#   as_tibble(data) %>%
#   tidyr::separate(key, into = sprintf("c%02d", 1:14), fill = "right") %>%
#   count(sort = TRUE,
#     c01, c02, c03, c04, c05, c06, c07, c08, c09, c10, c11, c12, c13, c14,
#     val
#   ) %>%
#   arrange(desc(n))

message("TODO: speed up conversion from flat format (data.tree is sluggish)...")
tree <- data.tree::as.Node(
  pathDelimiter = ".",
  data %>%
    mutate(pathString = key) %>%
    select(-key)
  )

message("Converting to JSON ...")

l2 <- as.list(
  tree,
  mode = "simple",
  unname = TRUE,
  nameName = "",
  childrenName = "",
  rootName = "node",
  keepOnly = NULL,
  pruneFun = NULL
)

j2 <- jsonify::to_json(l2)
message("Done.")
write(jsonify::pretty_json(j2), file = stdout())
