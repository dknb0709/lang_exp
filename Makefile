all: build test

build:
	./build-and-test.sh

test:
	./build/test/test_tokenizer.out ./test/resource/input.txt
	./build/test/test_tokenizer.out ./test/resource/input2.txt
	./build/test/test_tokenizer.out ./test/resource/input3.txt
	./build/test/test_tokenizer.out ./test/resource/error1.txt
	./build/test/test_tokenizer.out ./test/resource/error2.txt

clean:
	rm -rf ./build

.PHONY: build test clean
