FROM debian AS builder

RUN apt-get update -y && apt-get install -y \
	build-essential \
	git

RUN git clone --depth=1 https://github.com/Cheedoong/xml2json.git

RUN cd xml2json && make && cp xml2json /usr/local/bin

FROM debian

COPY --from=builder /usr/local/bin/xml2json /usr/local/bin



