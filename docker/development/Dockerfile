# Apache License 2.0

ARG BASE_IMAGE_VERSION="latest"

# General purpose development image (root user)

FROM openspacecollective/open-space-toolkit-base-development:${BASE_IMAGE_VERSION} AS root-user

LABEL maintainer="lucas@loftorbital.com"

# Dependencies

# jq

RUN apt-get update \
    && apt-get install -y jq \
    && rm -rf /var/lib/apt/lists/*

## fmt

ARG FMT_VERSION="5.2.0"

RUN cd /tmp \
    && git clone --branch ${FMT_VERSION} --depth 1 https://github.com/fmtlib/fmt.git \
    && cd fmt \
    && mkdir build \
    && cd build \
    && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE .. \
    && make --silent -j $(nproc) \
    && make install \
    && rm -rf /tmp/fmt

## libcurl

RUN apt-get update -y \
    && apt-get install -y libcurl4-openssl-dev libssl-dev \
    && rm -rf /var/lib/apt/lists/*

## Open Space Toolkit ▸ Core

ARG TARGETPLATFORM
ARG OSTK_CORE_MAJOR="5"

## Force an image rebuild when new Core minor or patch versions are detected
ADD https://api.github.com/repos/open-space-collective/open-space-toolkit-core/git/matching-refs/tags/${OSTK_CORE_MAJOR} /tmp/open-space-toolkit-core/versions.json

RUN mkdir -p /tmp/open-space-toolkit-core \
    && cd /tmp/open-space-toolkit-core \
    && export LATEST_PATCH_OF_MINOR=$(jq -r .[-1].ref versions.json | cut -d "/" -f3) \
    && export PACKAGE_PLATFORM=$(if [ ${TARGETPLATFORM} = "linux/amd64" ]; then echo "x86_64"; elif [ ${TARGETPLATFORM} = "linux/arm64" ]; then echo "aarch64"; else echo "Unknown platform" && exit 1; fi;) \
    && wget --quiet https://github.com/open-space-collective/open-space-toolkit-core/releases/download/${LATEST_PATCH_OF_MINOR}/open-space-toolkit-core-${LATEST_PATCH_OF_MINOR}-1.${PACKAGE_PLATFORM}-runtime.deb \
    && wget --quiet https://github.com/open-space-collective/open-space-toolkit-core/releases/download/${LATEST_PATCH_OF_MINOR}/open-space-toolkit-core-${LATEST_PATCH_OF_MINOR}-1.${PACKAGE_PLATFORM}-devel.deb \
    && apt-get install -y ./*.deb \
    && rm -rf /tmp/open-space-toolkit-core

# Labels

ARG VERSION
ENV VERSION="${VERSION}"
LABEL VERSION="${VERSION}"

# Development image for humans (non-root user)

FROM root-user AS non-root-user

# Install dev utilities

RUN apt-get update \
    && apt-get install -y zsh sudo \
    && rm -rf /var/lib/apt/lists/*

# Create non-root user and group

ARG USERNAME="developer"
ARG USER_UID="1000"
ARG USER_GID=${USER_UID}
RUN groupadd --gid ${USER_GID} ${USERNAME} || true \
    && adduser --uid ${USER_UID} --gid ${USER_GID} ${USERNAME} \
    && echo "${USERNAME} ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers.d/${USERNAME}

# Use non-root user

USER ${USERNAME}

# Install shell utilities

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" \
    && git clone https://github.com/bhilburn/powerlevel9k.git /home/${USERNAME}/.oh-my-zsh/custom/themes/powerlevel9k \
    && git clone https://github.com/zsh-users/zsh-autosuggestions /home/${USERNAME}/.oh-my-zsh/custom/plugins/zsh-autosuggestions \
    && git clone https://github.com/zsh-users/zsh-syntax-highlighting.git /home/${USERNAME}/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting \
    && mkdir -p /home/${USERNAME}/.vscode-server/extensions /home/${USERNAME}/.vscode-server-insiders/extensions

## Configure environment

ENV PATH="/home/${USERNAME}/.local/bin:${PATH}"

# Entrypoint

CMD [ "/bin/bash" ]
