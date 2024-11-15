# Dockerイメージ名
IMAGE_NAME = cpp_env

# コンテナ名
CONTAINER_NAME = cpp_container

# 作業ディレクトリ
WORKDIR = /app

# ホストのプロジェクトパス
HOST_PATH = $(shell pwd)

# Dockerイメージのビルド
build:
	docker buildx build --platform linux/arm64 -t $(IMAGE_NAME) .

# 開発用コンテナを起動
.DEFAULT_GOAL = run
run: build
	docker run --name $(CONTAINER_NAME) \
		-it \
		--rm \
		--platform linux/arm64 \
		-e HOME=/tmp \
		-v "$(HOST_PATH):$(WORKDIR)" \
		$(IMAGE_NAME)

# クリーンアップ
clean:
	-docker stop $(CONTAINER_NAME) 2>/dev/null || true
	-docker rm $(CONTAINER_NAME) 2>/dev/null || true
	-docker rmi $(IMAGE_NAME) 2>/dev/null || true

# 完全なクリーンアップ
fclean: clean
	-docker system prune -f
	-docker volume prune -f

.PHONY: build run-norm clean fclean