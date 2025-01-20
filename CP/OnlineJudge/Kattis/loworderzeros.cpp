//source:: https://open.kattis.com/problems/loworderzeros?tab=metadata
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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        vector<int> cnt_2(N , 0);
        vector<int> cnt_5(N , 0);
        for (int i = 1 ; i < N ; i++) {
            int c_2 = 0 , c_5 = 0;
            int tmp = i;
            if (i % 2 == 0) {
                while (tmp % 2 == 0) {
                    tmp /= 2;
                    c_2++;
                }
            }
            if (i % 5 == 0) {
                while (tmp % 5 == 0) {
                    tmp /= 5;
                    c_5++;
                }
            }
            cnt_2[i] = cnt_2[i - 1] + c_2;
            cnt_5[i] = cnt_5[i - 1] + c_5;
        }
        int x;
        while (cin >> x && x != 0) {
            int tm = min(cnt_2[x] , cnt_5[x]);
            int p = 1;
            int c_2 = 0 , c_5 = 0;
            for (int i = 1 ; i <= x ; i++) {
                int tmp = i;
                while (tmp % 2 == 0 && c_2 < tm) {
                    tmp /= 2;
                    c_2++;
                }
                while (tmp % 5 == 0 && c_5 < tm) {
                    tmp /= 5;
                    c_5++; 
                }
                p = (p * tmp) % 10;
            }
            cout << p << '\n';
        }
    }
    return 0;
}