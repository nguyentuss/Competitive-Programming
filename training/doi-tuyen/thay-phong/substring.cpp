#include <bits/stdc++.h>

using namespace std;

int a[300];
vector <int> v;
int k , n;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cin >> s;
	for (int i = 0 ; i < (int) s.size() ; i++) 
		a[(int) s[i]] ++;
	for (int i = 'a' ; i <= 'z' ; i++) {
		v.push_back(a[i]);
	}
	sort(v.begin() , v.end() , greater<int>());
	int ans = 0;
	for (int i = 0 ; i < k ; i++) {
		ans += v[i];
	}
	cout << ans;
	return 0;
}