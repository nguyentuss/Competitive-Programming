#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 4e3 + 1e2 + 7;;
const int MOD = 1e9 + 7;

vector<int> adj[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;    
    vector<int> a(n) , b(n);
    for (int i = 0; i < n ;i ++) cin >> a[i];
    for (int i = 0; i < n ;i ++) cin >> b[i];
    if (b[1] != a[1]) {
        cout << -1; 
        return 0;
    }
    cout << 2*(n - 1) - 1 << '\n';
    for (int i = 0 ; i < (n - 1) ; i++) {
        cout << b[i] << " " << b[i + 1] << '\n';
    }
    for (int i = 2 ; i < n ; i++) {
        cout << 1 << " " << a[i] << '\n';
    }
    return 0;
}