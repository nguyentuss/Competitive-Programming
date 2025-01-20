#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = opt<int>("min_n");
	int max_n = opt<int>("max_n");
	int val = opt<int>("max_val");
	int id = opt<int>("id");
	int n = rnd.next(min_n, max_n);
	cout << n << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << rnd.next(1 , val);
        if (i != (n - 1)) cout << " ";
    }
    cout << endl;
    return 0;
}