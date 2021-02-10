FROM haskell:8
RUN apt-get update -y && apt-get install -y \
	libcurl4-openssl-dev \
	libexpat-dev

#RUN stack install xml-to-json

RUN cabal update && cabal install xml-to-json
ENTRYPOINT ["xml-to-json"]
