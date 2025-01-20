//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) a.size()

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int k[N];
int P[N][20];
int n , p; 
int limit = 0;

int POW(int a , int x) {
    if (x == 0) return 1; 
    int child = POW(a , x/2)%MOD;
    if (x % 2 == 0) return (child*child)%MOD;
    else return ((child*child)%MOD*a)%MOD;
}

void calcjjdo() {
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < 20 ; j++) {
            P[i][j] = -1;
        }
    }
    limit = 0;
    for (int i = 1 ; i <= n ; i++) {
        P[i][0] = i; 
        for (int j = 1 ; j < 20 ; j++) {
            if (P[i][j - 1]*p > n) {
                if (i == 1) limit = j;
                break;
            }
            P[i][j] = P[i][j - 1] * p;
        }
    }
}

void solve() {
    cin >> n >> p;
    for (int i = 0 ; i < n ; i++) {
        cin >> k[i];
    }
    if (p == 1) {
        cout << n%2 << '\n';
        return;
    }
    sort(k , k + n);
    reverse(k , k + n); 
    calcjjdo(); 
    bool status = false;
    vector<int> a , b;
    int bb = 0; 
    int emer = false;
    int last = 0;
    //cout << P[7][1];
    for (int i = 0 ; i < n ; i++) {
        if (emer) {
            b.push_back(k[i]);
            continue;
        }
        else {
            if (!status) {
                a.push_back(k[i]);
                bb = a.back();
                last = 1;
                status ^= 1;
            }
            else {
                int kc = bb - k[i];
                b.push_back(k[i]);
                if (kc > limit || P[last][kc] == -1) {
                    emer = true;
                } 
                else {
                    if (!kc) last--; 
                    else last = P[last][kc] - 1;
                    //cerr << last << '\n'; 
                    if (!last) status ^= 1;
                    bb = k[i];
                    //cerr << last << '\n';
                }
            }
        }
    }
    // for (auto x : a) cerr << x << " ";
    // cerr << '\n';
    // for (auto x : b) cerr << x << " ";
    // cerr << '\n';
    int v1 = 0 , v2 = 0;
    for (auto x : a) {
        v1 = (v1 + POW(p , x)%MOD)%MOD;
    }
    //cout << '\n';
    for (auto x : b) {
        v2 = (v2 + POW(p , x)%MOD)%MOD;
    }
    cout << ((v1 - v2)%MOD + MOD)%MOD << '\n';
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}