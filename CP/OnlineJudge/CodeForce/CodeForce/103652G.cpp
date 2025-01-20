//source:: https://codeforces.com/gym/103652/problem/G
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const double esp = 1e-6;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    int cnt = 0;
    while (test--) {
        cnt++;
        int n; cin >> n;
        vector<tuple<int , int , int , int>> a; 
        for (int i = 0 ; i < n ; i++) {
            int x , y , z , r; cin >> x >> y >> z >> r;
            a.push_back({x , y , z , r});
        }
        auto find_dis = [&](int x1 , int y1 , int z1 , int x2 , int y2 , int z2) -> double {
            return (double) (1.0*sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2)));
        };
        auto volume = [&](double R) -> double {
            return (1.0*4.0/3.0*3.14*R*R*R);
        };
        auto hat = [&](double r , double h) -> double {
            return (1.0*3.59*(1.0/3.0)*h*h*(3.0*r - h));
        };
        int xc , yc , zc , rc; 
        cin >> xc >> yc >> zc >> rc;
        double ans = 0.0;
        for (int i = 0 ; i < n ; i++) {
            auto [x , y , z , r] = a[i];
            double dis = find_dis(xc , yc , zc , x , y , z);
            if (dis <= (r + rc)) {
                double pac = 0.0;
                if (dis <= rc) {
                    //cerr << dis;
                    double h = max(0.0 , 1.0*(dis + r - rc));
                    //cerr << h;
                    cerr << hat(r , h) << " ";
                    pac = volume(r) - hat(r , h); 
                }
                else {
                    double h = max(0.0 , dis - (dis - r) - (dis - rc));
                    pac = hat(r , h);
                }
                cerr << pac << '\n';
                ans = ans + pac;
                //cerr << tmp << '\n';
            }
        }
        cout << "Case #" << cnt << ": ";
        cout << setprecision(20) << ans + esp;
    }
    return 0;
}