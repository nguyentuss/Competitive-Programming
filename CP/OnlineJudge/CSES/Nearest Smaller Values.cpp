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


main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1 ; i <= n ; i++) {
        while (dq.size() && a[dq.back()] >= a[i]) 
            dq.pop_back();
        cout << dq.back() << " ";
        dq.push_back(i);
    }
    return 0;
}