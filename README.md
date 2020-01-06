# Open Space Toolkit ▸ I/O

[![Build Status](https://travis-ci.com/open-space-collective/open-space-toolkit-io.svg?branch=master)](https://travis-ci.com/open-space-collective/open-space-toolkit-io)
[![Code Coverage](https://codecov.io/gh/open-space-collective/open-space-toolkit-io/branch/master/graph/badge.svg)](https://codecov.io/gh/open-space-collective/open-space-toolkit-io)
[![Documentation](https://img.shields.io/readthedocs/pip/stable.svg)](https://open-space-collective.github.io/open-space-toolkit-io)
[![GitHub version](https://badge.fury.io/gh/open-space-collective%2Fopen-space-toolkit-io.svg)](https://badge.fury.io/gh/open-space-collective%2Fopen-space-toolkit-io)
[![PyPI version](https://badge.fury.io/py/open-space-toolkit-io.svg)](https://badge.fury.io/py/open-space-toolkit-io)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

Addressing, networking, database connectors.

## Warning

*⚠ This component is under development.*

## Installation

### C++

The binary packages are hosted using [GitHub Releases](https://github.com/open-space-collective/open-space-toolkit-io/releases).

*Note: Don't forget to set the desired version number in the URLs!*

#### Debian / Ubuntu

```bash
# Download .deb packages

wget https://github.com/open-space-collective/open-space-toolkit-io/releases/download/0.3.0/open-space-toolkit-io-0.3.0-1.x86_64-runtime.deb
wget https://github.com/open-space-collective/open-space-toolkit-io/releases/download/0.3.0/open-space-toolkit-io-0.3.0-1.x86_64-devel.deb

# Install .deb packages

apt install -y open-space-toolkit-io-0.3.0-*.deb
```

#### Fedora / CentOS

```bash
# Download .rpm packages

wget https://github.com/open-space-collective/open-space-toolkit-io/releases/download/0.3.0/open-space-toolkit-io-0.3.0-1.x86_64-runtime.rpm
wget https://github.com/open-space-collective/open-space-toolkit-io/releases/download/0.3.0/open-space-toolkit-io-0.3.0-1.x86_64-devel.rpm

# Install .rpm packages

dnf install -y open-space-toolkit-io-0.3.0-*.rpm
```

### Python

The binary packages are hosted on [PyPI](https://pypi.org/project/open-space-toolkit-io/):

```bash
pip install open-space-toolkit-io
```

## Getting Started

Want to quickly get started? It's pretty simple.

Install [Docker](https://www.docker.com/) and try this:

```bash
docker run -it openspacecollective/open-space-toolkit-io-python
```

This will start an [iPython](https://ipython.org/) shell within a container where the OSTk I/O component is already installed.

Once the shell is up and running, playing with it is easy:

```py
from ostk.io import URL # URL class
from ostk.io.ip.tcp.http import Client # HTTP client class

url = URL.parse("https://www.google.com") # Construct a URL

response = Client.get(url) # Send an HTTP GET request (over HTTPS)

response.get_status_code() # Display the status code of the HTTP response
```

*Tip: Use tab for auto-completion!*

## Structure

The **IO** library exhibits the following structure:

```txt
├── IP
│   ├── Address
│   └── TCP
│       ├── Client
│       ├── Server
│       └── HTTP
│           ├── Client
│           └── Server
└── URL
```

## Documentation

Documentation is available here:

- [C++](https://open-space-collective.github.io/open-space-toolkit-io)
- [Python](./bindings/python/docs)

## Tutorials

Tutorials are available here:

- [C++](./tutorials/cpp)
- [Python](./tutorials/python)

## Setup

### Development Environment

Using [Docker](https://www.docker.com) for development is recommended, to simplify the installation of the necessary build tools and dependencies.
Instructions on how to install Docker are available [here](https://docs.docker.com/install/).

To start the development environment:

```bash
make start-development
```

This will:

1. Build the `openspacecollective/open-space-toolkit-io-development` Docker image.
2. Create a development environment container with local source files and helper scripts mounted.
3. Start a `bash` shell from the `./build` working directory.

If installing Docker is not an option, you can manually install the development tools (GCC, CMake) and all required dependencies,
by following a procedure similar to the one described in the [Development Dockerfile](./docker/development/Dockerfile).

### Build

From the `./build` directory:

```bash
cmake ..
make
```

*Tip: `helpers/build.sh` simplifies building from within the development environment.*

### Test

To start a container to build and run the tests:

```bash
make test
```

Or to run them manually:

```bash
./bin/open-space-toolkit-io.test
```

*Tip: `helpers/test.sh` simplifies running tests from within the development environment.*

## Dependencies

| Name                | Version | License                | Link                                                                                                                         |
|---------------------|---------|------------------------|------------------------------------------------------------------------------------------------------------------------------|
| Boost               | 1.69.0  | BSL-1.0                | [boost.org](https://www.boost.org)                                                                                           |
| C++ Network Library | 0.13.0  | BSL-1.0                | [cpp-netlib.org](https://cpp-netlib.org)                                                                                     |
| Pistache            | master  | Apache License 2.0     | [pistache.io](http://pistache.io)                                                                                            |
| Core                | master  | Apache License 2.0     | [github.com/open-space-collective/open-space-toolkit-core](https://github.com/open-space-collective/open-space-toolkit-core) |

## Contribution

Contributions are more than welcome!

Please read our [contributing guide](CONTRIBUTING.md) to learn about our development process, how to propose fixes and improvements, and how to build and test the code.

## Special Thanks

*To be completed...*

## License

Apache License 2.0
