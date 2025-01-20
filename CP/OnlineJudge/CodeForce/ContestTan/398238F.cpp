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

int f[N] , ck[N];

void eratosthenes() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 2 ; i < N ; i++) {
        for (int j = 1 ; j <= i && i*j < N; j++) {
            f[i * j] = min(f[i * j] , f[i] + 1);
            f[i * j + 1] = min(f[i * j + 1] , f[i * j] + 1); 
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1 ; i < N ;i ++) {
        f[i] = inf;
    }   
    eratosthenes();
    int q; cin >> q;
    for (int i = 0 ; i < q; i++) {
        int x; cin >> x;
        cout << f[x] << '\n';
    }
    return 0;
}
