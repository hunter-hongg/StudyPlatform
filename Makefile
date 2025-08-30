BUILD_DIR = ./.build

.PHONY: build
all: 
	@cd $(BUILD_DIR) && make 
	@target/学习平台
	@rm -f log.log
build:
	@make -C build
fresh: 
	@cd $(BUILD_DIR) && rm -rf * && cmake ..
refresh:
	@cd $(BUILD_DIR) && rm -rf * && cmake ..
# run:
# 	@target/学习平台
launch:
	@target/学习平台
	@rm -f log.log
