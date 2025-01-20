#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

char a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> pos1;
        vector<int> pos2;
        int ans = 0;
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
            if (a[i] == 'L') {
                ans = ans + i - 1;
            }
            else {
                ans = ans + (n - i);
            }
        }
        priority_queue<ii , vector<ii> , greater<ii>> pq;
        for (int i = 1 ; i <= n ; i++) {
            if (a[i] == 'L') pq.push(ii(i , 1));
        }
        for (int i = n ; i >= 1 ; i--) {
            if (a[i] == 'R') pq.push(ii(n - i + 1 , 0));
        }
        int cnt = 0;
        vector<int> res;
        while (!pq.empty()) {
            int pos = pq.top().fi;
            int status = pq.top().se;
            pq.pop();
            //cerr << pos << " " << status << '\n';
            cnt++;
            if (status == 1) {
                ans = ans - (pos - 1);
                ans = ans + (n - pos);
            }
            else {
                int npos = n - pos + 1;
                ans = ans - (n - npos);
                ans = ans + (npos - 1);
            }
            res.push_back(ans);
        }
        if (res.size() == 0) {
            for (int i = 0 ; i < n ; i++) {
                cout << ans << " ";
            }
            cout << '\n';
            continue;;
        }
        int maxi = 0; 
        for (auto x : res) {
            maxi = max(maxi , x);
            cout << maxi << " ";
        }
        int xx = maxi;
        for (int i = 0 ; i < (n - res.size()) ; i++) {
            cout << xx << " ";
        }
        cout << '\n';
    }
    return 0;
}