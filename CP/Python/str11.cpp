#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string x,s,y;
    getline(cin,s);
    getline(cin,x);
    getline(cin,y);
    while (s.find(x)!=-1)
    {
        int pos = s.find(x);
        s.erase(pos , x.length());
        s.insert(pos , y);
    }
    cout << s ;
    return 0;
}