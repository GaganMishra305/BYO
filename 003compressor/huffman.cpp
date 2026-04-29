#include <bits/stdc++.h>
#include "hufftree.cpp"
using namespace std;

HuffTree* build_tree(const map<char, int> &freq) {
    // min-heap of HuffTree* by root weight
    auto cmp = [](HuffTree* a, HuffTree* b){ return a->root->weight > b->root->weight; };
    priority_queue<HuffTree*, vector<HuffTree*>, decltype(cmp)> pq(cmp);
    for(const auto &p : freq) {
        HuffTree* leaf = new HuffTree(p.first, p.second);
        pq.push(leaf);
    }
    if(pq.empty()) return nullptr;
    while(pq.size() > 1) {
        HuffTree* t1 = pq.top(); pq.pop();
        HuffTree* t2 = pq.top(); pq.pop();
        HuffTree* merged = new HuffTree(t1->root, t2->root, t1->root->weight + t2->root->weight);
        pq.push(merged);
    }
    return pq.top();
}

map<char, int> build_frequency_table(istream& input) {
    map<char, int> freq;
    char ch;
    while(input.get(ch)) {
        freq[ch]++;
    }
    return freq;
}

string format_frequency_table(const map<char, int>& freq) {
    ostringstream output;
    for(const auto& [ch, count] : freq) {
        output << ch << " : " << count << '\n';
    }
    return output.str();
}

#ifndef UNIT_TEST
int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage: ./huffman <filename.txt>" << endl;
        return 1;
    }
    string fname = argv[1];
    ifstream f(fname);
    if(!f.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }
    cout << format_frequency_table(build_frequency_table(f));
    return 0;
}
#endif
