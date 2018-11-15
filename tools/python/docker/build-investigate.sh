#!/bin/bash

################################################################################################################################################################

# @project        Library/IO
# @file           tools/python/docker/build-investigate.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd ${script_directory} > /dev/null

source "../../.env"

docker build \
--tag="${repository_name}/${project_name}-python-investigate" \
--file="Dockerfile.investigate" \
.

popd > /dev/null

################################################################################################################################################################