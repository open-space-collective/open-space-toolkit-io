################################################################################################################################################################

# @project        Library/IO
# @file           tools/python/docker/Dockerfile
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

FROM jupyter/scipy-notebook:latest

LABEL maintainer="lucas@loftorbital.com"

USER root

RUN ln -s /opt/conda/include/python3.6m /opt/conda/include/python3.6

RUN cd /tmp \
 && wget --quiet http://sourceforge.net/projects/boost/files/boost/1.68.0/boost_1_68_0.tar.gz \
 && tar -xf boost_1_68_0.tar.gz \
 && cd boost_1_68_0 \
 && ./bootstrap.sh --with-python=/opt/conda/bin/python3 --with-python-version=3.6 --with-python-root=/opt/conda/lib/python3.6 \
 && echo "using python : 3.6 : /usr : /opt/conda/include/python3.6m ;" >> project-config.jam \
 && ./b2 --with-python -j 8 install \
 && rm -rf /tmp/boost_1_68_0

RUN jupyter labextension install @jupyterlab/plotly-extension

COPY ./shortcuts-extension /home/jovyan/.jupyter/lab/user-settings/@jupyterlab/shortcuts-extension

RUN chown -R $NB_UID:$NB_UID /home/jovyan/.jupyter

####

# Environment

ENV LD_LIBRARY_PATH /usr/local/lib:${LD_LIBRARY_PATH}
ENV PYTHONPATH /usr/local/lib:${PYTHONPATH}

RUN apt-get update -y

# Development Tools

## Compilers

RUN apt-get install -y cmake python3-dev python3-numpy

## Python Tools

RUN python3 -m pip install --user --upgrade setuptools wheel twine

## GoogleTest [1.8.1]

RUN cd /tmp > /dev/null \
 && git clone --branch release-1.8.1 --depth 1 https://github.com/google/googletest.git \
 && cd googletest \
 && mkdir build \
 && cd build \
 && cmake .. \
 && make -j $(nproc) \
 && make install \
 && rm -rf /tmp/googletest

## Boost [1.68.0]

RUN cd /tmp > /dev/null \
 && wget --quiet http://sourceforge.net/projects/boost/files/boost/1.68.0/boost_1_68_0.tar.gz \
 && tar -xf boost_1_68_0.tar.gz \
 && cd boost_1_68_0 \
 && ./bootstrap.sh --with-python=/usr/bin/python3 --with-python-version=3.6 --with-python-root=/usr/lib/python3.6 \
 && echo "using python : 3.6 : /usr : /usr/include/python3.6m ;" >> project-config.jam \
 && ./b2 -j $(nproc) link=static cxxflags=-fPIC install \
 && ./b2 -j $(nproc) --with-python link=shared cxxflags=-fPIC install \
 && rm -rf /tmp/boost_1_68_0 /tmp/boost_1_68_0.tar.gz

## RapidJSON [1.1.0]

RUN cd /tmp > /dev/null \
 && git clone https://github.com/miloyip/rapidjson.git \
 && cd rapidjson \
 && mkdir build \
 && cd build \
 && cmake .. \
 && make --silent -j $(nproc) \
 && make install \
 && rm -rf /tmp/rapidjson

## ordered-map [0.6.0]

RUN cd /tmp > /dev/null \
 && git clone --branch v0.6.0 --depth 1 https://github.com/Tessil/ordered-map.git \
 && cd ordered-map \
 && cp -r ./include/tsl /usr/local/include \
 && rm -rf /tmp/ordered-map

## {fmt} [5.2.0]

RUN cd /tmp > /dev/null \
 && git clone --branch 5.2.0 --depth 1 https://github.com/fmtlib/fmt.git \
 && cd fmt \
 && mkdir build \
 && cd build \
 && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE .. \
 && make --silent -j $(nproc) \
 && make install \
 && rm -rf /tmp/fmt

## Rapidcsv [master]

RUN cd /tmp > /dev/null \
 && git clone https://github.com/d99kris/rapidcsv.git \
 && cd rapidcsv \
 && mkdir -p /usr/local/include/rapidcsv \
 && cp src/*.h /usr/local/include/rapidcsv/ \
 && rm -rf /tmp/rapidcsv

RUN cd /tmp > /dev/null \
 && git clone --branch 0.13-release --depth 1 https://github.com/cpp-netlib/cpp-netlib \
 && cd cpp-netlib \
 && git submodule init \
 && git submodule update \
 && mkdir build \
 && cd build \
 && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. \
 && make -j $(nproc) \
 && make install \
 && rm -rf /tmp/cppnetlib

## Library ▸ Core [0.1.19]

RUN mkdir -p /tmp/library-core \
 && cd /tmp > /dev/null \
 && git clone https://github.com/open-space-collective/library-core.git \
 && cd library-core \
 && mkdir build \
 && cd build \
 && cmake -DBUILD_PYTHON_BINDINGS=OFF .. \
 && make -j $(nproc) \
 && make install

RUN apt-get install -y libcurl4-openssl-dev

# RUN ln -s /usr/lib/x86_64-linux-gnu/libssl.so.1.1 /usr/lib/libssl.so
# RUN ln -s /usr/lib/x86_64-linux-gnu/libcrypto.so.1.1 /usr/lib/libcrypto.so

RUN ln -s /opt/conda/lib/libssl.so /usr/lib/libssl.so
RUN ln -s /opt/conda/lib/libcrypto.so /usr/lib/libcrypto.so

RUN mkdir -p /tmp/library-io \
 && cd /tmp > /dev/null \
 && git clone https://github.com/open-space-collective/library-io.git \
 && cd library-io \
 && mkdir build \
 && cd build \
 && cmake -DBUILD_PYTHON_BINDINGS=OFF .. \
 && make -j $(nproc) \
 && make install

RUN chown -R $NB_UID:$NB_UID /home/jovyan/.local

# USER $NB_UID

################################################################################################################################################################