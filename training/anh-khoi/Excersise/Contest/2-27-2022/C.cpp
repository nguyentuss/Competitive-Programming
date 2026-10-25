#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N] , t[MAX_N];

int retrieve(int x) {
	int ans = 0;
	for (; x<MAX_N; x+=x&-x) ans += t[x];
	return ans;
}

void update(int x) {
	for (; x>0; x-=x&-x) t[x]++;
}

int cnt[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    set<int> s;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    vector<int> number(s.begin() , s.end());
    for (int i = 1 ; i <= n ;i ++) {
        a[i] = lower_bound(number.begin() , number.end() , a[i]) - number.begin() + 1;
    }
    int res = 0;
    for (int i = 1 ; i <= n ;i ++) {
        res += retrieve(a[i] + 1);
        update(a[i]);
    }
    cout << res;
    return 0;
}