#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 5e4 + 7;
const int MOD = 1e9 + 7;

map<int , int> mp;
set<int> s;

void calc(int x) {

    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            s.insert(i);
        }
    }
    if (x > 1) {
        s.insert(x);    
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n ; cin >> n;
    vector<int> a(n) , b(n);
    for (int i = 0 ; i < n ; i++) {
        int x , y; cin >> x >> y;
        a[i] = x , b[i] = y;
    }
    calc(a[0]); calc(b[0]); 
    vector<int> factor(s.begin() , s.end());
    map<int , int> mp;
    for (auto x : factor) {
        mp[x]++;
    }
    for (int i = 1 ; i < n ;i ++) {
        for (auto x : factor) {
            if (a[i] % x == 0 || b[i] % x == 0) {
                mp[x] ++;
            }
        }
    }
    for (auto it : mp) {
        if (it.second == n) {
            cout << it.first;
            return 0;
        }
    }
    cout << -1;
    return 0;
}