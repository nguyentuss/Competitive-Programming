#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) x.size()
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
vector<int> adj[N];
int f[N];
int up[N];

//#pragma once

//const ll mod = 1000000007; // faster if const

vector<int> pref[N];
vector<int> suf[N];

void DFS(int u , int father) {
    f[u] = 1;
    int res = 1;
    for (int i = 0 ; i < sz(adj[u]) ; i++) {
        int v = adj[u][i];
        pref[u].push_back(0); suf[u].push_back(0);
        if (v != father) {
                DFS(v , u);
                pref[u][i] = res;
                (res *= (f[v] + 1))%=mod;
                (f[u] *= (f[v] + 1))%=mod;
        }
    }
    res = 1;
    for (int i = sz(adj[u]) - 1 ; i >= 0 ; i--) {
        int v = adj[u][i];
        if (v != father) {
            suf[u][i] = res;
            (res *= (f[v] + 1))%=mod;
        }
    }
    //cout << tmp << " " << pw[edge] << '\n';
}

void DFS1(int u , int father) {
    for (int i = 0 ; i < sz(adj[u]) ; i++) {
        int v = adj[u][i];
        if (v != father) {
            up[v] = ((((up[u] * suf[u][i])%mod * pref[u][i])%mod)%mod + 1)%mod;
            DFS1(v , u);
        }
    }
}

signed main() {
        ios_base::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);
        int n; cin >> n;
        /*
        8
1 1 2 2 3 3 5
35 36 32 19 26 17 17 14
11
1 1 2 2 3 3 5 4 9 9
95 108 80 95 74 41 41 38 80 41 41
        */
        for (int i = 1 ; i < n ;i ++) {
                int x; cin >> x;
                x--;
                adj[i].push_back(x);
                adj[x].push_back(i);
        }
        DFS(0 , -1);
        up[0] = 1;
        DFS1(0 , -1);
        for (int i = 0 ; i < n ;i ++) {
                //int c = (f[0] - f[i] + 1 + mod)%mod;
                //int d = f[i]%mod;
                //cerr << up[i] << " " << f[i] << '\n';
                cout << (up[i] * f[i])%mod << " ";
        }
        return 0;
}