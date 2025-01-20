#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = opt<int>("min_n");
	int max_n = opt<int>("max_n");
    int min_m = opt<int>("min_m");
	int max_m = opt<int>("max_m");
    int sub = opt<int>("sub");  
	int id = opt<int>("id");
	int n = max(min_n, rnd.wnext(max_n, 10));
    int m = max(min_m, rnd.wnext(max_m, 10)); 
    cout << n << " " << m <<  '\n';
    return 0;
}