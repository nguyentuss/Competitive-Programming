#include <bits/stdc++.h>

using namespace std;

vector<int> a,b;
int k , m;
int na , nb;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> na >> nb >> k >> m;
	for (int i = 0 ; i < na ;i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	for (int i = 0 ; i < nb ;i++) {
		int x; cin >> x;
		b.push_back(x);
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end() , greater<int>());
	if (a[k - 1] < b[m - 1]) cout << "YES";
	else cout << "NO";	
	return 0;
}