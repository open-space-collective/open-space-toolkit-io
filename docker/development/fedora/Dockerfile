################################################################################################################################################################

# @project        Open Space Toolkit ▸ I/O
# @file           docker/development/fedora/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

ARG BASE_IMAGE_VERSION="latest"

FROM openspacecollective/open-space-toolkit-base:${BASE_IMAGE_VERSION}-fedora

LABEL maintainer="lucas@loftorbital.com"

# Dependencies

## {fmt}

ARG FMT_VERSION="5.2.0"

RUN cd /tmp \
 && git clone --branch ${FMT_VERSION} --depth 1 https://github.com/fmtlib/fmt.git \
 && cd fmt \
 && mkdir build \
 && cd build \
 && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE .. \
 && make --silent -j $(nproc) \
 && make install \
 && rm -rf /tmp/fmt

## libcurl

RUN dnf update -y \
 && dnf install -y libcurl-devel openssl-devel \
 && dnf clean all

## Open Space Toolkit ▸ Core

ARG OSTK_CORE_VERSION="0.4.7"

RUN mkdir -p /tmp/open-space-toolkit-core \
 && cd /tmp/open-space-toolkit-core \
 && wget --quiet https://github.com/open-space-collective/open-space-toolkit-core/releases/download/${OSTK_CORE_VERSION}/open-space-toolkit-core-${OSTK_CORE_VERSION}-1.x86_64-runtime.rpm \
 && wget --quiet https://github.com/open-space-collective/open-space-toolkit-core/releases/download/${OSTK_CORE_VERSION}/open-space-toolkit-core-${OSTK_CORE_VERSION}-1.x86_64-devel.rpm \
 && dnf install -y ./*.rpm \
 && rm -rf /tmp/open-space-toolkit-core

# Labels

ARG VERSION
ENV VERSION="${VERSION}"
LABEL VERSION="${VERSION}"

# Execution

CMD ["/bin/bash"]

################################################################################################################################################################
