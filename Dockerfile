FROM ubuntu:22.04

# 必要なパッケージのインストール (clangとmake、その他開発ツール)
RUN apt update && apt install -y \
    clang \
    g++ \
    make \
    build-essential \
    cmake \
    # 標準C++ライブラリの開発ファイルをインストール
    libstdc++-11-dev \
    # 他に必要なツールがあればここに追加
    && rm -rf /var/lib/apt/lists/*

# 作業ディレクトリの設定
WORKDIR /app

# ホストのファイルをコンテナにマウントするための設定
CMD ["/bin/bash"]