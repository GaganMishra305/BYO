#include <bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {
    // file-opener
    string fname = argv[argc - 1];
    ifstream f(fname);
    istream* in = &cin;
    if(fname[0] != '-') { // assumption: filename does not begin with '-'
        if(!f.is_open()) {
            cout << "Failed to open file\n";
            return 1;
        }
        in = &f;
    } else {
        fname = "";
    }

    // core
    char ch;
    int ccc = 0;
    int lcc = 0;
    int wcc = 0;
    string word = "";
    bool inWord = false;
    while(in -> get(ch)) {
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
