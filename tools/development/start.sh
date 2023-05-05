#!/bin/bash

################################################################################################################################################################

# @project        Open Space Toolkit ▸ Astrodynamics
# @file           tools/development/start.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

# Check input arguments

if [[ -z ${project_directory} ]]; then
    echo "Variable [project_directory] is undefined."
    exit 1
fi

if [[ -z ${docker_development_image_repository} ]]; then
    echo "Variable [docker_development_image_repository] is undefined."
    exit 1
fi

if [[ -z ${docker_image_version} ]]; then
    echo "Variable [docker_image_version] is undefined."
    exit 1
fi

project_directory=$(git rev-parse --show-toplevel)

open_space_toolkit_core_directory="${project_directory}/../open-space-toolkit-core"

# Initialize variables

options=()
command=""

# Setup linked mode

if [[ ! -z ${1} ]] && [[ ${1} == "--link" ]]; then

    for link in "${@:2}"

    do

        # Extract last part of the path

        dep=${link##*/}

        # Log the linking step

        echo "Linking with ${dep} at ${link}..."

        # Open Space Toolkit ▸ Core

        if [[ ${dep} == "open-space-toolkit-core" ]]; then

            options+=( "-v" )
            options+=( "${link}:/mnt/open-space-toolkit-core:ro" )

            command="${command} \
            rm -rf /usr/local/include/OpenSpaceToolkit/Core; \
            rm -f /usr/local/lib/libopen-space-toolkit-core.so*; \
            cp -as /mnt/open-space-toolkit-core/include/OpenSpaceToolkit/Core /usr/local/include/OpenSpaceToolkit/Core; \
            cp -as /mnt/open-space-toolkit-core/src/OpenSpaceToolkit/Core/* /usr/local/include/OpenSpaceToolkit/Core/; \
            ln -s /mnt/open-space-toolkit-core/lib/libopen-space-toolkit-core.so /usr/local/lib/; \
            ln -s /mnt/open-space-toolkit-core/lib/libopen-space-toolkit-core.so.0 /usr/local/lib/; \
            cp -as /mnt/open-space-toolkit-core/build/bindings/python/dist/* /usr/local/share;"

        fi

    done

    command="${command} /bin/bash"

fi

# Run Docker container

docker run \
    -it \
    --rm \
    --privileged \
    "${options[@]}" \
    --volume="${project_directory}:/app:delegated" \
    --volume="${project_directory}/tools/development/helpers:/app/build/helpers:ro,delegated" \
    --workdir="/app/build" \
    ${docker_development_image_repository}:${docker_image_version} \
    /bin/bash -c "${command}"

################################################################################################################################################################
