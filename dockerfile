FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install build-essential -y
RUN apt-get install git -y
RUN apt-get install make -y
RUN apt-get install binutils-arm-none-elf -y

COPY . /

RUN make clean
RUN make submodules
RUN make all

# -------

# FROM alpine:3.20.1

# RUN apk add gcc-aarch64-none-elf
# RUN apk add git
# RUN apk add make

# COPY . /

# RUN make clean
# RUN make submodules
# RUN make all
