#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

struct characters {
	int chA , chV , chC;
};

string s;
characters f[MAX_N];
int n , k;
int res = INT_MAX;

bool check(int l , int r) {
	int chA = f[r].chA - f[l].chA;
	int chV = f[r].chV - f[l].chV;
	int chC = f[r].chC - f[l].chC;
	if (chA >= k && chV >= k && chC >= k) {
		res = min(res , chA + chV + chC - 3*k);
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);	cout.tie(NULL);
	cin >> k;
	cin >> s;
	s = '0' + s , n = s.size();
	for (int i = 1 ; i <= n ;i ++) {
		f[i].chA = f[i - 1].chA + (s[i] == 'A'?1:0);
		f[i].chV = f[i - 1].chV + (s[i] == 'V'?1:0);
		f[i].chC = f[i - 1].chC + (s[i] == 'C'?1:0);
	}
	for (int i = 1 ; i <= n ;i ++) {
		if (f[i].chA < k || f[i].chC < k || f[i].chV < k) 
			continue;
		int l = 0 , r = i;
		while (l <= r) {
			int mid = (l + r)/2;
			if (check(mid , i)) {
				l = mid + 1;
			} 
			else r = mid - 1;
		}
	}
	cout << res;
	return 0;
}