#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 4e5 + 7;
const int MOD = 1e9 + 7;

vector<ii> ans;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , d , k; cin >> n >> d >> k;
    if (k == 1) {
        if (d == 1) {
            if (n == 2) {
                cout << "YES" << '\n';
                cout << 1 << " " << 2 << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
        else {
            cout << "NO" << '\n';
        }
        
        return 0;
    }
    for (int i = 1; i <= d ; i++) {
        ans.push_back(ii(i , i + 1));
    }
    int nodes = ans.size() + 1;
    if (nodes > n) {
        cout << "NO";
        return 0;
    }
    bool ff = false;
    queue<ii> q;
    for (int i = 2 ; i <= d ;i ++) {
        int h = min(i - 1, d - i + 1);
        q.push(ii(i , 0));
        while (!q.empty()) {
            int u = q.front().fi; 
            int he = q.front().se;
            q.pop();
            if (he == h) continue;
            for (int j = 0 ; j < (he == 0 ? (k - 2) : (k - 1)) ; j++) {
                if (nodes == n) {
                    ff = true;
                    break;
                }
                ans.push_back(ii(u , ++nodes));
                q.push(ii(nodes , he + 1));
            }
            if (ff) break;
        }
        //cerr << nodes << '\n';
        if (ff) break;
    }
    cerr << ans.size();
    if (ans.size() == (n - 1)) {
        cout << "YES" << '\n';
        for (auto E : ans) {
            cout << E.fi << " " << E.se << '\n';
        }
    }
    else {
        cout << "NO";
    }


    return 0;
}