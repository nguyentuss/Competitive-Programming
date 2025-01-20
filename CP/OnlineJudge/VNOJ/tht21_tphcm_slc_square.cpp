#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e6 + 7)
#define inf (int) (1e9 + 7)

vector<int> ph(int x) {
    vector<int> cnt(MAX_N , 0);
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                cnt[i]++;
            }
        }
    }
    if (x > 1) cnt[x] ++; 
    return cnt;
}

int POW(int a , int n) {    
    if (n == 0) return 1;
    int child = POW(a , n / 2);
    if (n % 2 == 1) return child*child*a;
    else return child*child;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int a , b , c; cin >> a >> b >> c;
    vector<int> cnt_a = ph(a);
    vector<int> cnt_b = ph(b);
    vector<int> cnt_c = ph(c);
    int ans = 1;
    for (int i = 1 ; i <= max({a , b , c}) ; i++) {
        int x = max({cnt_a[i] , cnt_b[i] , cnt_c[i]});
        if (x != 0) {
            ans *= POW(i , (x + 1)/2);
        }
    }
    cout << ans;
    return 0;
}