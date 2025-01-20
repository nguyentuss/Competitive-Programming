#include <bits/stdc++.h>

using namespace std;

int main() {
    int x; cin >> x;
    int y = 100 - x;
    int g = __gcd(x , y);
    cout << x/g + y/g;
    return 0;
}