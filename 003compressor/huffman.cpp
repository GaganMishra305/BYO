#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage: ./huffman <filename.txt>" << endl;
        return 1;
    }

    string fname = argv[1];
    ifstream f(fname);
    char ch;
    map<char, int> freq;
    while(f.get(ch)) {
        freq[ch]++;
    }

    for(auto [ch, f] : freq) {
        cout << ch << " : " << f << endl;
    }

    return 0;
}
