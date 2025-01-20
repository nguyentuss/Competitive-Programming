#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e4 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n + 1); 
    int sum = 0;
    for (int i = 0 ; i < n ;i ++) {
        cin >> a[i];
        sum += a[i];
    }
    int val = sum / n;
    int total_move = 0;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] >= val) {
            int last = a[i] - val;
            a[i + 1] += last;
            a[i] = val;
            total_move += last;
        }
        else {
            int last = val - a[i];
            a[i + 1] -= last;
            a[i] = val;
            total_move += last;
        }
    }
    cout << total_move;
    return 0;
}