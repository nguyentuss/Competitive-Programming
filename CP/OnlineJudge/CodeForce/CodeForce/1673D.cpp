//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
vector<int> find_divisor(int x) {
    vector<int> a;
    for (int i = 2 ; i * i <= x ; i++) {
        if (!(x % i)) {
            if (x/i == i) {
                a.push_back(i);
            }
            else {
                a.push_back(i);
                a.push_back(x/i);
            }
        }
    }
    a.push_back(x);
    return a;
}

vector<int> find_factor(int x) {
    vector<int> a;
    a.push_back(1);
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                a.push_back(i);
            }
        }
    }
    if (x > 1) a.push_back(x); 
    return a;
}

int lcm(int a , int b) {
    return (a*b)/__gcd(a , b);
}

void solve() {
    int b , q , y; cin >> b >> q >> y;
    int c , r , z; cin >> c >> r >> z;
    int e = b+q*(y-1);
    int f = c+r*(z-1);
    if(c<b || c>e || f<b || f>e || r%q!=0 || (c-b)%q!=0)
        cout << 0 << '\n';
    else if(c-r<b || f+r>e)
        cout << -1 << '\n';
    else {
        int ans = 0;
        //cerr << "YES";
        for (int i = 1 ; i * i <= r ; i++) {
            if (r % i == 0) {
                if (lcm(i , q) == r) {
                    ans = (ans + (r/i)*(r/i)%MOD)%MOD; 
                }
                if (r / i != i && lcm(r/i , q) == r) {
                    ans = (ans + i*i%MOD)%MOD; 
                }
            }
        }
        cout << ans << '\n';
    }
}

main() {
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}