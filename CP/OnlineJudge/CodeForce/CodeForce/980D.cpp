// Source: https://codeforces.com/contest/980/problem/D

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second

const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

int f[N];
bool isOdd[N];
bool isPos[N];
int factor[N];
int ans[N];
int a[N];
int mp1[N] , mp2[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    set<int> s;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        int tm = abs(a[i]);
        factor[i] = 1;
        if (a[i] >= 0) isPos[i] = true;
        for (int j = 2 ; j * j <= tm ; j++) {
            if (tm % j == 0) {
                int cnt = 0;
                while (tm % j == 0) {
                    tm /= j;
                    cnt++;
                }
                if (cnt % 2) {
                    factor[i] *= j;
                    isOdd[i] = true;
                }
            }
        }
        if (tm > 1) {
            factor[i] *= tm;
            isOdd[i] = true;
        }
        s.insert(factor[i]);
    }    
    vector<int> v(s.begin() , s.end());
    map<int , int> mp;
    for (int i = 0 ; i < v.size() ;i ++) mp[v[i]] = i;
    for (int i = 1 ; i <= n ; i++) {
        factor[i] = mp[factor[i]];
    }
    for (int i = 1 ; i <= n ; i++) {
       
        int groups = 0;
        bool gr_1 = false; // nhóm chỉ gồm thằng các mũ chẵn , 1 và 0 , >= 0
        bool gr_2 = false; // // nhóm chỉ gồm thằng các mũ chẵn , 1 và 0 , < 0
        for (int j = i ; j >= 1; j--) {
            if (isOdd[j]) {
                if (!mp1[factor[j]] && isPos[j]) {
                    mp1[factor[j]]++; 
                    groups++;
                }
                if (!mp2[factor[j]] && !isPos[j]) {
                    mp2[factor[j]]++;
                    groups++;
                }
            }
            else {
                if (isPos[j] && a[j] > 0) {
                    if (!gr_1) {
                        gr_1 = true;
                        groups++;
                    }
                }
                else if (!isPos[j]) {
                    if (!gr_2) {
                        gr_2 = true; 
                        groups++;
                    }
                }
            }
            ans[max(1 , groups)]++;
        }   
        for (int j = i ; j >= 1 ; j--) {
            mp1[factor[j]] = 0; 
            mp2[factor[j]] = 0;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}