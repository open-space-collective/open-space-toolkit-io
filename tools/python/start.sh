#!/bin/bash

################################################################################################################################################################

# @project        Library/IO
# @file           tools/python/start.sh
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

pushd "${script_directory}" > /dev/null

source ../.env

# Build Docker image if it does not exist already

if [[ "$(docker images -q ${image_name}-python:${image_version} 2> /dev/null)" == "" ]]; then

    pushd "${script_directory}/docker" > /dev/null

    ./build.sh

    popd

fi

if [[ ! -z $1 ]] && [[ $1 == "--link" ]]; then

    docker run \
    --name="${container_name}-notebook" \
    -it \
    --rm \
    --publish="${python_port}:8888" \
    --user="" \
    --env="GRANT_SUDO=yes" \
    --env="JUPYTER_ENABLE_LAB=yes" \
    --env="LD_LIBRARY_PATH=/usr/local/lib:/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --env="PYTHONPATH=/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --volume="${library_core_directory}/lib:/opt/library-core:ro" \
    --volume="${project_directory}/lib:/opt/lib:ro" \
    --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/tutorials" \
    --volume="${project_directory}/share:/var/library-io" \
    --workdir="/home/jovyan" \
    "${image_name}-python:${image_version}" \
    bash -c "mkdir -p /opt/conda/lib/python3.6/site-packages/Library/Core \
    && ln -s /opt/library-core/liblibrary-core.so.0 /opt/conda/lib/python3.6/site-packages/Library/Core/liblibrary-core.so.0 \
    && ln -s /opt/library-core/LibraryCorePy.so /opt/conda/lib/python3.6/site-packages/Library/Core/LibraryCorePy.so \
    && echo 'from .LibraryCorePy import *' > /opt/conda/lib/python3.6/site-packages/Library/Core/__init__.py \
    && mkdir -p /opt/conda/lib/python3.6/site-packages/Library/IO \
    && ln -s /opt/lib/liblibrary-io.so.0 /opt/conda/lib/python3.6/site-packages/Library/IO/liblibrary-io.so.0 \
    && ln -s /opt/lib/LibraryIOPy.so /opt/conda/lib/python3.6/site-packages/Library/IO/LibraryIOPy.so \
    && echo 'from .LibraryIOPy import *' > /opt/conda/lib/python3.6/site-packages/Library/IO/__init__.py \
    && start-notebook.sh --NotebookApp.token=''"

else

    # docker run \
    # --name="${container_name}-notebook" \
    # -it \
    # --rm \
    # --publish="${python_port}:8888" \
    # --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    # --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/tutorials" \
    # --volume="${project_directory}/share:/var/library-io" \
    # --workdir="/home/jovyan" \
    # "jupyter/base-notebook:latest" \
    # /bin/bash

    # docker run \
    # --name="${container_name}-notebook" \
    # -it \
    # --rm \
    # --publish="${python_port}:8888" \
    # --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    # --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/tutorials" \
    # --volume="${project_directory}/share:/var/library-io" \
    # --workdir="/home/jovyan" \
    # "${image_name}-python:${image_version}" \
    # /bin/bash

    docker run \
    --name="${container_name}-notebook" \
    -it \
    --rm \
    --publish="${python_port}:8888" \
    --user="" \
    --env="GRANT_SUDO=yes" \
    --env="JUPYTER_ENABLE_LAB=yes" \
    --env="LD_LIBRARY_PATH=/usr/local/lib:/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --env="PYTHONPATH=/opt/conda/lib/python3.6/site-packages:/home/jovyan/lib" \
    --volume="${library_core_directory}/lib:/opt/library-core:ro" \
    --volume="${project_directory}/lib:/opt/lib:ro" \
    --volume="${project_directory}/bindings/python/docs:/home/jovyan/docs" \
    --volume="${project_directory}/tutorials/python/notebooks:/home/jovyan/tutorials" \
    --volume="${project_directory}/share:/var/library-io" \
    --workdir="/home/jovyan" \
    "${image_name}-python:${image_version}" \
    bash -c "mkdir -p /opt/conda/lib/python3.6/site-packages/Library/IO \
    && ln -s /opt/lib/liblibrary-io.so.0 /opt/conda/lib/python3.6/site-packages/Library/IO/liblibrary-io.so.0 \
    && ln -s /opt/lib/LibraryIOPy.so /opt/conda/lib/python3.6/site-packages/Library/IO/LibraryIOPy.so \
    && echo 'from .LibraryIOPy import *' > /opt/conda/lib/python3.6/site-packages/Library/IO/__init__.py \
    && start-notebook.sh --NotebookApp.token=''"
    # && /bin/bash"

fi

popd > /dev/null

################################################################################################################################################################