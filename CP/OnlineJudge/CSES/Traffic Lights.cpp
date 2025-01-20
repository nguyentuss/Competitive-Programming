#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7; 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int x , n; cin >> x >> n;
    map<int , int> mp , cnt;
    mp[0] = 1 , mp[x] = 1;
    for (int i = 1 ; i <= n ;i ++) {
        int x; cin >> x;
        auto it = mp.upper_bound(x); 
        int r = it->first;
        it--; 
        int l = it->first; 
        //cerr << l << " " << r << '\n';
        if (cnt[r - l]) cnt[r - l]--;
        if (!cnt[r - l]) cnt.erase(r - l);
        cnt[r - x]++; cnt[x - l]++;
        mp[x]++;
       // cerr << r - x - 1 << " " << x - l - 1 << '\n';
        auto it_1 = cnt.end(); 
        it_1--;
        cout << it_1->first << " ";
    }

    return 0;
}