#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct se {
    double s;
    int color;
    int ID;
};
bool cmp(se &a , se &b) {
    return a.s < b.s;
}

bool checked = false;

void solve(int k, const vector<se> &x, const vector<se> &y) {
    vector<se> a(k + 1);
    for (int i=0; i < k ; i++) {
        double dy = y[i].s - y[k].s;
        if (dy != 0) {
            a[i].s = (x[i].s - x[k].s) / dy;
            a[i].color = x[i].color;
        } 
        else {
            a[i].s = 1e9;
            a[i].color = -1;
        }
        a[i].ID = i;
    }
    a[k].s = 1e9;a[k].color = -1; a[k].ID = k;
    sort(a.begin(), a.end() , cmp);
    int red = 0 , blue = 0;int sizered = 0, sizeblue = 0;
    vector <int> tmp1 , tmp2;
    bool c;
    if (y[k].color == 1) c = true;
    else c = false;
    for (int i=1; i<=k; i++) {
        if (a[i - 1].color == 1) {
                tmp2.push_back(a[i - 1].ID);
                blue++;
        }
        else if (a[i - 1].color == 0) {
                tmp1.push_back(a[i - 1].ID);
                red++;
        }
       // cout << a[1].s << " " << a[0].s;
        if (a[i].s != a[i-1].s) {
            if (blue + red >= 2) {
                if (c == true) blue ++;
                else red++;
                if (blue >= 2 && red >= 1) {
                    if (c == true) {
                        cout << k + 1 << " " << tmp2[sizeblue] + 1 << " " << tmp1[sizered] + 1;
                        checked = true;
                        return;
                    }
                    else {
                        cout << k + 1 << " " << tmp2[sizeblue] + 1 << " " << tmp2[sizeblue + 1] + 1;
                        checked = true;
                        return;
                    }
                }
                else if (blue >= 1 && red >= 2) {
                    if (c == true) {
                        cout << k + 1 << " " << tmp1[sizered] + 1<< " " << tmp1[sizered + 1] + 1;
                        checked = true;
                        return;
                    }
                    else {
                        cout << k + 1 << " " << tmp1[sizered] + 1<< " " << tmp2[sizeblue] + 1;
                        checked = true;
                        return;
                    }
                }
            }
            sizeblue = tmp2.size();
            sizered = tmp1.size();
            blue = 0;
            red = 0;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    int n; cin >> n;
    vector<se> x(2*n), y(2*n);
    for (int i=0; i<n; i++) {
        cin >> x[i].s >> y[i].s;
        x[i].color = 1 , y[i].color = 1;
    }
    for (int i = n ; i < 2*n ; i++) {
        cin >> x[i].s >> y[i].s;
        x[i].color = 0 , y[i].color = 0;
    }
    for (int i=2; i<2*n; i++) solve(i, x, y);
    if (checked == false) cout << -1;
    return 0;
}