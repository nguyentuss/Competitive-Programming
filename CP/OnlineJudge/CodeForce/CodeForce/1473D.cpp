#include <bits/stdc++.h>
using namespace std;

#define ll long long

void test_case() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> MINL(n + 1);
    vector<int> MAXL(n + 1);
    vector<int> NOWL(n + 1);
    vector<int> MINR(n + 1);
    vector<int> MAXR(n + 1);
    vector<int> NOWR(n + 1);

    MINL[0] = 0; MAXL[0] = 0; NOWL[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') NOWL[i + 1] = NOWL[i] - 1;
        else NOWL[i + 1] = NOWL[i] + 1;

        MINL[i + 1] = min(MINL[i], NOWL[i + 1]);
        MAXL[i + 1] = max(MAXL[i], NOWL[i + 1]);
    }

    MINR[n] = 0; MAXR[n] = 0; NOWR[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '-') NOWR[i] = NOWR[i + 1] - 1;
        else NOWR[i] = NOWR[i + 1] + 1;

        MINR[i] = min(MINR[i + 1], NOWR[i]);
        MAXR[i] = max(MAXR[i + 1], NOWR[i]); 
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int MIN = MINL[l];
        int MAX = MAXL[l];
        int NOW = NOWL[l];

        MIN = min(MIN, NOW - MAXR[r + 1] + NOWR[r + 1]);
        MAX = max(MAX, NOW - MINR[r + 1] + NOWR[r + 1]);

        cout << MAX - MIN + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        test_case();
    }
}