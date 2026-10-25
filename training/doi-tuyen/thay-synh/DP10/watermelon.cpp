#include <bits/stdc++.h>

using namespace std;

int min_time_to_explore(int N, int M, vector<string>& garden) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (garden[i - 1][j - 1] == 'I' ? 1 : 0);
        }
    }

    return dp[N][M];
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> garden(N);
    for (int i = 0; i < N; ++i) {
        cin >> garden[i];
    }
    // for (int i = 1 ; i <= N ; i++) {
    //     for (int j = 1 ; j <= M ; j++) {
    //         cout << garden[i - 1][j - 1] << '\n';
    //     }
    // }

    int num_watermelons = 0;
    for (const string& row : garden) {
        num_watermelons += count(row.begin(), row.end(), 'I');
    }
    vector<int> result(num_watermelons + 1);
    for (int i = 0; i <= num_watermelons; ++i) {
        result[i] = min_time_to_explore(N, M, garden);
    }

    for (int i = 0; i <= num_watermelons; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
