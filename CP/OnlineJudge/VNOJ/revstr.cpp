#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3e5 + 7)
#define int long long
#pragma GCC optimize("Ofast")

vector<char> pos[MAX_N];
int L[MAX_N];

signed main() {    
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    s = '0' + s;
    int len = s.size();
    int n; cin >> n;
    vector<int> f(s.size() + 2 , 0);
    for (int i = 1 ; i <= n ;i ++) {
        int pos; cin>> pos;
        ++f[pos];
        --f[len - pos + 1];
    }
    for (int i = 1 ; i < s.size() ; i++) {
        f[i] += f[i - 1];
        pos[f[i]].push_back(s[i]);
        //cout << f[i] << " ";
    }
    for (int i = 1 ; i <= n ; i++) {
        if (i % 2 && pos[i].size()) {
            reverse(pos[i].begin() , pos[i].end());
        }
    }
    for (int i = 1 ; i < s.size() ; i++) {
        cout << pos[f[i]][L[f[i]]++];
    }

    return 0;
}