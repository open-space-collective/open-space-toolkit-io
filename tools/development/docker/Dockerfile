################################################################################################################################################################

# @project        Library/IO
# @file           tools/development/docker/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        TBD

################################################################################################################################################################

FROM openspacecollective/library-core:0.1.7

LABEL maintainer="lucas@loftorbital.com"

# Arguments

ARG cpu_count=1

# Dependencies

## Library ▸ Core [0.1.17]

RUN mkdir -p /tmp/library-core \
 && pushd /tmp/library-core > /dev/null \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.1.17/library-core-0.1.17-1.x86_64-runtime.rpm \
 && wget --quiet https://github.com/open-space-collective/library-core/releases/download/0.1.17/library-core-0.1.17-1.x86_64-devel.rpm \
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