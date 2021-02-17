FROM haskell:8

RUN apt-get update -y && apt-get install -y \
	libcurl4-openssl-dev \
	libexpat-dev

RUN cabal update && \
	cabal install xml-to-json

FROM debian:buster

# copy binary from previous step
COPY --from=0 /root/.cabal/bin/xml-to-json /usr/local/bin/xml-to-json 

# add system libs
RUN apt-get update -y && apt-get install -y \
	libcurl4-openssl-dev \
	libexpat-dev

ENTRYPOINT ["xml-to-json"]

