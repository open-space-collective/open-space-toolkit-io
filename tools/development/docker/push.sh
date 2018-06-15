#!/bin/bash

################################################################################################################################################################

# @project        Library/IO
# @file           tools/development/docker/push.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        TBD

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

source "${script_directory}/../../.env"

docker push ${image_name}

################################################################################################################################################################