#!/bin/bash

################################################################################################################################################################

# @project        Library/IO
# @file           tools/python/debug.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        TBD

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd "${script_directory}" > /dev/null

source ../.env

if [[ ! -z $1 ]] && [[ $1 == "--link" ]]; then

    docker run \
    --name="${container_name}-python-debug" \
    -it \
    --rm \
    --privileged \
    --user="" \
    --env="LD_LIBRARY_PATH=/usr/local/lib:/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --env="PYTHONPATH=/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --volume="${project_directory}/../library-core/lib:/opt/library-core:ro" \
    --volume="${project_directory}/lib:/opt/lib:ro" \
    --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/notebooks" \
    --volume="${script_directory}/helpers:/home/jovyan/notebooks/helpers:ro" \
    --volume="${project_directory}/share:/var/library-io" \
    --workdir="/home/jovyan/notebooks" \
    "${repository_name}/${project_name}-python-debug" \
    bash -c "mkdir -p /opt/conda/lib/python3.6/site-packages/Library/Core \
    && ln -s /opt/library-core/liblibrary-core.so.0 /opt/conda/lib/python3.6/site-packages/Library/Core/liblibrary-core.so.0 \
    && ln -s /opt/library-core/LibraryCorePy.so /opt/conda/lib/python3.6/site-packages/Library/Core/LibraryCorePy.so \
    && echo 'from .LibraryCorePy import *' > /opt/conda/lib/python3.6/site-packages/Library/Core/__init__.py \
    && mkdir -p /opt/conda/lib/python3.6/site-packages/Library/IO \
    && ln -s /opt/lib/liblibrary-io.so.0 /opt/conda/lib/python3.6/site-packages/Library/IO/liblibrary-io.so.0 \
    && ln -s /opt/lib/LibraryIOPy.so /opt/conda/lib/python3.6/site-packages/Library/IO/LibraryIOPy.so \
    && echo 'from .LibraryIOPy import *' > /opt/conda/lib/python3.6/site-packages/Library/IO/__init__.py \
    && /bin/bash"

else

    docker run \
    --name="${container_name}-python-debug" \
    -it \
    --rm \
    --privileged \
    --user="" \
    --env="LD_LIBRARY_PATH=/usr/local/lib:/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --env="PYTHONPATH=/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --volume="${project_directory}/lib:/opt/lib:ro" \
    --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/notebooks" \
    --volume="${script_directory}/helpers:/home/jovyan/notebooks/helpers:ro" \
    --volume="${project_directory}/share:/var/library-io" \
    --workdir="/home/jovyan/notebooks" \
    "${repository_name}/${project_name}-python-debug" \
    bash -c "mkdir -p /opt/conda/lib/python3.6/site-packages/Library/IO \
    && ln -s /opt/lib/liblibrary-io.so.0 /opt/conda/lib/python3.6/site-packages/Library/IO/liblibrary-io.so.0 \
    && ln -s /opt/lib/LibraryIOPy.so /opt/conda/lib/python3.6/site-packages/Library/IO/LibraryIOPy.so \
    && echo 'from .LibraryIOPy import *' > /opt/conda/lib/python3.6/site-packages/Library/IO/__init__.py \
    && /bin/bash"

fi

popd > /dev/null

################################################################################################################################################################