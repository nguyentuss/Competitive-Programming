//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int n , m , r; 
int x[N], y[N], a[N],b[N],c[N];

// find point intersect between 2 duong` thang
bool inter(int i1, int i2) {
	int det = a[i1] * b[i2] - a[i2] * b[i1];
	if (det == 0) return 0;
	double x = ((double)c[i1] * b[i2] - c[i2] * b[i1]) / det;
	double y = ((double)a[i1] * c[i2] - a[i2] * c[i1]) / det;
	return sqrt(x * x + y * y) <= r;
}

void solve() {
    cin >> n >> m >> r;
    for (int i = 0 ; i < n ; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0 ; i < m ; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int cnt = 1 + m;
    for (int i = 0 ; i < m ; i++) {
        for (int j = i + 1 ; j < m ; j++) {
            if (inter(i , j)) cnt++;
        }
    }
    if (cnt != n) {
        cout << "no" << '\n';
        return;
    }
    map<int , int> mp; 
    for (int i = 0 ; i < n ; i++) {
        int pos = 0; 
        for (int j = 0 ; j < m ; j++) {
            if (x[i] * a[j] + y[i] * b[j] + c[j] > 0) pos |= 1 << j;
        }
        if (mp[pos]) {
            cout << "no" << '\n';
            return;
        }
        mp[pos] = 1;
    }
    cout << "yes" << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}