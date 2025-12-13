BUILD_DIR = ./build
NPROC = `nproc`

# all: 
# 	@cd $(BUILD_DIR) && make -j$(NPROC) 
# 	@target/学习平台
# 	@rm -f log.log
# fresh: 
# 	@cd $(BUILD_DIR) && rm -rf * && cmake ..
# launch:
# 	@target/学习平台
# 	@rm -f log.log
# install:
# 	cp target/学习平台 /usr/local/bin
	# 同时复制依赖
all: go 

run: 
	Cpp/target/学习平台
go: 
	cd Golang && make
rel: 
	cd Golang && make build
grun: 
	cd Golang && make run
