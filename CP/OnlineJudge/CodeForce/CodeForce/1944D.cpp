//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int base = 311;

vector<int> D_odd;
vector<int> D_even;
void manacher(string &s , int n){
    int L = 1 , R = 0;
    D_odd.assign(n + 1 , 0);
    D_even.assign(n + 1 , 0);
    for (int i = 1 ; i <= n ; i++) {
        if (i > R) D_odd[i] = 0; 
        else D_odd[i] = min(R - i , D_odd[L + (R - i)]); 
        while (i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= N && s[i - D_odd[i] - 1] == s[i + D_odd[i] + 1]) {
            D_odd[i]++; 
        }
        if (i + D_odd[i] > R) {
            R = i + D_odd[i]; 
            L = i - D_odd[i];
        }
    }
    L = 1 , R = 0; 
    for (int i = 1 ; i <= n ; i++) {
        int j = i + 1; 
        if (j > R) D_even[i] = 0; 
        else D_even[i] = min(R - j + 1 , D_even[L + (R - i)]);
        while (i - D_even[i] > 0 && j + D_even[i] <= N && s[i - D_even[i]] == s[j + D_even[i]]) {
            D_even[i]++;
        }
        if (i + D_even[i] > R) {
            R = i + D_even[i]; 
            L = j - D_even[i];
        }
    }
}

void solve() {
	int n , q; cin >> n >> q;	
	string s; cin >> s;
    s = " " + s; 
    manacher(s , n);
    vector<int> f(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        f[i] = f[i - 1] + D_odd[i] + 1 + D_even[i];
        cout << D_odd[i] << " " << D_even[i] << '\n';
    }
     set <int> s1, s2;
    for (int i = 0; i < n - 1; i++){
        if (s[i] != s[i + 1]) s1.insert(i);
        if (i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
    }
    // while (q--) {
    //     int l , r; cin >> l >> r;
    //     if (l == r){
    //         cout << 0 << "\n";
    //         continue;
    //     }
        
    //     int len = r - l + 1;

    //     int ans;
    //     auto it = s1.lower_bound(l);
    //     if (it == s1.end() || (*it) >= r){
    //         ans = 0;
    //     } else {
    //         it = s2.lower_bound(l);
    //         if (it == s2.end() || (*it) >= r - 1){
    //             ans = ((len - 1)/ 2) * (((len - 1) / 2) + 1);
    //         } else {
    //             ans =  len * (len - 1) / 2 - 1;
    //         }
    //     }

    //     if (v[l + r] < (r - l + 1)) ans += len;

    //     cout << ans << "\n";
    // }
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}