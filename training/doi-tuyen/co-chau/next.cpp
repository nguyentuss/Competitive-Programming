#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int a[100007];
set<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("next.inp","r",stdin);
	//freopen("next.out","w",stdout);
	int n ; cin >> n;
	for (int i = 1 ; i <= n ; i++) { 
		cin >> a[i];
		s.insert(a[i]);
	}
	for (int i = 1 ; i <= n ; i++) {
		// upper_bound(x) là tìm thằng nhỏ nhất mà lớn hơn
		auto it = s.upper_bound(a[i]);
		// nếu kh tìm ra là nó sẽ trỏ tới .end()
		if (it == s.end()) {
			cout << -1 << " ";
		}
		else {
			// nhớ cái dấu * nha , kh có nó kh chạy đx âu 
			cout << *it << " ";
		}
	}
	return 0;
}