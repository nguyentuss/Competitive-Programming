#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define MAX_N (int) (1e5 + 7)
vector<ii> v;
bool check[MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int l , r; cin >> l >> r;
		v.push_back(ii(l , r));
	}
	sort(v.begin() , v.end());
	for (int i = 0 ; i < n ; i++) {

	}
	return 0;
}