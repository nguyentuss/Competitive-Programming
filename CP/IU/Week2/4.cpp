#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
	int sum = 1;
	for (int i = 2 ; i * i <= n ; i++) {
		if (n % i == 0) {
			sum += i;
			if (i != (n/i)) {
				sum += n/i;
			}
		}
	}
	if (n == sum) cout << "YES";
	else cout << "NO";
    return 0;
}
