default: run

format:
    dart format .
run:
	flutter run
build:
	flutter build linux
test:
    flutter test
check: 
    flutter analyze
go:
	./go/bin/学习平台
rel version:
    flutter build linux --release 
    cp build/linux/x64/release/bundle release/v{{version}} -rv
    tar cavf release/StudyPlatformv{{version}}.tar.xz release/v{{version}}
    mv release/v{{version}} release/raw/v{{version}}
