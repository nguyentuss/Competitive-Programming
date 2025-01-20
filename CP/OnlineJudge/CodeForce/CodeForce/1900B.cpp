//source:: 
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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

bool condition(int a , int b , int c) {
    int tmp = min(b , c);
    a += tmp;
    b -= tmp;
    c -= tmp;
    //cerr << a << " " << b << " " << c << '\n';
    if (b == 0 && c == 0) return true; 
    if (b < c) swap(b , c);
    if (b % 2 == 1) return false;
    if (b % 2 == 0) {
        if (a - b/2 >= 0) return true;
    }
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int a , b , c; cin >> a >> b >> c;
        cout << condition(a , b , c) << " " << condition(b , a , c) << " " << condition(c , a , b) << '\n';        
        //cout << condition(1 , 1 , 1);
    }
    return 0;
}