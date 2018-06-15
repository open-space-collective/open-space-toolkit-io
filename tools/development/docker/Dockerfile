################################################################################################################################################################

# @project        Library/IO
# @file           tools/development/docker/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        TBD

################################################################################################################################################################

FROM openspacecollective/library-core:latest

LABEL maintainer="lucas@loftorbital.com"

# Arguments

ARG version
ARG cpu_count=1

# Dependencies

## Library :: Core [master]

RUN pushd /tmp > /dev/null \
    && git clone https://github.com/open-space-collective/library-core.git \
    && cd library-core \
    && mkdir build \
    && cd build \
    && cmake -DBUILD_UNIT_TESTS=OFF .. \
    && make -j ${cpu_count} \
    && make install \
    && rm -rf /tmp/library-core \
    && popd > /dev/null

# Labels

ENV version ${version}

LABEL version="${version}"

# Execution

CMD ["/bin/bash"]

################################################################################################################################################################