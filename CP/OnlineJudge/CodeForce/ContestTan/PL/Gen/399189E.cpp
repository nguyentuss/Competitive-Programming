#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

int n , m;
int f[N];    

void up(int x , int val) {
    for ( ; x < N ; x += x&(-x)) {
        f[x] += val;
    }
}

int get(int x) {
    int ss = 0;
    for ( ; x > 0 ; x -= x&(-x)) {
        ss += f[x];
    }       
    return ss;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++) {
        up(i , 1);
    }
    int last = n;
    for (int i = 1 ; i <= m ; i++) {
        int pos; cin >> pos;
        if (pos > last) {
            cout << 0;
        }
        else {
            int l = 1 , r = n;
            int c = 0;
            while (l <= r) {
                int mid = (l + r)/2;
                //cerr << l << " " << r << '\n';
                if (get(mid) >= pos) {
                    r = mid - 1;
                    c = mid;
                }
                else l = mid + 1;
            }
            cout << c;
            up(c , -1);
            last--;
        }
        cout << '\n';
    }
    
    return 0;
}