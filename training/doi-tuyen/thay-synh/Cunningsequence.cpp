#include <iostream>

using namespace std;

const int N = 1007;
int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    f[0] = 1; f[1] = 1; 
    for (int i = 2 ; i <= n ; i++) {
        if (!(i % 2)) {
            f[i] = f[i/2] + 1;
        }
        else {
            f[i] = f[i - 1] - f[i/2];
        }
    }
    cout << f[n];

    return 0;
}