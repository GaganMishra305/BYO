#include <bits/stdc++.h>
using namespace std;

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
