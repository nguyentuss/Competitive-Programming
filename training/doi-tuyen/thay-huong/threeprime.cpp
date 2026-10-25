#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

struct seg {
	int a , b , c;
};

vector <bool> eratosthenes((int) 1e7 , false);
vector <int> v;
vector <seg> ans;

void sieve() {
	for (int i = 2 ; i * i <= 1e7 ; i++) {
		for (int j = i * i ; j <= 1e7 ; j += i) {
			if (!eratosthenes[j]) 
				eratosthenes[j] = true;
		}
	}
	for (int i = 2 ; i <= 1e7 ; i++) {
		if (!eratosthenes[i])
			v.push_back(i); 
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	sieve();
	//cout << v[340000];
	for (int i = 0 ; i < 340000 ; i++) {
		if (!eratosthenes[2*v[i] - 1]) 
			ans.push_back({v[i] , v[i] , 2*v[i] - 1});
		if (!eratosthenes[2*v[i] + 1]) 
			ans.push_back({v[i] , v[i] , 2*v[i] + 1});
	}
	int k;	
	cin >> k;
	cout << ans[k - 1].a << " " << ans[k - 1].b << " " << ans[k - 1].c; 
	return 0;
}