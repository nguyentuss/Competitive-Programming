#include <bits/stdc++.h>

using namespace std;

#define MOD (int) (1e9 + 7)
#define MAX_N (int) (1e5 + 7)
#define int long long

int cnt[71][2];
int mask_num[71];
int f[2][1 << 20];

// goi cnt[i][status] la so cach chon sao cho no la chan neu status = 0 
// nguoc lai la le neu status = 1

bool prime(int x) {
    for (int i = 2 ; i * i <= x ; i++) {
        if (x % i == 0) return false;
    }
    return (x > 1);
}

void init() {
    for (int i = 0 ; i < 71 ; i++)
        cnt[i][0] = 1;
    int dem = 0;
    for (int i = 2 ; i < 71 ; i++) {
        if (!prime(i)) continue;
        for (int j = 1 ; j <= 71 ; j++) {
            int x = j;
            if (x % i == 0) {
                while (x % i == 0) {
                    mask_num[j] ^= (1 << dem);
                    x /= i;
                }
            }
        }
        dem++;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		cnt[x][0] = cnt[x][1] = (cnt[x][1] + cnt[x][0]) % MOD;
	}
    f[0][0] = 1;
    for (int i = 0 ; i < 70 ; i++) {
        int newi = (i + 1)%2;
        int cur = (newi + 1)%2;
        for (int mask = 0 ; mask < (1 << 20) ; mask++) {
            if (f[cur][mask] == 0) continue;
            (f[newi][mask ^ mask_num[i + 1]] += f[cur][mask]*cnt[i + 1][1])%=MOD;
            (f[newi][mask] += f[cur][mask]*cnt[i + 1][0] ) %= MOD;
        }
        for (int mask = 0 ; mask < (1 << 20) ; mask++) {
            f[cur][mask] = 0;
        }
    }
    cout << ((f[0][0] - 1)%MOD + MOD)%MOD;
    return 0;
}
