FROM ubuntu:22.04

# 必要なパッケージのインストール (clang, make, 開発ツール, python3)
RUN apt update && apt install -y \
    clang \
    g++ \
    make \
    build-essential \
    cmake \
    valgrind \
    libstdc++-11-dev \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

RUN pip install pytest

# 作業ディレクトリの設定
WORKDIR /app

# ホストのファイルをコンテナにマウントするための設定
CMD ["/bin/bash"]
