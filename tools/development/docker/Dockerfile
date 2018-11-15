################################################################################################################################################################

# @project        Library/IO
# @file           tools/development/docker/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

FROM openspacecollective/library-core:0.1.7

LABEL maintainer="lucas@loftorbital.com"

# Arguments

ARG cpu_count=1

# Dependencies

## libcurl

RUN dnf update -y \
 && dnf install -y libcurl-devel openssl-devel \
 && dnf clean all

## C++ Network Library [0.13.0]

# RUN pushd /tmp > /dev/null \
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
#  && make -j ${cpu_count} \
#  && make install \
#  && popd > /dev/null \
#  && rm -rf /tmp/cppnetlib

RUN pushd /tmp > /dev/null \
 && git clone --branch 0.13-release --depth 1 https://github.com/cpp-netlib/cpp-netlib \
 && cd cpp-netlib \
 && git submodule init \
 && git submodule update \
 && mkdir build \
 && cd build \
 && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. \
 && make -j ${cpu_count} \
 && make install \
 && popd > /dev/null \
 && rm -rf /tmp/cppnetlib

## Library ▸ Core [0.1.19]

RUN mkdir -p /tmp/library-core \
 && pushd /tmp/library-core > /dev/null \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.1.19/library-core-0.1.19-1.x86_64-runtime.rpm \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.1.19/library-core-0.1.19-1.x86_64-devel.rpm \
 && dnf install -y ./*.rpm \
 && rm -rf /tmp/library-core \
 && popd > /dev/null

# Labels

ARG version

ENV version ${version}

LABEL version="${version}"

# Execution

CMD ["/bin/bash"]

################################################################################################################################################################