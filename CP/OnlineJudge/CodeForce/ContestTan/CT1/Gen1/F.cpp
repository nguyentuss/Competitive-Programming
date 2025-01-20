#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

multiset<int> lo , hi;
int a[N];
int n , d;

void ins(int x) {
    int val = *lo.rbegin();
    if (x > val) {
        hi.insert(x);
        if (hi.size() > (d/2)) {
            lo.insert(*hi.begin());
            hi.erase(hi.find(*hi.begin()));
        }
    }
    else {
        lo.insert(x);
        if (lo.size() > ((d + 1)/2)) {
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }
    }
}

void remov(int x) {
    if (hi.find(x) != hi.end()) hi.erase(hi.find(x));
    else lo.erase(lo.find(x));
    if (lo.empty()) {
        lo.insert(*hi.begin());
        hi.erase(hi.find(*hi.begin()));
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    lo.insert(a[1]);
    for (int i = 2 ; i <= d ; i++) {
        ins(a[i]);
    }
    int ans = 0;
    for (int i = d + 1 ; i <= n ;i ++) {
        int mid = *lo.rbegin();
        if (a[i] >= 2*mid) ans++;
        if (d == 1) {
            ins(a[i]);
            remov(a[i - d]);
        }
        else {
            remov(a[i - d]);
            ins(a[i]);
        }
    }
    cout << ans;
    return 0;
}
