#! make

build:
	docker build --load -t msimcoup .

test:
	# no msimcoup --help available, so just showing the file for now
	docker run --rm --entrypoint "" msimcoup ls -lahtr /usr/local/bin


