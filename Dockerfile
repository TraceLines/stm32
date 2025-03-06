# 使用Ubuntu作为基础镜像
# ARG TARGETPLATFORM=linux/amd64
# FROM antrea-ubuntu-arm64:latest
FROM ubuntu:22.04

# 安装必要工具链和依赖
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    cmake \
    ninja-build\
    git \
    libusb-1.0-0-dev \
    openocd \
    wget \
    && rm -rf /var/lib/apt/lists/*
# 
# docker build --platform linux/amd64 -t stm32-builder .

# 安装ARM GCC工具链
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 && \
    tar xjf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 && \
    mv gcc-arm-none-eabi-10.3-2021.10 /opt/arm-gcc && \
    rm gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2

# 添加工具链到PATH
ENV PATH="/opt/arm-gcc/bin:${PATH}"

# 设置工作目录
WORKDIR /workspace
