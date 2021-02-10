#! make

PWD:=$(shell pwd)

all: build xml-to-json

build:
	docker build --load -t xml-to-json .

xml-to-json:
	# convert XML to JSON and pipe results on stdout to xml-to-json-instance.json
	@echo off
	docker run --rm -v $(PWD)/..:/tmp/ -it xml-to-json /tmp/Year2D_Multi_00541.xml > xml-to-json-instance.json

clean:
	rm -f xml-to-json-instance.json
