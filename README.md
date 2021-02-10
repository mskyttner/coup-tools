# coup

A couple of tools to convert XML to JSON on the command line:

- xml2json (C++) can convert XML to JSON, it provides a dockerized CLI command based on https://github.com/Cheedoong/xml2json
- xml-to-json (Haskell) can also convert XML to JSON, it provides a dockerized CLI command based on https://github.com/sinelaw/xml-to-json#installation
- quicktype (various langs) can generate JSON Schema and code, it provides a dockerized CLI command based on https://github.com/quicktype/quicktype
- jv (Go) contains a JSON Schema validation tool through a dockerized CLI command based on https://github.com/ory/jsonschema

## Installation

Use the Makefiles to build and install the tools.

		make build

To build these CLI tools, docker is required.

## Usage

Example usage is shown in the Makefile, the "test" target can be then be executed like this:

		make test

This target uses an .xml file (Year2D_Multi_00541.xml) and converts it to JSON, generates a JSON Schema, generates some C++ and Rust code for reading/writing the format in the schema, validates the JSON against the schema and finally uses R to convert the JSON into an .xlsx file by extracting some tabular data from this data structure, which can then be viewed in spreadsheet format.

Using these CLI tools, XML can be converted to JSON with a JSON Schema which allows automatic code generation for generating files that can be used embedded in a parser implemented in a specific format (C++, Rust, Go etc).

- An XML file can be converted to JSON. (use xml2json or xml-to-json)

- From this JSON file a JSON Schema can be inferred (iteratively). (use quicktype) 

- The JSON file can be validated against the JSON Schema. (use jv)

- A C++ (or Rust or Go etc) file (for read and write files in a JSON format complying with the schema) can be generated. (use quicktype)

## Thoughts

The highly nested format in the XML-file can be flattened.

See the json2xlsx.R file.


