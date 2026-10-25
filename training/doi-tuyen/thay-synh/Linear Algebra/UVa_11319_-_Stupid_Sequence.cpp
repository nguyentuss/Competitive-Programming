#include <bits/stdc++.h>

using namespace std;

int m[7][7], b[7], x[7];

int a[1500];

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1500; i++) cin >> a[i];
        for (int i = 0; i < 7; i++) {
            int p = 1;
            for (int j = 0; j < 7; j++) {
                m[i][j] = p;
                p *= i + 1;
            }
            b[i] = a[i];
        }
        for (int i = 0; i < 7; i++) {
            for (int k = i; k < 7; k++) {
                if (m[k][i]) {
                    swap(m[k], m[i]);
                    break;
                }
            }
            if (!m[i][i]) {
                cout << "This is a smart sequence!\n";
            }
            for (int k = i + 1; k < 7; k++) {
                int r = m[k][i] / m[i][i];
                if (b[k] < (__int128)b[i] * r) {
                    cout << "This is a smart sequence!\n";
                    return;
                }
                b[k] -= r * b[i];
                for (int j = i; j < 7; j++) {
                    m[k][j] -= r * m[i][j];
                }
            }
        }
        for (int i = 7 - 1; i >= 0; i--) {
            int y = b[i];
            for (int j = i + 1; j < 7; j++) {
                if (y < x[j] * m[i][j]) {
                    cout << "This is a smart sequence!\n";
                    return;
                }
                y -= x[j] * m[i][j];
            }
            x[i] = y / m[i][i];
            if (x[i] > 1000) {
                cout << "This is a smart sequence!\n";
                return;
            }
        }
        for (int i = 1; i <= (int)a.size(); i++) {
            int y = a[i - 1];
            for (int j = 0; j < 7; j++) {
                if (y < x[j] || (y - x[j]) % i) {
                    cout << "This is a smart sequence!\n";
                    return;
                }
                y = (y - x[j]) / i;
            }
            if (y) {
                cout << "This is a smart sequence!\n";
                return;
            }
        }
        cout << x[0];
        for (int i = 1; i < 7; i++) {
            cout << ' ' << x[i];
        }
        cout << "\n";
    }
}
