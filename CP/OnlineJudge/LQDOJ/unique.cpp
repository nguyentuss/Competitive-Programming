#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main() {
	//ios::sync_with_stdio(0); cin.tie(NULL);

	unordered_map <int,int> m;
	vector <int> v;

	int n , x; scanf("%d",&n);
	for (int i = 0 ; i < n ; i++) {
		scanf("%d",&x);
		m[x] ++;		
		if (m[x] == 1) v.push_back(x);
	}
	for (int i = 0 ; i < (int) v.size(); i++) {
		if (m[v[i]] == 1) {
			printf("%d",v[i]);
			return 0;
		} 
	}
	return 0;
}