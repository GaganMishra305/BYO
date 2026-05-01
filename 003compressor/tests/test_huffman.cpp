#include "../huffman.cpp"

#include <cassert>
#include <iostream>

int main() {
    std::istringstream input("aaabbc");

    // ---test frequency map builder---
    auto freq = build_frequency_table(input);

    // ---test frequency map formatter---
    assert(freq['a'] == 3);
    assert(freq['b'] == 2);
    assert(freq['c'] == 1);
    assert(format_frequency_table(freq) == "a : 3\nb : 2\nc : 1\n");
    
    // --- test build_tree (hufftree_build) ---
    std::map<char,int> freq2{{'a',3},{'b',2},{'c',1}};
    HuffTree* tree = build_tree(freq2);
    assert(tree != nullptr);
    assert(tree->root != nullptr);
    int total = 3 + 2 + 1;
    assert(tree->root->weight == total);
    std::function<int(Node*)> sumLeafWeights = [&](Node* n)->int {
        if(!n) return 0;
        if(n->is_leaf()) {
            LeafNode* ln = static_cast<LeafNode*>(n);
            return ln->weight;
        } else {
            InternalNode* in = static_cast<InternalNode*>(n);
            return sumLeafWeights(in->left) + sumLeafWeights(in->right);
        }
    };
    assert(sumLeafWeights(tree->root) == total);

    // --- test build_prefix_table ---
    map<char, string> codes = build_prefix_table(tree);
    assert(codes['a'] == "0");
    assert(codes['b'] == "11");
    assert(codes['c'] == "10");
    return 0;
}
