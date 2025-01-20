#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 107;
const int MOD = 1e9 + 7;

tuple<int , int , int , int>trace[N][N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        string s; cin >> s;
        string t; cin >> t;
        string virus; cin >> virus; 
        int n = s.size(); 
        int m = t.size();
        int h = virus.size();
        vector<vector<vector<int>>> f(n + 1 , vector<vector<int>> (m + 1 , vector<int> (h + 1 , -inf)));
        auto prefix_func = [&](string s) -> vector<int> {
            int j = 0; 
            vector<int> pi(h);
            for (int i = 1 ; i < h ; i++) {
                j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1]; 
                }
                if (s[i] == s[j]) j++;
                pi[i] = j;
            }
            return pi;
        };
        
        vector<int> pi = prefix_func(virus);
        for (int i = 0 ; i <= n ; i++) {
            for (int j = 0 ; j <= m ; j++){
                if (i == 0 || j == 0) f[i][j][0] = 0;
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                for (int k = 0 ; k <= h ; k++) {
                    if (f[i][j][k] < f[i][j - 1][k]) {
                        f[i][j][k] = f[i][j - 1][k]; 
                        trace[i][j][k] = {i , j - 1 , k , 0}; 
                    }
                    if (f[i][j][k] < f[i - 1][j][k]) {
                        f[i][j][k] = f[i - 1][j][k]; 
                        trace[i][j][k] = {i - 1, j, k , 0}; 
                    }
                    if (s[i - 1] == t[j - 1]) {
                        int tm = k;
                        while (tm > 0 && s[i - 1] != virus[tm]) {
                            tm = pi[tm - 1];
                        }
                        if (s[i - 1] == virus[tm]) {
                            tm ++;
                        }
                        if (tm < h && f[i][j][tm] < (f[i - 1][j - 1][k] + 1)) {
                            f[i][j][tm] = f[i - 1][j - 1][k] + 1; 
                            trace[i][j][tm] = {i - 1, j - 1 , k , 1};
                        }
                    }  
                }
            }
        }
        int ans = 0;
        int k = 0;
        for (int i = 0 ; i < h ; i++) {
            if (ans < f[n][m][i]) {
                ans = f[n][m][i];
                k = i;
            }
            //ans = max(ans , f[n][m][i]);
        }
        //cout << ans;
        if (!ans) return cout << 0,0;
        int x = n , y = m , z = k;
        string tr;
        int px , py , pz , status;
        //tie(px , py , pz , status) = trace[8][1][1];
        //cout << px << " " << py << " " << pz << " " << status;
        while (true) {
            tie(px , py , pz , status) = trace[x][y][z];
            if (status == 1) {
                tr.push_back(s[x - 1]);
                //cerr << s[x - 1];
                if (tr.size() == ans) break;
            }
            
            x = px , y = py , z = pz;
        }
        reverse(tr.begin() , tr.end());
        cout << tr;
    }
    return 0;
}