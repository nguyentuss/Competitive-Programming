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
const int VAL = 1e6 + 7;

int mp[VAL];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    set<int> s;
    for (int i = 0 ; i < n ;i ++) {
        int x; cin >> x;    
        mp[x]++;
        s.insert(x);
    }
    vector<int> a(s.begin() , s.end()); 
    reverse(a.begin() , a.end()); 
    int pq = 0; 
    // pq chi danh cho nhung thang nao` last == 2
    int ans = 0;
    for (auto x : a) {
        if (pq != 0 && mp[x] >= 2) {
            ans = ans + pq*x;
            mp[x] -= 2;
            pq = 0;
        }
        int last = mp[x]%4;
        ans = ans + ((mp[x] - last)/4)*x*x;
        int mm = last%2;
        if (mm) mp[x - 1]++;
        last -= mm;
        if (last == 2) pq = x;
        //cout << ans << " ";
    }
    cout << ans;
    return 0;
}   