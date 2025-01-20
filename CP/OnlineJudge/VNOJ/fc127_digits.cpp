#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (307)

int f[MAX_N];
string curr;

string findsmallest(int m , int s) {
	string ans(m , '0');
	for (int i = m - 1 ; i >= 0 ; i--) {
		if (s >= 9) {
			ans[i] = '9';
			s -= 9;
		}
		else {
			char c = (char)s + '0';
			ans[i] = c;
			s = 0;
		}
	}
	return ans;
}

string findMin(int x, string y)
{
    int n = y.size();
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = y[i] - '0';
        if (i > 0)
            p[i] += p[i - 1];
    }
    for (int i = n - 1, k = 0;; i--, k++) {
        int d = 0;
 
        if (i >= 0)
            d = y[i] - '0';

        for (int j = d + 1; j <= 9; j++) {
 
            int r = (i > 0) * p[i - 1] + j;
 
            if (x - r >= 0 and x - r <= 9 * k) {
 
                string suf = findsmallest(k, x - r);
 
                string pre = "";
                if (i > 0)
                    pre = y.substr(0, i);
                char cur = (char)j + '0';
                pre += cur;
                return pre + suf;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("fc127_digits.inp","r",stdin);
	//freopen("fc127_digits.out","w",stdout);
	int n; cin >> n;
	cin >> f[1];
	curr += '0';
	curr = findMin(f[1] , curr);
	cout << curr << '\n';
	for (int i = 2 ; i <= n ; i++) {
		cin >> f[i];
		curr = findMin(f[i] , curr);
		cout << curr << '\n';
	}
	return 0;
}