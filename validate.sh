#!/bin/bash

set -e

docker run -v $(pwd):/tmp:ro --rm -it \
	jv /tmp/schema.json /tmp/$1

echo $?

