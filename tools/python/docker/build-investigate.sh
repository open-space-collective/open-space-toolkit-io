#!/bin/bash

################################################################################################################################################################

# @project        Library/IO
# @file           tools/python/docker/build-investigate.sh
# @author         Lucas Brémond <lucas.bremond@gmail.com>
# @license        Apache License 2.0

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd ${script_directory} > /dev/null

source "../../.env"

docker build \
--tag="${image_name}-python-investigate:${image_version}" \
--file="Dockerfile.investigate" \
.

popd > /dev/null

################################################################################################################################################################