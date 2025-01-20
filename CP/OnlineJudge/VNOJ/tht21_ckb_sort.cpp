#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7) 
#define inf (int) (1e9 + 7) 


int res[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int a , b; cin >> a >> b;
    vector<string> str;
    vector<int> num;
    for (int i = a ; i <= b ; i++) {
        //cout << i << " ";
        string tmp = to_string(i);
        str.push_back(tmp);
        num.push_back(i);
    }
    sort(str.begin() , str.end());
    map<int , int> m;
    int cnt = 0;
    for (auto x : str) {
        int val = stoi(x);
        m[val] = ++cnt;  
    }
    vector<int> arr;
    for (auto x : num) {
        arr.push_back(m[x]);
       // cout << m[x] << " ";
    }

    vector<int> res(MAX_N);
    vector<int> last(MAX_N , inf);
    for (int i = 0 ; i < arr.size() ; i++) {
        res[i] = lower_bound(last.begin() , last.end() , arr[i]) - last.begin();
        last[res[i]] = min(last[res[i]] , arr[i]);
    }
    int ans = inf;
    int len = arr.size();
    for (int i = 0 ; i < arr.size() ; i++) {
        ans = min(ans , len - res[i] - 1);
    }
    cout << ans;
    return 0;
}