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
    int n , k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    map<int , int> mp;
    int diff = 0;
    int l = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (mp[a[i]] == 0) {
            diff++;
        }
        mp[a[i]]++;
        while (l <= i && diff > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) {
                diff--; 
            }
            l++;
        } 
        ans = ans + (i - l + 1);
    }
    cout << ans;
    return 0;
}