#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 27;
const int MOD = 1e9 + 7;

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
/*
nhan xet dap an bai toan chi <= 20 -> dao nhan sang i
goi f[i][mask] : la tổng trọng số khi thêm vào lần đi thang thứ i (dk ràng <= W) 
toan xét tới mask (bit 1 là đã thử r , bit 0 là chưa thử)

*/

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        int n , W; cin >> n >> W;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        vector<pair<int , int>> f(1 << n , {n + 1 , W + 1});
        f[0] = ii(1 , 0);
        for (int mask = 0 ; mask < (1 << n) ; mask++) {
            for (int i = 0 ; i < n ; i ++) {
                if (mask & (1 << i)) {
                    auto prev = f[mask ^ (1 << i)];
                    int weight = prev.se; 
                    if (weight + a[i] <= W) {
                        f[mask] = min(f[mask] , {prev.fi , prev.se + a[i]});
                    }
                    f[mask] = min(f[mask] , {prev.fi + 1 , a[i]});
                }
            }
        }
        cout << f[(1 << n) - 1].fi;
    }
    return 0;
}