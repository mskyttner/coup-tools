#! make

PWD:=$(shell pwd)

build:
	docker build --load -t xml2json .

convert:
	# convert XML to JSON 
	docker run --rm -v $(PWD)/..:/tmp/ -it xml2json xml2json /tmp/Year2D_Multi_00541.xml > xml2json-instance.json

clean:
	rm -f xml2json-instance.json
