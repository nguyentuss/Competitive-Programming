#include <bits/stdc++.h>

using namespace std;

const int N = 15;
#define ii pair<int , int>

int cnt_P[5'000'000];
int f[1 << 15];
int c[1 << 15];

// goi f[i][mask] là đáp án bài toán khi xét tới customer thứ i
// mask đã được sử dụng , custormer i lưu dc S số
// DPT : 3^N use optimize subset in mask

void eratosthenesSieve(int lim) {
    cnt_P[0] = cnt_P[1] = 0;
	for (int i = 2 ; i < lim ; i++) {
        if (cnt_P[i] == 0) 
            for (int j = i ; j < lim ; j += i) {
                cnt_P[j] ++;
            }
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthenesSieve(1000'000);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        for (int i = 0 ; i < n ; i++) {
            if (mask & (1 << i)) {
                c[mask] += a[i];
            }
        }
        c[mask] = cnt_P[c[mask]];
    }
    //cout << cnt_P[210];
    for (int mask = 0 ; mask < (1 << n) ; mask++) {
        for (int i = mask ; i > 0 ; i = (i - 1) & mask) {
            f[mask] = max(f[mask] , f[mask ^ i] + c[i]);
        }
    }
    cout << f[(1 << n) - 1];
    return 0;
}