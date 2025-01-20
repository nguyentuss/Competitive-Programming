#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    vector<int> a(n + 2 , 0);
    vector<vector<int>> f(n + 2 , vector<int>(4 , 0));
    for (int i = 1 ; i <= n ; i++) {
        if (s[i] == 'A') a[i] = 0;
        if (s[i] == 'C') a[i] = 1;
        if (s[i] == 'G') a[i] = 2;
        if (s[i] == 'T') a[i] = 3;
    }
    for (int i = n ; i >= 1 ; i--) {
        for (int status = 0 ; status <= 3 ; status ++) {
            f[i][status] = f[i + 1][status] + (status == a[i]);
        }
    }
    int l = 1 , r = 1;
    string ans = "";
    bool kt = false;
    while (l <= n) {
        if (f[l][0] && f[l][1] && f[l][2] && f[l][3]) {
            int cnt1 , cnt2 , cnt3 , cnt4;
            cnt1 = cnt2 = cnt3 = cnt4 = 0;
            for (r = l ; r <= n ; r++) {
                cnt1 += (a[r] == 0);
                cnt2 += (a[r] == 1);
                cnt3 += (a[r] == 2);
                cnt4 += (a[r] == 3);
                if (cnt1 && cnt2 && cnt3 && cnt4) break;   
            }       
            cerr << r << " ";
            ans += s[r];
            l = r + 1;
        }
        else {
            kt = true;
            if (!f[l][0]) ans += 'A';
            else if (!f[l][1]) ans += 'C';
            else if (!f[l][2]) ans += 'G';
            else if (!f[l][3]) ans += 'T';
            break;
        }
    }
    cout << ans;
    if (!kt) cout << 'A';
    return 0;
}