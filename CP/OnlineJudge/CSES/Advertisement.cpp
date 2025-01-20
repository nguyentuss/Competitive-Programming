#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e5 + 7)

int a[MAX_N];
int L[MAX_N] , R[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    deque<int> dq;
    dq.push_back(0);
    for (int i = 1 ; i <= n ; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        } 
        L[i] = dq.back() + 1;
        dq.push_back(i);
    }
    while (!dq.empty()) dq.pop_back();
    dq.push_back(n + 1);
    for (int i = n ; i >= 1 ; i--) {
        while (!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        R[i] = dq.back() - 1;
        dq.push_back(i);
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        ans = max(ans , (R[i] - L[i] + 1)*a[i]);
       // cout << L[i] << " " << R[i] << '\n';
    }
    cout << ans;
    return 0;
}