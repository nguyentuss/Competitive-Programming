#include <bits/stdc++.h>

using namespace std;

vector <int> v , checked;
int n , x;


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("preolp1.inp","r",stdin);
	freopen("preolp1.out","w",stdout);
	int test; cin >> test;
	for (int i = 0 ; i < test ; i++) {
		checked.clear();v.clear();
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			v.push_back(x);
			checked.push_back(x);
		}
		long long ans = 0;
		sort(checked.begin() , checked.end() , greater<int>());
		for (int i = 0 ; i < n ; i++) {
			if (v[i] == checked[0]) ans += checked[1];
			else ans += checked[0];
		}
		cout << ans << endl;
	}


	return 0;
}