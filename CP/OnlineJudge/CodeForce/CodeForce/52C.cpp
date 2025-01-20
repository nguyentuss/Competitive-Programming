#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (200007)

struct seg {
    int val;
    int lazy;
};

seg IT[4*MAX_N];
int v[MAX_N];

void build(int id , int l , int r) {
    if (l == r) {
        IT[id].val = v[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = min(IT[2*id] , IT[2*id + 1]);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0 ; i < n ;i++) {
        cin >> v[i];
    }
    build(1 , 0 , n - 1);
    int m; cin >> m;
    for (int i = 1; i <= n ; i++) {
        int l , r;
        string s;
        cin >> l;
        getline(cin , s);
        string tmp1 , tmp2;
        if (s.size() == 2) r = stoi(s);

    }


    return 0;
}
