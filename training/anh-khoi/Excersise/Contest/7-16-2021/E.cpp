#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7) 

int n , numnode = 1;
int trie[MAX_N*19 + 7][10];
bool check = false;

void addnum(int x) {
	vector <int> num(19);
	for (int i = 18 ; i >= 0 ; i --) {
      num[i] = x%10;
      x/=10;
    }
    if (check) {
    	for (int chose = 0 ; choose < 2 ; choose++) {
    		int node = 1;
    		for (int i = 0 ; i < len ; i++) {
    			for (int j = 0 ; j < 10 ; j++) {
    				if (trie[node][j]) {
    					
    				}
    			}
    		}
  		}
    }
    int node = 1;
    for (auto e : num) {
    	if (!trie[node][e])
    		trie[node][e] = ++numnode;
    	node = trie[node][e];
    }
   	check = true;
   	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		long long x; cin >> x;
		addnum(x);
	}
	return 0;
}