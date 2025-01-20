#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long cnt_1, c;
vector <int> a (18), choose (18);
vector <int> money {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};

void back (int pos) {
	if (pos == 18) {
		long long sum = 0;
		int cur_1 = 0;
		for (int i = 0; i < 9; i++)
			if (choose[i] == 1) {
				cur_1++;
				sum += a[i] * money[i];
			}
		for (int i = 9; i < 18; i++)
			if (choose[i] == 1) sum -= a[i] * money[i - 9];

		if (sum == c && cur_1 > cnt_1)
			cnt_1 = cur_1;
	}
	else {
		for (int i = 0; i < 2; i++) {
			choose[pos] = i;
			back (pos + 1);
		}
	}
}

int main () {
	ios::sync_with_stdio (false); cin.tie (0);
	//freopen ("SC1.inp", "r", stdin);
	//freopen ("SC1.out", "w", stdout);

	int t; cin >> t;

	while (t--) {
		cnt_1 = 1e9;
		int cnt = 0;

		cin >> c;
		for (int i = 0; i < 9; i++) {
			string s; cin >> s;
			cin >> a[i] >> a[i + 9];
			if (a[i] == true) cnt++;
		}

		back (0);

		if (cnt_1 == 1e9) cout << "SORRY!!!" << '\n';
		else cout << cnt - cnt_1 << '\n';
	}

	return 0;
}