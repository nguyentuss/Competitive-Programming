#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int base = 31;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        vector<int> POW(n + 1 , 0); 
        POW[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            POW[i] = POW[i - 1]*base;
        }
        vector<int> hashA(n + 1 , 0);
        for (int i = 1 ; i <= n ; i++) {
            hashA[i] = hashA[i - 1]*base + s[i] - 'a' + 1;
        }
        auto get_hash = [&](int l , int r) -> int {
            return (hashA[r] - hashA[l - 1]*POW[r - l + 1]);
        };
        for (int i = 1 ; i <= n ; i++) {
            int id = i;
            bool ok = true;
            while (id < n) {
                int len = min(i , n - id);
                ok &= get_hash(1 , len) == get_hash(id + 1 , id + len);
                id += len;
            }
            if (ok) {
                cout << i << " ";
            }
        }
    }
    return 0;
}