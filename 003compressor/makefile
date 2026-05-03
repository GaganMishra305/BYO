target:
	g++ -o ./build/huffman huffman.cpp
	./build/huffman tests/book.txt
	./build/huffman tests/book.huff

test:
	g++ -DUNIT_TEST -o ./build/huffman_test tests/test_huffman.cpp
	./build/huffman_test

clean:
	rm  build/*
