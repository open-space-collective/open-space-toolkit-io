#!/bin/bash

# Apache License 2.0

PYTHON_MAJOR_VERSION="3"
PYTHON_MINOR_VERSION="11"
PYTHON_VERSION="${PYTHON_MAJOR_VERSION}.${PYTHON_MINOR_VERSION}"

project_directory="$(git rev-parse --show-toplevel)"
python_directory="${project_directory}/build/bindings/python/OpenSpaceToolkitIOPy-python-package-${PYTHON_VERSION}"

pushd "${python_directory}" > /dev/null

python${PYTHON_VERSION} -m pip install . --force-reinstall

popd > /dev/null

for link in ${links}

do

    dep=$(basename ${link})

    package=$(echo "${dep}" | tr '-' '_' | sed 's/\/$//')

    python${PYTHON_VERSION} -m pip install /usr/local/share/${package}-*-py${PYTHON_MAJOR_VERSION}${PYTHON_MINOR_VERSION}-*.whl --force-reinstall;

done
