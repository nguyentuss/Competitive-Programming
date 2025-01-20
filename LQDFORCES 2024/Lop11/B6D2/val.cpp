#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
const int VAL = 1000 * 1000;
 
int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(50 , 100 , "n"); 
    inf.readEoln();
    for (int i = 0 ; i < n ; i++) {
        int x = inf.readInt(-VAL , VAL , "x");
        int y = inf.readInt(-VAL , VAL , "y");
        inf.readEoln();
        //ensuref()
    }
    inf.readEof();
    return 0;
}