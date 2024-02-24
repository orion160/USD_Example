FROM fedora:latest as base

SHELL ["/bin/bash", "-c"]

# Base setup
RUN dnf upgrade -y \
    && dnf install -y sudo \
    && groupadd dev \
    && useradd -g dev -m -s /bin/bash orphee \
    && echo "orphee ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

FROM base

USER orphee:dev

# NeoVim
RUN sudo dnf install -y neovim

# Misc
RUN sudo dnf install -y git gh curl wget bat tar zip unzip openssh gnupg python3 python3-pip bash-completion

# LLVM toolchain
## LLVM perse can make cross platform builds
#RUN sudo dnf install -y llvm clang clang-analyzer clang-tools-extra lldb

# LLVM dev
# RUN sudo dnf install -y llvm-devel clang-devel clang-tools-extra-devel lldb-devel

# LLVM app
# llvm-static llvm-libs llvm-cmake-utils

# GCC toolchain
RUN sudo dnf install -y gcc gcc-c++ gdb binutils binutils-gold binutils-gprofng
# gcc-gfortran

# Emulation
# qemu-user

# ARM64
# qemu-system-aarch64 edk2-aarch64

# GCC cross toolchain
# RUN sudo dnf install -y gcc-aarch64-linux-gnu gcc-c++-aarch64-linux-gnu binutils-aarch64-linux-gnu

# RISCV
# qemu-system-riscv64 edk2-riscv64
# RUN sudo dnf install -y gcc-riscv64-linux-gnu gcc-c++-riscv64-linux-gnu binutils-riscv64-linux-gnu

# Build tools
RUN sudo dnf install -y cmake ninja-build

# Oh My Posh!
RUN export omp=$HOME/.orphee/omp \
    && mkdir -p $omp \
    && curl -s https://ohmyposh.dev/install.sh | bash -s -- -d $omp \
    && echo "export PATH=$omp:\$PATH" >> ~/.bashrc \
    && echo 'eval "$(oh-my-posh init bash --config https://raw.githubusercontent.com/JanDeDobbeleer/oh-my-posh/main/themes/spaceship.omp.json)"' >> ~/.bashrc

# vcpkg
#RUN export vcpkg=$HOME/.orphee/vcpkg \
#    && git clone https://github.com/Microsoft/vcpkg.git $vcpkg \
#    && cd $vcpkg \
#    && ./bootstrap-vcpkg.sh \
#    && echo "export VCPKG_ROOT=$vcpkg" >> ~/.bashrc \
#    && echo "export PATH=$vcpkg:\$PATH" >> ~/.bashrc

WORKDIR /workspace
