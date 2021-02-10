#! make

PWD=$(shell pwd)

build:
	make -C xml2json build
	make -C xml-to-json build
	make -C jv build
	make -C quicktype build

test:
	# two conversions from xml to json
	make -C xml2json convert
	mv xml2json/xml2json-instance.json Year2D_Multi_00541.json
	make -C xml-to-json xml-to-json
	mv xml-to-json/xml-to-json-instance.json Year2D_Multi_00541.json
	# generate JSON Schema and code (C++ and Rust)
	make -C quicktype infer-schema gen-code

	# validate JSON against JSON Schema
	make -C jv validate
	# convert to xlsx
	./json2xlsx.R Year2D_Multi_00541.json
	# convert to csv and parquet
	./json2flat.R Year2D_Multi_00541.json
	# convert back to json
	./flat2json.R Year2D_Multi_00541.parquet > roundtrip.json

validate:
	# display validation errors from roundtrip
	bash -c "./validate.sh roundtrip.json > roundtrip-validation.txt" && echo "success!" || \
		{ echo "failed validation! see roundtrip-validation.txt for results"; exit 0; }

clean:
	rm -f coup.hpp coup.rs schema.json Year2D_Multi_00541.xlsx Year2D_Multi_00541.json roundtrip.json Year2D_Multi_00541.csv Year2D_Multi_00541.parquet roundtrip-validation.txt
