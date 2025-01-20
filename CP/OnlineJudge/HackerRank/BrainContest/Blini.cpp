#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	stack <int> st;
	st.push(0);
	int x;
	int cnt = 0;
	while (cin >> x) {
		while (x > st.top()) {
			cnt += 1;
			st.push(cnt);
		}
		if (st.top() != x) {
			cout << "NO";
			return 0;
		}
		st.pop();
	}
	cout << "YES";
	return 0;
}