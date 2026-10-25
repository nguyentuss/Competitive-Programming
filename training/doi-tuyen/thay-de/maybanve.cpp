#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    map <char,int> m;
    vector <string> s(n);
    for (int i=0;i<n;i++) cin >> s[i];
    string a;
    cin >> a;
    for (int i=0;i<n;i++) if (s[i].find(a)==0) m[s[i][a.size()]]=1;
    cout << "***";
    for (char i='A';i<='E';i++) if (m[i]) cout << i;else cout << '*';
    cout << "\n";
    for (char i='F';i<='M';i++) if (m[i]) cout << i;else cout << '*';
    cout << "\n";
    for (char i='N';i<='U';i++) if (m[i]) cout << i;else cout << '*';
    cout << "\n";
    for (char i='V';i<='Z';i++) if (m[i]) cout << i;else cout << '*';
    cout << "***";
    return 0;
}