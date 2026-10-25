#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_DIGITS = 30;
const int MAX_FIGURES = 9;

typedef int longint[MAX_DIGITS + 1];
typedef longint fig[MAX_FIGURES + 1];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void addLong(longint& a, longint& b) {
    int z = max(a[0], b[0]);
    int cy = 0;
    for (int i = 1; i <= z + 1; ++i) {
        cy += a[i] + b[i];
        if (cy > 9999) {
            a[i] = cy - 10000;
            cy = 1;
        } else {
            a[i] = cy;
            cy = 0;
        }
    }
    a[0] = (a[z + 1] > 0) ? z + 1 : z;
}

void xwrite(int a) {
    string s = to_string(a);
    while (s.length() < 4) {
        s = "0" + s;
    }
    cout << s;
}

void writelong(longint& a) {
    cout << a[a[0]];
    for (int i = a[0] - 1; i >= 1; --i) {
        xwrite(a[i]);
    }
}

int main() {
    int n;
    cin >> n;
    
    fig a, b;

    for (int i = 0; i <= MAX_FIGURES; ++i) {
        a[i][0] = 1;
        a[i][1] = 1;
    }
    a[0][1] = 0;
    a[8][1] = 0;

    for (int i = 2; i <= n; ++i) {
        b[0][0] = 0;
        addLong(b[0], a[4]);
        addLong(b[0], a[6]);
        b[1][0] = 0;
        addLong(b[1], a[6]);
        addLong(b[1], a[8]);
        b[2][0] = 0;
        addLong(b[2], a[7]);
        addLong(b[2], a[9]);
        b[3][0] = 0;
        addLong(b[3], a[4]);
        addLong(b[3], a[8]);
        b[4][0] = 0;
        addLong(b[4], a[0]);
        addLong(b[4], a[3]);
        addLong(b[4], a[9]);
        b[5][0] = 1;
        b[5][1] = 0;
        b[6][0] = 0;
        addLong(b[6], a[0]);
        addLong(b[6], a[1]);
        addLong(b[6], a[7]);
        b[7][0] = 0;
        addLong(b[7], a[2]);
        addLong(b[7], a[6]);
        b[8][0] = 0;
        addLong(b[8], a[1]);
        addLong(b[8], a[3]);
        b[9][0] = 0;
        addLong(b[9], a[2]);
        addLong(b[9], a[4]);
    }

    for (int i = 1; i <= MAX_FIGURES; ++i) {
        addLong(a[0], a[i]);
    }

    writelong(a[0]);

    return 0;
}
