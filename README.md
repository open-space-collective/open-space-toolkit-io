# Library ▸ I/O

Addressing, networking, database connectors.

[![Build Status](https://travis-ci.com/open-space-collective/library-io.svg?branch=master)](https://travis-ci.com/open-space-collective/library-io)
[![Code Coverage](https://codecov.io/gh/open-space-collective/library-io/branch/master/graph/badge.svg)](https://codecov.io/gh/open-space-collective/library-io)
[![Documentation](https://img.shields.io/readthedocs/pip/stable.svg)](https://open-space-collective.github.io/library-io)
[![GitHub version](https://badge.fury.io/gh/open-space-collective%2Flibrary-io.svg)](https://badge.fury.io/gh/open-space-collective%2Flibrary-io)
[![PyPI version](https://badge.fury.io/py/LibraryIOPy.svg)](https://badge.fury.io/py/LibraryIOPy)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

## Warning

Library **name** is yet to be defined.

Please check the following projects:

- [Naming Project](https://github.com/orgs/open-space-collective/projects/1)

*⚠ This library is still under heavy development. Do not use!*

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

- [C++](https://open-space-collective.github.io/library-io)
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

1. Build the `openspacecollective/library-io-development` Docker image.
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
./bin/library-io.test
```

*Tip: `helpers/test.sh` simplifies running tests from within the development environment.*

## Dependencies

| Name                | Version | License                | Link                                                                                                   |
|---------------------|---------|------------------------|--------------------------------------------------------------------------------------------------------|
| Boost               | 1.69.0  | BSL-1.0                | [boost.org](https://www.boost.org)                                                                     |
| C++ Network Library | 0.13.0  | BSL-1.0                | [cpp-netlib.org](https://cpp-netlib.org)                                                               |
| Pistache            | master  | Apache License 2.0     | [pistache.io](http://pistache.io)                                                                      |
| Core                | master  | Apache License 2.0     | [github.com/open-space-collective/library-core](https://github.com/open-space-collective/library-core) |

## Contribution

Contributions are more than welcome!

Please read our [contributing guide](CONTRIBUTING.md) to learn about our development process, how to propose fixes and improvements, and how to build and test the code.

## Special Thanks

*To be completed...*

## License

Apache License 2.0
