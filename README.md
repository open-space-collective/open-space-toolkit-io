# Library :: IO

Addressing, networking, database connectors.

[![Build Status](https://travis-ci.com/open-space-collective/library-io.svg?branch=master)](https://travis-ci.com/open-space-collective/library-io)
[![Code Coverage](https://codecov.io/gh/open-space-collective/library-io/branch/master/graph/badge.svg)](https://codecov.io/gh/open-space-collective/library-io)
[![Documentation](https://readthedocs.org/projects/docs/badge/?version=latest)](https://open-space-collective.github.io/library-io)

## Warning

Library **name** and **license** are yet to be defined.

Please check the following projects:

- [Naming Project](https://github.com/orgs/open-space-collective/projects/1)
- [Licensing Project](https://github.com/orgs/open-space-collective/projects/2)

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

The documentation can be found [here](https://open-space-collective.github.io/library-io).

## Setup

### Development

Using [Docker](https://www.docker.com) is recommended, as the development tools and dependencies setup is described in the provided [Dockerfile](./tools/development/docker/Dockerfile).

Instructions to install Docker can be found [here](https://docs.docker.com/install/).

Start the development environment:

```bash
./tools/development/start.sh
```

This will also build the `openspacecollective/library-io:latest` Docker image, if not present already.

If installing Docker is not an option, please manually install the development tools (GCC, CMake) and the dependencies.
The procedure should be similar to the one described in the [Dockerfile](./tools/development/docker/Dockerfile).

### Build

From the development environment:

```bash
./build.sh
```

Manually:

```bash
mkdir -p build
cd build
cmake ..
make
```

### Test

From the development environment:

```bash
./test.sh
```

Manually:

```bash
./bin/library-io.test
```

## Dependencies

The **IO** library internally uses the following dependencies:

| Name        | Version | License                | Link                                                                                                   |
|-------------|---------|------------------------|--------------------------------------------------------------------------------------------------------|
| Boost       | 1.67.0  | Boost Software License | [boost.org](https://www.boost.org)                                                                     |
| Pistache    | master  | Apache License 2.0     | [pistache.io](http://pistache.io)                                                                      |
| Core        | master  | TBD                    | [github.com/open-space-collective/library-core](https://github.com/open-space-collective/library-core) |

## Contribution

Contributions are more than welcome!

Please read our [contributing guide](CONTRIBUTING.md) to learn about our development process, how to propose fixes and improvements, and how to build and test the code.

## Special Thanks

*To be completed...*

## License

*To be defined...*