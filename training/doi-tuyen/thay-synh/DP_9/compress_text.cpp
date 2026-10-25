#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int rmax = 52;

struct Rule {
    char c;
    string s;
};

int n, r;
vector<Rule> p;
unsigned char a[256];
unsigned char b[256];
string s;

void work() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0] = 1;
    b[0] = 0;
    for (int i = 1; i <= s.length(); i++) {
        a[i] = a[i - 1] + 1;
        b[i] = 0;
        for (int j = 1; j <= r; j++) {
            int w = p[j-1].s.length();
            if (w <= i) {
                if (a[i - w] + 1 < a[i]) {
                    if (s.substr(i - w, w) == p[j-1].s) {
                        a[i] = a[i - w] + 1;
                        b[i] = j;
                    }
                }
            }
        }
    }
    string q = "";
    int i = s.length();
    while (i != 0) {
        if (b[i] == 0) {
            q = s[i-1] + q;
            i--;
        } else {
            q = p[b[i]-1].c + q;
            i -= p[b[i]-1].s.length();
        }
    }
    cout << q << endl;
}

int main() {
    freopen("text.inp","r",stdin);
    freopen("text.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> n;
    p.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> p[i].s >> p[i].c;
    }

    for (int tnum = 1; tnum <= n; tnum++) {
        cin >> s;
        work();
    }

    return 0;
}