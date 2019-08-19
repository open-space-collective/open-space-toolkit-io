#!/bin/bash

################################################################################################################################################################

# @project        Library ▸ I/O
# @file           tools/python/investigate.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd "${script_directory}" > /dev/null

source ../.env

docker run \
--name="${container_name}-investigate" \
-it \
--rm \
--user="" \
--env="GRANT_SUDO=yes" \
--publish="${python_port}:8888" \
--volume="${script_directory}/investigate:/investigate" \
--workdir="/investigate" \
"${image_name}-python-investigate:${image_version}" \
bash -c "/bin/bash"

popd > /dev/null

################################################################################################################################################################
