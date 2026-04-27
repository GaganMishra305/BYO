#include "../huffman.cpp"

#include <cassert>

int main() {
    std::istringstream input("aaabbc");
    auto freq = build_frequency_table(input);

    assert(freq['a'] == 3);
    assert(freq['b'] == 2);
    assert(freq['c'] == 1);
    assert(format_frequency_table(freq) == "a : 3\nb : 2\nc : 1\n");

    return 0;
}
