    #include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    s = '0' + s;
    vector <vector <int>> f(2002 , vector<int> (2002 , INT_MAX));
    int len = s.size() - 1;
    f[0][0] = 0;
    for (int i = 0 ; i < len ; i ++) {
        for (int j = 0 ; j <= len ; j++) {
            if (f[i][j] == INT_MAX) continue;
            if (s[i + 1] == '(') {
                f[i + 1][j + 1] = min(f[i + 1][j + 1] , f[i][j]);
                if (j > 0) 
                    f[i + 1][j - 1] = min(f[i + 1][j - 1] , f[i][j] + 1);
            }
            else {
                if (j > 0)
                    f[i + 1][j - 1] = min(f[i + 1][j - 1] , f[i][j]);
                f[i + 1][j + 1] = min(f[i + 1][j + 1] , f[i][j] + 1);
            }
        }
    }
    cout << f[len][0];

    return 0;
}