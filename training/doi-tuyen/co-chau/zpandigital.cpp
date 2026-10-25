#include <bits/stdc++.h>

using namespace std;

bool C[10];
int X[10];
vector<int> v;

void calc(int len) {
	int x = 0;
	for (int i = 1 ; i <= len ; i++) 
		x = x*10 + X[i];
	v.push_back(x);
}

void backtr(int i , int len) {
	for (int j = 1 ; j <= len ; j++) {
		if (!C[j]) {
			C[j] = true;
			X[i] = j;
			if (i == len) calc(len);
			else backtr(i + 1 , len);
			C[j] = false;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("zpandigital.inp","r",stdin);
	freopen("zpandigital.out","w",stdout);
	for (int i = 1 ; i <= 8 ; i++) backtr(1 , i);
	sort(v.begin() , v.end());
	//for (auto x : v) cout << x << " ";
	vector<int> rev = v;
	reverse(rev.begin() , rev.end());
	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		int l , r; cin >> l >> r;
		int pos1 = lower_bound(v.begin() , v.end() , l) - v.begin();
		int pos2 = lower_bound(rev.begin() , rev.end() , r , greater<int>()) - rev.begin();
		cout << abs((int)rev.size() - 1 - pos2) - pos1 + 1 << '\n'; 
	}

	return 0;
}