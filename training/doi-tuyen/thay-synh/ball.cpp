#include <iostream>

using namespace std;

const int N = 31;
int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    f[n] = 1;
    for (int i = n ; i >= 1 ; i--) {
        if (i - 1 >= 0)
            f[i - 1] += f[i];
        if (i - 2 >= 0)
        f[i - 2] += f[i]; 
    }
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        sum += f[i];
    }
    cout << sum;
    return 0;
}