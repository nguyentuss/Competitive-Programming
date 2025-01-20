#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int main() {
    long n , s = 0; ; cin >> n;
    for (int i = 1 ; i <=n ; i++){
        cin >> a[i];
        s += a[i];
    }
    long dem = 0,tong = 0;
    for (int i = n; i>=2 ; i--)
    {
        tong = tong + a[i];
        s = s - a[i];
        cout << s << " " << tong << "\n";
        if (s == tong) dem++;
        cout << dem << "\n";
    }
    cout << dem;
    return 0;
}