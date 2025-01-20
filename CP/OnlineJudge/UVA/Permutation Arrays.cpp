//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;
string x[5000];
int idx[5000];
int test; 

void solve() {
    getchar();
    string line;
    getline(cin , line);
    //cout << line << " ";
    stringstream ss;
    ss << line;
    int n = 0 , m = 0;
    while (ss >> idx[n]) {
        //cout << idx[n] << " ";
        n++;
    }
    getline(cin , line); 
    ss.clear();
    ss << line; 
    while (ss >> x[idx[m]]) {
        m++;
    }
    for (int i = 1 ; i <= m ; i++) {
        cout << x[i] << endl;
    }
    if (test) {
        puts("");
    }
    //cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    test = 1;
    scanf("%d",&test);
    getchar();
    while (test--) {
        solve();
    }

}