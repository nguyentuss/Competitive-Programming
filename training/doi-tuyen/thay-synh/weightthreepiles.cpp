#include <iostream>
#include <vector>

using namespace std;

bool can_partition_into_three_piles(int N, vector<int>& masses, vector<vector<int>>& piles) {
    int total_mass = 0;
    for (int i = 0; i < N; ++i) {
        total_mass += masses[i];
    }

    if (total_mass % 3 != 0) {
        return false;
    }

    int target_mass = total_mass / 3;

    // dp[i][j][k] represents whether it's possible to form piles of weights i, j, and k using the first 'k' masses
    vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(target_mass + 1, vector<bool>(target_mass + 1, false)));
    vector<vector<vector<int>>> P(N + 1, vector<vector<int>>(target_mass + 1, vector<int>(target_mass + 1, 0)));
    for (int i = 0; i <= N; ++i) {  
        dp[i][0][0] = true;  
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 0; i <= target_mass; ++i) {
            for (int j = 0; j <= target_mass; ++j) {
                dp[k][i][j] = dp[k - 1][i][j];  

                if (i >= masses[k - 1]) {
                    dp[k][i][j] = dp[k][i][j] || dp[k - 1][i - masses[k - 1]][j];
                    if (dp[k - 1][i - masses[k - 1]][j]) P[k][i][j] = 1;
                }

                if (j >= masses[k - 1]) {
                    dp[k][i][j] = dp[k][i][j] || dp[k - 1][i][j - masses[k - 1]];
                    if (dp[k - 1][i][j - masses[k - 1]]) P[k][i][j] = 2;
                }
            }
        }
    }

    if (!dp[N][target_mass][target_mass]) {
        return false;  // No solution
    }
    int i = target_mass;
    int j = target_mass;
    for (int k = N; k > 0; --k) {
        int status = P[k][i][j];
        if (status == 1) {
            piles[0].push_back(k);
            i -= masses[k - 1];
        }
        else if (status == 2) {
            piles[1].push_back(k);
            j -= masses[k - 1];
        }
        else piles[2].push_back(k);
    }

    return true;
}

vector<vector<int>> piles;
int main() {
    int N;
    cin >> N;

    vector<int> masses(N);
    for (int i = 0; i < N; ++i) {
        cin >> masses[i];
    }
    piles.resize(3);
    int total_mass = 0;
    if (can_partition_into_three_piles(N, masses , piles)) {
        for (int x : piles[0]) cout << x << " "; 
        cout << '\n';
        for (int x : piles[1]) cout << x << " "; 
        cout << '\n';
        for (int x : piles[2]) cout << x << " ";
    }
    else {
        cout << "No solution";  
    }
    return 0; 
}