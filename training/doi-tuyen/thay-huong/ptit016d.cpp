#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("ptit016d.inp","r",stdin);
#define fo freopen("ptit016d.out","w",stdout);

vector <int> v;

int main() { 
	boost; 
	fi;fo;
	int n , k , x; cin >> n >> k;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin() + 1 , v.end());

	long long total1 = 0 , total2 = 0;

	total1 = v[0];
	for (int i = 1 ; i < n - k ; i++) 
		total1 -= v[i];
		
	for (int i = n - k; i < n  ; i++) 
			total2 += v[i];

	cout << total2 + total1;
	


	return 0;
}