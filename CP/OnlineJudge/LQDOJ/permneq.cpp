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

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int x = 1;
    for (int i = 1 ; i <= n/2 + n%2 ; i++) {
        cout << x << " ";
        x += 2;
    }
    if (n % 2 == 0) {
        x = n;
    }
    else x = n - 1;
    for (int i = 1 ; i <= n/2 ; i++) {
        cout << x << " ";
        x -= 2;
    }   
    return 0;
}