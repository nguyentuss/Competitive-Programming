#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 7;

int f[MAX_N];

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    f[1] = 1;
    for (int i = 1 ; i < MAX_N ; i++) {
        for (int j = i << 1 ; j < MAX_N ; j += i) {
            f[j] -= f[i];
        }
    }
    for (int i = 1 ; i < 20 ; i++) 
        cout << f[i] << " ";
    return 0;
}