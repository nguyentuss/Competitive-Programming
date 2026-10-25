#include <bits/stdc++.h>

using namespace std;

#define MIN_NUM (int) (1e9 +7)

vector <int> b , r;
long long totalb , totalr;

void init(){
	b.clear();
	r.clear();
	totalb = 0;
	totalr = 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("matkhau.inp","r",stdin);
	freopen("matkhau.out","w",stdout);

	int t; cin >> t;
	while (t --) {
		init();
		int n , m , x;
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			b.push_back(x);
			totalb += x;
		}
		cin >> m;
		for (int i = 0 ; i < m ; i++) {
			cin >> x;
			r.push_back(x);
			totalr += x;
		}
		long long maximumb = totalb , maximumr = totalr;
		for (int i = n - 1 ; i >= 0 ; i --) {
			totalb -= b[i];
			maximumb = max(maximumb , totalb);
		}
		for (int i = m - 1 ; i >= 0 ; i --){ 
			totalr -= r[i];
			maximumr = max(maximumr , totalr);
		}
		cout << maximumb + maximumr << endl;
	}

	return 0;
}