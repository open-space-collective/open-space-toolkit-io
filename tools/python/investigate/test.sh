#!/bin/bash

pip install LibraryCorePy
pip install LibraryIOPy

# ldd /opt/conda/lib/python3.6/site-packages/Library/IO/LibraryIOPy.so

# /usr/lib/x86_64-linux-gnu/libssl.so.1.1

declare -a arr=(
    '/opt/conda/lib/libssl.a'
    '/opt/conda/lib/pkgconfig/libssl.pc'
    '/opt/conda/lib/libssl.so.1.0.0'
    '/opt/conda/lib/libssl.so'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libssl.a'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/pkgconfig/libssl.pc'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libssl.so.1.0.0'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libssl.so'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libssl.a'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/pkgconfig/libssl.pc'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libssl.so.1.0.0'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libssl.so'
    '/opt/conda/lib/pkgconfig/libcrypto.pc'
    '/opt/conda/lib/libcrypto.a'
    '/opt/conda/lib/libcrypto.so.1.0.0'
    '/opt/conda/lib/libcrypto.so'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/pkgconfig/libcrypto.pc'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libcrypto.a'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libcrypto.so.1.0.0'
    '/opt/conda/pkgs/openssl-1.0.2o-0/lib/libcrypto.so'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/pkgconfig/libcrypto.pc'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libcrypto.a'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libcrypto.so.1.0.0'
    '/opt/conda/pkgs/openssl-1.0.2o-h470a237_1/lib/libcrypto.so'
    '/opt/conda/lib/pkgconfig/libcurl.pc'
    '/opt/conda/lib/libcurl.la'
    '/opt/conda/lib/libcurl.so.4'
    '/opt/conda/lib/libcurl.so.4.5.0'
    '/opt/conda/lib/libcurl.a'
    '/opt/conda/lib/libcurl.so'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/libcurl.la'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/pkgconfig/libcurl.pc'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/libcurl.so.4'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/libcurl.so.4.5.0'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/libcurl.a'
    '/opt/conda/pkgs/libcurl-7.61.0-h1ad7b7a_0/lib/libcurl.so'
    '/opt/conda/conda-meta/libcurl-7.61.0-h1ad7b7a_0.json'
)

# for i in "${arr[@]}"
# do

#     if [[ -h ${i} ]]; then

#         mv ${i}{,_}

#     elif [[ -f ${i} ]]; then

#         mv ${i}{,_}

#     fi

# done

apt-get update
apt-get install -y libcurl4

# conda update -y libcurl
# conda remove -y libcurl

# path="/usr/lib/x86_64-linux-gnu"

# export PATH="${path}:${PATH}"
# export LD_LIBRARY_PATH="${path}"
# export PYTHONPATH="${path}"
# export CONDA_ENVS_PATH="${path}"

# echo ${PATH}
# echo ${LD_LIBRARY_PATH}
# echo ${PYTHONPATH}
# echo ${CONDA_ENVS_PATH}

# ln -s /usr/lib/x86_64-linux-gnu/libssl.so.1.1 /usr/lib/x86_64-linux-gnu/libssl.so
# ln -s /usr/lib/x86_64-linux-gnu/libcurl.so.4 /usr/lib/x86_64-linux-gnu/libcurl.so

ln -s /usr/lib/x86_64-linux-gnu/libcurl.so.4 /opt/conda/lib/python3.6/site-packages/Library/IO/
ln -s /usr/lib/x86_64-linux-gnu/libssl.so.1.1 /opt/conda/lib/python3.6/site-packages/Library/IO/
ln -s /usr/lib/x86_64-linux-gnu/libcrypto.so.1.1 /opt/conda/lib/python3.6/site-packages/Library/IO/

python test.py