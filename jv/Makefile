#! make

PWD:=$(shell pwd)

build:
	docker build --load -t jv .

validate:
	# validate schema.json
	docker run -v $(PWD)/..:/tmp:ro --rm -it jv /tmp/schema.json
	# validate instance
	docker run -v $(PWD)/..:/tmp:ro --rm -it jv /tmp/schema.json /tmp/Year2D_Multi_00541.json

