#include <bits/stdc++.h>
using namespace std;

struct Node {
    int weight = 0;
    virtual bool is_leaf();
};

inline bool Node::is_leaf() { return false; }

struct LeafNode : public Node {
    char element;
    LeafNode(char el, int wt) {
        element = el;
        weight = wt;
    }
    bool is_leaf() {
        return true;
    }
};

struct InternalNode : public Node {
    Node* left;
    Node* right;
    InternalNode(Node* l, Node* r, int wt) {
        left = l;
        right = r;
        weight = wt;
    }
    bool is_leaf() {
        return false;
    }
};

struct HuffTree {
    Node* root;
    HuffTree(char el, int wt) {
        root = new LeafNode(el, wt);
    }
    HuffTree(Node* l, Node* r, int wt) {
        root = new InternalNode(l, r, wt);
    }
    int compare_to(Node* node) {
        if(root->weight < node->weight) return -1;
        else if(root->weight == node->weight) return 0;
        return 1;
    }
};
