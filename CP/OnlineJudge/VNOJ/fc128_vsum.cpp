#include <bits/stdc++.h>

using namespace std;

bool cnt1 , cnt2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int sum = N*(N+1)/2;
	cnt1 = sum%2==0?1:0;
	cnt2 = sum%2==0?0:1;
	int L = 1 , R = N;
	while (R < 100) {
		sum += ++R;
		sum -= L++;
		if (sum%2 == 0) cnt1 = 1;
		else cnt2 = 1;
	}
	if (cnt1 && cnt2) cout << 2;
	else if (cnt1) cout << 0;
	else cout << 1;
	return 0;
}