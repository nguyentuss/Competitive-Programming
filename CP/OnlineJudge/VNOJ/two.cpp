#include <bits/stdc++.h>

using namespace std;

vector<int> a(1e5);
vector<int> b(1e5);
bool cmp1(const int &x , const int &y) {
	return a[x] < a[y];
}
bool cmp2(const int &x , const int &y) {
	return b[x] > b[y];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n; i++) 
		cin >> a[i];
	for (int i = 1 ; i <= n ; i++) 
		cin >> b[i];
	vector<int> n1 , n2;
	for (int i = 1 ; i <= n ; i ++) {
		if (a[i] <= b[i]) n1.push_back(i);
		if (a[i] > b[i]) n2.push_back(i);
	}	
	sort(n1.begin() , n1.end() , cmp1);
	sort(n2.begin() , n2.end() , cmp2);	
	vector<int> tmp;
	for (auto x : n1) tmp.push_back(x);
	for (auto x : n2) tmp.push_back(x);
	int ta = a[tmp[0]] , tb = ta + b[tmp[0]];
	for (int i = 1 ; i < tmp.size() ; i++) {
		ta += a[tmp[i]];
		if (ta >= tb) tb = ta + b[tmp[i]];
		else tb += b[tmp[i]];
	}
	cout << tb << '\n';
	for (auto x : tmp) cout << x << " ";
	return 0;
}