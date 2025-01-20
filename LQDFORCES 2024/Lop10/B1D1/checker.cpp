#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> a;
set<int> s;

pair<vector<int>, vector<int>> read_answer(InStream &stream) {
    vector<int> b;
    vector<int> c;
    for (int x : a) {
        s.insert(x);
    }
    int m = s;
    for (int i = 0 ; i < m ; i++) {
        int x = stream.readInt(1 , 1000 * 1000 * 1000); 
        b.push_back(x);
    }
    for (int i = 0 ; i < m ; i++) {
        int x = stream.readInt(1 , 1000 * 1000 * 1000); 
        c.push_back(x);
    }

    return pair<vector<int> , vector<int>>(b, c);
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt(); 
    for (int i = 0 ; i < n ; i++) {
        int x = inf.readInt(); 
        a.push_back(x);
    }

    auto jans = read_answer(ans);
    auto pans = read_answer(ouf);
    if (jans == pans) {
        quitf(_pc(5) , "correct");
    }
    else {
        if ()
        quitf(_wa , "wa");
    }
    
    return 0;
}