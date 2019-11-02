################################################################################################################################################################

# @project        Library ▸ I/O
# @file           docker/development/debian/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

ARG BASE_IMAGE_VERSION=latest
ARG BASE_IMAGE_SYSTEM=debian

FROM openspacecollective/library-base:${BASE_IMAGE_VERSION}-${BASE_IMAGE_SYSTEM} as development-base

LABEL maintainer="lucas@loftorbital.com"

# Dependencies

## {fmt} [5.2.0]

RUN cd /tmp \
 && git clone --branch 5.2.0 --depth 1 https://github.com/fmtlib/fmt.git \
 && cd fmt \
 && mkdir build \
 && cd build \
 && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE .. \
 && make --silent -j $(nproc) \
 && make install \
 && rm -rf /tmp/fmt

## libcurl

RUN apt-get update -y \
 && apt-get install -y libcurl4-openssl-dev libssl-dev \
 && rm -rf /var/lib/apt/lists/*

## C++ Network Library [0.13.0]

# RUN cd /tmp \
#  && dnf update -y \
#  && dnf install -y openssl-static \
#  && dnf clean all \
#  && git clone --branch 0.13-release --depth 1 https://github.com/cpp-netlib/cpp-netlib \
#  && cd cpp-netlib \
#  && git submodule init \
#  && git submodule update \
#  && mkdir build \
#  && cd build \
#  && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. \
#  && make -j $(nproc) \
#  && make install \
#  && rm -rf /tmp/cppnetlib

RUN cd /tmp \
 && git clone --branch 0.13-release --depth 1 https://github.com/cpp-netlib/cpp-netlib \
 && cd cpp-netlib \
 && git submodule init \
 && git submodule update \
 && mkdir build \
 && cd build \
 && cmake -DCPP-NETLIB_STATIC_BOOST=ON -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. \
 && make -j $(nproc) \
 && make install \
 && rm -rf /tmp/cppnetlib

## Library ▸ Core [0.2.5]

RUN mkdir -p /tmp/library-core \
 && cd /tmp/library-core \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.2.5/library-core-0.2.5-1.x86_64-runtime.deb \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.2.5/library-core-0.2.5-1.x86_64-devel.deb \
 && apt install -y ./*.deb \
 && rm -rf /tmp/library-core

# Labels

ARG VERSION

ENV VERSION ${VERSION}

LABEL VERSION="${VERSION}"

# Execution

CMD ["/bin/bash"]

################################################################################################################################################################
