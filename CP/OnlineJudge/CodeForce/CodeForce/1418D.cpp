#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int a[N];
set<int> s_ele;
multiset<int> s_diff;

int findMax(set<int> &s) {
    if (!s.empty()) {
        return (*s.rbegin());
    }
    return 0;
}

int findMin(set<int> &s) {
    if (!s.empty()){ 
        return (*s.begin());
    }
    return 0;
}

int find_greater(set<int> &s , int x) {
    if (!s.empty()) {
        auto it = s.lower_bound(x);
        if (it != s.end()) return *it; 
    }
    return -1;
}

int find_lower(set<int> &s , int x) {
    if (!s.empty()) {
        auto it = s.lower_bound(x);
        if (it != s.begin()) {
            it--;
            return *it;
        }
    }
    return -1;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , q; cin >> n >> q;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        s_ele.insert(a[i]);
    }
    sort(a + 1 , a + 1 + n);
    for (int i = 1 ; i < n ; i++) {
        s_diff.insert(a[i + 1] - a[i]);
    }
    int tt = 0; 
    if (!s_diff.empty()) tt = *s_diff.rbegin();
    cout << findMax(s_ele) - findMin(s_ele) - tt << '\n';
    int cnt = 0;
    while (q--) {
        cnt++;
        int ask , x; cin >> ask >> x;
        if (ask == 0) {
            s_ele.erase(x);
            int l = find_lower(s_ele, x);
            int r = find_greater(s_ele , x);
            if (l != -1) s_diff.erase(s_diff.find(x - l));
            if (r != -1) s_diff.erase(s_diff.find(r - x));
            if (l != -1 && r != -1) s_diff.insert(r - l);
        }
        else {
            int l = find_lower(s_ele, x);
            int r = find_greater(s_ele , x);
            s_ele.insert(x);
            if (l != -1) s_diff.insert(x - l);
            if (r != -1) s_diff.insert(r - x);
            if (l != -1 && r != -1) s_diff.erase(s_diff.find(r - l));
        }
        int tm = 0;
        if (!s_diff.empty()) tm = *s_diff.rbegin();
        cout << findMax(s_ele) - findMin(s_ele) - tm << '\n';
    }
    //cout << find_lower(s_ele , 11) << " " << find_greater(s_ele , 11);
    return 0;
}