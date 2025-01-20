#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;


int f[20][10][3];
//goi f[i][num][status] la so cach khi tai vi tri i co so la num

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        auto calc = [&](string s) -> int {
            //reverse(s.begin() , s.end());
            memset(f , 0 , sizeof(f));
            for (int num = 1 ; num <= 9 ; num++) {
                int status;
                if (num < s[0] - '0') status = 0;
                if (num == s[0] - '0') status = 1; 
                if (num > s[0] - '0') status = 2;
                f[1][num][status] ++;
            }
            int n = s.size();
            for (int i = 1 ; i < n ; i++) {
                for (int j = 0 ; j <= 9 ; j++) {
                    for (int status = 0 ; status <= 2 ; status ++) {
                        if (f[i][j][status] == 0) continue;
                        for (int num = 0 ; num <= 9 ; num++) {
                            if (num == j) continue;
                            int newstatus = status;
                            if (status == 1) {
                                if (num < s[i] - '0') newstatus = 0;
                                if (num > s[i] - '0') newstatus = 2;
                            }
                            f[i + 1][num][newstatus] += f[i][j][status];
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 1 ; i <= n ; i++) {
                for (int j = 0 ; j <= 9 ; j++) {
                    for (int status = 0 ; status <= (i < n ? 2 : 1) ; status++) {
                        ans += f[i][j][status];
                    }
                }
            }
            return ans;
        };
        int a , b; cin >> a >> b;
        cout << calc(to_string(b)) - calc(to_string(max(0ll , a - 1))) + (a == 0 ? 1 : 0); 
    }  
    return 0;
}