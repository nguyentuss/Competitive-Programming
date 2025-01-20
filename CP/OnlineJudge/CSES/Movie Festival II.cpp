#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>

vector<ii> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , k; cin >> n >> k;
    a.assign(n + 1 , ii(0 , 0));
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin() + 1 , a.begin() + 1 + n);
    int total = 1;
    multiset<int> s;
    s.insert(a[1].first);
    k--;
    for (int i = 2 ; i <= n ; i++) {
        //cerr << a[i].second << " " << a[i].first << '\n';
        auto it = s.upper_bound(a[i].second);
        if (it == s.begin() && k != 0) {
            k--;
            s.insert(a[i].first);
            total++;
        }
        else if (it != s.begin()){
            //cout << i << '\n';
            it--;
            s.erase(it);
            s.insert(a[i].first);
            total++;
        }
    }
    cout << total;

    return 0;
}