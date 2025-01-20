#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);

    int n , q; cin >> n >> q;
    int diff = 0;
    vector<int> cnt(n + 1) , pos(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        if (cnt[a[i] - 1] == false) {
            diff++;
        }
        cnt[a[i]] = true;
    }
    //cerr << diff;
    auto calc = [&] (int x , int pos_x , int pos_y) {
        if (pos_x > pos[x - 1] && pos_y <= pos[x - 1]) diff ++;
        if (pos_x < pos[x - 1] && pos_y >= pos[x - 1]) diff --;
        //cerr << diff << '\n';
        if (pos_x < pos[x + 1] && pos_y >= pos[x + 1]) diff ++;
        if (pos_x > pos[x + 1] && pos_y <= pos[x + 1]) diff --;
    };

    for (int i = 1 ; i <= q ;i ++) {
        int x , y; cin >> x >> y; 
        x = a[x] , y = a[y];
        int pos_x = pos[x] , pos_y = pos[y];
        calc(x , pos_x , pos_y);
        calc(y , pos_y , pos_x);
        if (y - x == 1) {
            if (pos[x] < pos[y]) 
                diff--;
            if (pos[x] > pos[y]) 
                diff++;
        }
        if (x - y == 1) {
            if (pos[x] < pos[y]) 
                diff++;
            if (pos[x] > pos[y])
                diff--;
        }
        swap(a[pos[x]] , a[pos[y]]);
        swap(pos[x] , pos[y]);
        // for (int j = 1 ; j <= n ; j++) {
        //     cerr << a[j] << " ";
        // }
        cerr << '\n';
        cout << diff << '\n';
    }
    return 0;
}