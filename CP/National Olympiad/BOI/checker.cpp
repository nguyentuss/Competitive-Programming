#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> a , b;
    for (int i = 1 ; i <= 10000 ; i++) {
        string x; cin >> x;
        a.push_back(x);
    }    
    for (int i = 1 ; i <= 10000 ; i++) {
        string x; cin >> x;
        b.push_back(x);
    }  
    for (int i = 0 ; i < a.size() ; i++) {
        if (a[i] != b[i]) {
            cout << i << " " << a[i] << " " << b[i] << '\n';
        }
    }

    return 0;
}