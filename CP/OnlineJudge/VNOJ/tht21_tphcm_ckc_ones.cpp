#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int n , m , ask , x , y , u , id;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n , m;
	bitset<tm> s[MAX_N];
	char c;
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 0 ; j < tm ; j++) {
			cin >> c;
			s[i][j] = c - '0';
		}
	}
	int q; cin >> q;
	bitset<tm> tmp;
	for (int i = 1 ; i <= q ; i++) {
		cin >> ask;
		if (ask == 1) {
			cin >> u >> id;
			s[u].flip(id - 1);
		}
		else {
			cin >> x >> y;
			tmp = s[x] ^ s[y];
			cout << tmp.count() << '\n';
		}
	}
	return 0;
}