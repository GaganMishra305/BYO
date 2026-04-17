#include <bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "Usage: ccwc <one flag> <filename.txt>\n";
        return 1;
    }

    // file-opener
    string fname = argv[argc - 1];
    ifstream f(fname);
    if(!f.is_open()) {
        cout << "Failed to open file\n";
        return 1;
    }

    // core
    char ch;
    int ccc = 0;
    int lcc = 0;
    int wcc = 0;
    string word = "";
    bool inWord = false;
    while(f.get(ch)) {
        if(ch == '\n')lcc++;
        if (isspace(static_cast<unsigned char>(ch))) {
            inWord = false;
        } else if (!inWord) {
            wcc++;
            inWord = true;
        }
        ccc++; 
    }
    
    if(argc == 2) { // noflags
        cout << lcc << " " << wcc << " " << ccc << " " << fname << endl;
        return 0;
    }

    string flag = argv[1]; // assumption: one flag at a time
    switch(flag[1]) {
        case 'c':
            cout << ccc << " " << fname << endl;
            break;
        case 'l':
            cout << lcc << " " << fname << endl;
            break;
        case 'w':
            cout << wcc << " " << fname << endl;
            break;
        
        default:
            cout << "Invalid flag\n" << endl;
    }
    return 0;
}
