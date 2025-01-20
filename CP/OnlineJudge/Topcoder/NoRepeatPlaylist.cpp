#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long f[101][101];
    
class NoRepeatPlaylist {
public:
    int numPlaylists(int N, int M, int P) {
        f[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= P;  ++j) {
                f[i][j] = (f[i - 1][j - 1] * (N - i + 1) + f[i][j - 1] * max(i - M, 0)) % MOD;
            }
        }
        return (int)f[N][P];
    }
};