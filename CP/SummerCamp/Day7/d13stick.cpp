#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e9 + 7;
const int MOD = 1e9 + 7;


struct seg {
    int val , type1 , type2;
};

vector<seg> adj;
int tt[4];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int a , b , c , d; cin >> a >> b >> c >> d;
    tt[0] = a , tt[1] = b , tt[2] = c , tt[3] = d;
    adj.push_back({a , 0 , 1});
    adj.push_back({b , 1 , 1});
    adj.push_back({c , 2 , 1});
    adj.push_back({d , 3 , 1});
    int ans = 0;
    for (int i = 0 ;i < 4; i++) {
        ans = max(ans , adj[i].val/2);
    }
    for (int i = 0 ; i < 4 ; i++) {
        if (tt[i] == 1) continue;
        int x = tt[i]/2; 
        adj.push_back({x , i , 2});
        adj.push_back({x + tt[i]%2 , i , 2});
    }
    cerr << adj.size();
    int n = adj.size();
    for (int i = 0 ; i < (int) (n - 3) ; i++) {
        for (int j = i ; j < (int) (n - 2) ; j++) {
            for (int k = j + 1 ; k < (int) (n - 1) ; k++) {
                for (int h = k + 1 ; h < (int)n ; h++) {
                    int a_1 = adj[i].val , b_1 = adj[j].val , c_1 = adj[k].val , d_1 = adj[h].val;
                    vector<vector<int>> dem(4 , vector<int> (4 , 0));
                    int a_2 = adj[i].type1 , b_2 = adj[j].type1 , c_2 = adj[k].type1 , d_2 = adj[h].type1;
                    int a_3 = adj[i].type2 , b_3 = adj[j].type2 , c_3 = adj[k].type2 , d_3 = adj[h].type2;
                    dem[a_2][a_3]++ , dem[b_2][b_3]++ , dem[c_2][c_3]++, dem[d_2][d_3]++;
                    if ((dem[0][1] && dem[0][2]) || (dem[2][1] && dem[2][2]) || (dem[3][1] && dem[3][2]) || (dem[1][1] && dem[1][2])) {
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(a_1);
                    tmp.push_back(b_1);
                    tmp.push_back(c_1);
                    tmp.push_back(d_1);
                    sort(tmp.begin() , tmp.end());
                    for (auto z : tmp) {
                        cerr << z << " ";
                    }
                    cerr << tmp[0] << " " << b_1 << " " << c_1 << " " << d_1 << " " << ans << '\n';
                    ans = max(ans , tmp[0]*tmp[2]);
                    cerr << ans << " ";
                    cerr << '\n';
                    //cerr << i << " " << j << " " << k << " " << h << '\n';
                }
            }
        }
    }
    cout << ans;
    return 0;
}