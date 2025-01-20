#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	int min_n = opt<int>("min_n");
	int max_n = opt<int>("max_n");
    int min_m = opt<int>("min_m");
	int max_m = opt<int>("max_m");
    int min_q = opt<int>("min_q");
	int max_q = opt<int>("max_q");
	int min_val = opt<int>("min_val");
    int max_val = opt<int>("max_val");
    int sub = opt<int>("sub");
	int id = opt<int>("id");
    int limit;
    if (sub == 1) {
        limit = 100;
    }
    if (sub == 2) {
        limit = 10000; 
    }
    if (sub == 3) {
        limit = 100000;
    }
	int n = max(min_n, rnd.wnext(max_n, 10));
    int m = max(min_m, rnd.wnext(max_m, 10)); 
    while (n * m > limit) {
        if (n > 1) n--;
        if (m > 1) m--; 
    }
    int q = max(min_q, rnd.wnext(max_q, 10));
    cout << n << " " << m <<  " " << q << '\n';
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char c = rnd.next(min_val , max_val) + 'a';
            cout << c;
        }
        cout << '\n';
    }
    for (int i = 0 ; i < q ; i++) {
        int len = min({rnd.next(2 , 10) , n , m});
        for (int j = 0 ; j < len ; j++) {
            char c = rnd.next(min_val , max_val) + 'a';
            cout << c;
        }
        cout << '\n';   
    }
    return 0;
}