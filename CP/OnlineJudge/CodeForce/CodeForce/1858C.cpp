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
const int MOD = 19 + 7;

int a[N];
int check[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) check[i] = false;
        int l = 2;
        a[1] = 1;
        for (int i = 2 ; i <= n ; i++) {
            int x = i; 
            if (check[x]) continue; 
            while (x <= n) {
                a[l++] = x; 
                check[x] = true;
                x *= 2;
            }
        }
        for (int i = 1; i <= n ; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}