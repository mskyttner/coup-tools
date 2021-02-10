FROM golang AS builder
RUN go get -d github.com/ory/jsonschema
WORKDIR /go/src/github.com/ory/jsonschema
RUN go install cmd/jv/main.go && cd /go/bin && mv main jv

FROM golang  
COPY --from=builder /go/bin/jv /usr/local/bin/jv
ENTRYPOINT ["jv"]
