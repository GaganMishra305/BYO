target:
	g++ -o ./build/huffman huffman.cpp
	./build/huffman tests/book.txt

test:
	g++ -DUNIT_TEST -o ./build/huffman_test tests/test_huffman.cpp
	./build/huffman_test

clean:
	rm -rf build