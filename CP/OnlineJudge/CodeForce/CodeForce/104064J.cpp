//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        map<int , bool> mp;
        int n; cin >> n;
        vector<int> a;
        for (int i = 0 ; i < n ; i++) {
            int x , y; cin >> x >> y;
            a.push_back(y);
        }
        a.push_back(a[0]);
        for (int i = 0 ; i < n ; i++) {
            int u = a[i];
            int v = a[i + 1];
            if (u > v) swap(u , v); 
            int dis1 = v - u;
            int dis2 = 360 - (v - u);
            if (dis1 < dis2) {
                for (int j = u ; j <= v ; j++) {
                    mp[j] = true;
                }
            }
            else {
                for (int j = -180 ; j <= u ; j++) {
                    mp[j] = true;
                }
                for (int j = v ; j <= 180 ; j++) {
                    mp[j] = true;
                }
            }
        
        }
        bool status = 0;
        int l = -inf , r = -inf;
        for (int i = -180 ; i < 180 ; i++) {
            if (mp[i] == false) {
                if (!status) {
                    l = i;
                    status = 1;
                } 
            }
            if (mp[i] == true && status) {
                    r = i - 1;
                    break;
            }
        }
        if (l == -inf && r == -inf) {
            cout << "yes";
        }
        else {
            cout << "no ";
            cout << fixed << setprecision(1) << (double) (l + r)/2.0 << '\n';
        }
        cout << l << " " << r;
    }
    return 0;
}