#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

char a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n , k; cin >> n >> k;
        vector<ii> v;
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        v.push_back(ii(0 , 0));
        a[n + 1] = '3';
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++) {
            cnt++;
            if (a[i] != a[i + 1]) {
                v.push_back(ii(cnt , a[i] - '0'));
                cnt = 0;
            }
        }

    }
    return 0;
}