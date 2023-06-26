#!/bin/bash

# Apache License 2.0

PYTHON_VERSION="3.11"

project_directory="$(git rev-parse --show-toplevel)"
python_directory="${project_directory}/build/bindings/python/OpenSpaceToolkitIOPy-python-package-${PYTHON_VERSION}"

pushd "${python_directory}" > /dev/null

python${PYTHON_VERSION} -m pip install . --force-reinstall

popd > /dev/null

for link in ${links}

do

    dep=$(basename ${link} | tr '-' '_' | sed 's/\/$//')

    py_version=$(echo "${PYTHON_VERSION}" | sed 's/\.//')

    python${PYTHON_VERSION} -m pip install /usr/local/share/${dep}-*-py${py_version}-*.whl --force-reinstall;

done
