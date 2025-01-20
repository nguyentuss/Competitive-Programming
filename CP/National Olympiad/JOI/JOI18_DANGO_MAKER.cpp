#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 3e3 + 7;
const int MOD = 1e9 + 7;

// f[i][0] : khong co thang cuoi cung
// f[i][1] : thang cuoi cung duoc su dung la nam hang ngang
// f[i][2] : thang cuoi cung duoc su dung la nam` hang cot
int f[MAX_N][3];
char a[MAX_N][MAX_N];
int n , m;

bool c(int x , int y , char d) {
    return (0 <= x && x < n && 0 <= y && y < m && a[x][y] == d);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
            //cout << a[i][j] << " ";
        }
    }
    int ans = 0;
    for(int i=0; i<=n+m-4; ++i) {
		int jm=min(m, i+2);
		for(int j=0; j<jm; ++j) {
			f[j+1][0]=max(f[j][0], max(f[j][1], f[j][2]));
			f[j+1][1]=c(i+1-j, j-1, 'R')&&c(i+1-j, j, 'G')&&c(i+1-j, j+1, 'W')?max(f[j][0], f[j][1])+1:0;
			f[j+1][2]=c(i-j, j, 'R')&&c(i+1-j, j, 'G')&&c(i+2-j, j, 'W')?max(f[j][0], f[j][2])+1:0;
		}
		ans+=max(f[jm][0], max(f[jm][1], f[jm][2]));
	}
    cout << ans;
    return 0;
}   