#include <bits/stdc++.h>
#include "hufftree.cpp"
using namespace std;

const int BITS = 8; // bits that are compressed together

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

map<char, string> build_prefix_table(HuffTree *t) {
    // using simple dfs-strategy for prefix-map generation by traversing the hufftree
    map<char, string> code;
    queue<Node*> q;
    q.push(t->root);

    function<void(Node*, string)> dfs = [&] (Node* root, string path) {
        if(root->is_leaf()) {
            code[root->element] = path;
        } else {
            dfs(root->left,     path + "0");
            dfs(root->right, path + "1");
        }
    };
    dfs(t->root, "");
    return code;
}

map<char, int> build_frequency_table(istream& input) {
    map<char, int> freq;
    char ch;
    while(input.get(ch)) {
        freq[ch]++;
    }
    return freq;
}

template<typename K, typename V>
string format_table(const map<K, V>& table) {
    ostringstream output;
    for (const auto& [k, v] : table) {
        output << k << " : " << v << '\n';
    }
    return output.str();
}

void encoder(int bit, map<char, string> &codes, ifstream &inp, ofstream &out) {
    inp.clear();              
    inp.seekg(0, std::ios::beg); 
    string buff = "";
    char ch;
    while(inp.get(ch)) {
        buff += codes[ch];
        while(buff.size() >= bit) {
            string bit_string = buff.substr(0, bit);
            buff = buff.substr(bit);
            char byte = static_cast<char>(std::stoi(bit_string, nullptr, 2));
            out << byte;
        }
    } 
    
    // flush remaining bits
    if(!buff.empty()) {
        buff.append(bit - buff.size(), '0');
        char byte = static_cast<char>(stoi(buff, nullptr, 2));
        out.put(byte);
    }
}

void decoder(ifstream &cfile, ofstream &dfile) {
    dfile << "decompressed file wud be here" << endl;
}

#ifndef UNIT_TEST
int main(int argc, char* argv[]) {
    // reading input file
    if(argc != 2) {
        cout << "Usage: ./huffman <filename.txt>" << endl;
        return 1;
    }
    string fname = argv[1];
    string name  = fname.substr(0, fname.rfind("."));
    string fext  = fname.substr(fname.rfind("."));
    ifstream f(fname);

    // execution parsing based on file type passed
    if(fext == ".huff") {
        string dname = name+"_D" + ".txt";
        cout << "Decompressed file is stored at " << dname << endl;
        ifstream cfile(fname);
        ofstream dfile(dname);
        decoder(cfile, dfile);
        return 0;
    } else if(fext != ".txt") {
        cout << "Expected a .txt file" << endl;
        return 1;
    } else if(!f.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    // generating output filename.huff
    string oname = name + ".huff";
    ofstream outfile(oname);
    if(outfile.is_open()) {
        map<char, int> ft = build_frequency_table(f);
        outfile << format_table(ft);
        outfile << "===HEADER ENDS===" << endl;
        map<char, string> codes = build_prefix_table(build_tree(ft));
        encoder(BITS, codes, f, outfile); // number of bits that collapse to make one compressed character {8, 16}
    } else {
        cout << "Unable to create output file" << endl;
        return 1;
    }
    cout << "Compressed file stored at " + oname << endl;
    return 0;
}
#endif
