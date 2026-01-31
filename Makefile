.PHONY: all build test clean

all: build

build:
	cmake -S . -B build -G Ninja
	cmake --build build

test: build
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build
