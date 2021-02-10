#! make

PWD:=$(shell pwd)
UID:=$(shell id -u)
GID:=$(shell id -g)

build:
	docker build --load -t quicktype .

infer-schema:
	docker run --rm -u $(UID):$(GID) -v $(PWD)/..:/tmp/ quicktype --lang schema -o /tmp/schema.json /tmp/Year2D_Multi_00541.json

gen-code:
	docker run --rm -u $(UID):$(GID) -v $(PWD)/..:/tmp/ quicktype --src /tmp/schema.json --src-lang schema --lang c++ --boost --source-style single-source --namespace coup --out /tmp/coup.hpp
	docker run --rm -u $(UID):$(GID) -v $(PWD)/..:/tmp/ quicktype --src /tmp/schema.json --lang rust --out /tmp/coup.rs

