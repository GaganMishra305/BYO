target:
	g++ -o ./build/huffman huffman.cpp
	./build/huffman tests/book.txt
	./build/huffman tests/book.huff
	diff tests/book.txt tests/book_D.txt && echo "Files match!" || echo "Files differ!"

test:
	g++ -DUNIT_TEST -o ./build/huffman_test tests/test_huffman.cpp
	./build/huffman_test

clean:
	rm  build/*
