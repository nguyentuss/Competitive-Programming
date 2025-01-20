#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int a[N];
int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    deque<int> dq_max , dq_min;
    dq_max.push_back(1);
    dq_min.push_back(1);
    f[1] = 0; 
    deque<int>::iterator it;
    for (int i = 2 ; i <= n ; i++) {
        f[i] = f[i - 1] + 1;
        // cout << i << ":";
        // for (it = dq_min.begin(); it != dq_min.end(); ++it)
        //     cout << a[*it] << " ";
        // cout << '\n';
        bool stat1 = false , stat2 = false;
        while (dq_min.size() && a[dq_min.back()] <= a[i]) {
            f[i] = min(f[i] , f[dq_min.back()] + 1); 
            if (a[i] == a[dq_min.back()]) stat1 = true;
            dq_min.pop_back();
        }
        while (dq_max.size() && a[dq_max.back()] >= a[i]) {
            f[i] = min(f[i] , f[dq_max.back()] + 1); 
            if (a[i] == a[dq_max.back()]) stat2 = true;
            dq_max.pop_back(); 
        }
        if (dq_min.size() && !stat1) {
            f[i] = min(f[i] , f[dq_min.back()] + 1);
        }
        if (dq_max.size() && !stat2) {
            f[i] = min(f[i] , f[dq_max.back()] + 1);
        }
        dq_min.push_back(i); 
        dq_max.push_back(i); 
        //for (auto x : dq_max) cout << x << '\n';
    }
    //for (int i = 1 ; i <= n ; i++) cout << f[i] << " " ;
    cout << f[n];
}