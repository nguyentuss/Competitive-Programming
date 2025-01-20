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
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 17 ;
const int MOD = 1e9 + 7;

int POW[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n;
        POW[0] = 1;
        for (int i = 1 ; i < 13 ; i++) {
            POW[i] = POW[i - 1] * i;
        }
        while (cin >> n && n != 0) {
            int ans = 0;
            vector<int> num(10);
            vector<int> a(n);
            bool status = 0;
            int sum = 0;
            for (int i = 0 ; i < n ; i++) {
                int x; cin >> a[i];
                num[a[i]]++;
                sum += a[i];
            }
            int C = POW[n];
            for (int c = 0 ; c <= 9 ; c++) {
                C /= POW[num[c]];
            }  
            int tm = 0;
            int d10 = 1;
            for (int i = 0 ; i < n ; i++) {
                tm += d10;
                d10 *= 10;
            }
            //C /= n;
            ans = (C * tm * sum) / n;
            cout << ans << '\n';
        }
    }
    return 0;
}