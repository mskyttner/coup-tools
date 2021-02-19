FROM debian

RUN apt-get update -y && apt-get install -y \
	cmake \
	build-essential \
	libboost-dev \
	git

WORKDIR /src

RUN git clone --depth=1 https://github.com/pejtranholmen/msimcoup3.git

RUN cd msimcoup3 && cmake . && cmake -G "Unix Makefiles" . && make

FROM debian

# multistage build, just get the binary from the previous step
COPY --from=0 /src/msimcoup3/msimcoup /usr/local/bin/msimcoup

ENTRYPOINT ["msimcoup"]


