#include <bits/stdc++.h>

using namespace std;

string n , m;
string ans1 , ans2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("collide.inp","r",stdin);
	freopen("collide.out","w",stdout);
	
	cin >> n >> m;
	while (n.size() < m.size()) n = '0' + n;
	while (m.size() < n.size()) m = '0' + m;
	for (int i = 0 ; i < n.size() ; i++) {
		if (n[i] > m[i]) ans1.push_back(n[i]);
		if (n[i] < m[i]) ans2.push_back(m[i]);
		if (n[i] == m[i]) {
			ans1.push_back(n[i]);
			ans2.push_back(m[i]);
		}
	} 
	int a = atoi(ans1.c_str());
	int b = atoi(ans2.c_str());
	cout << a << '\n' << b;
	return 0;
}