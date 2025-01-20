//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) a.size()

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e18 + 7;

int g[N][N];

tuple<string , vector<int>> change(string s , vector<int> pl) {
    char curr = s[0];
    string tt = "";
    tt += s[0];
    int cc = pl[0]; 
    vector<int> vc;
    for (int i = 1 ; i < s.size() ; i++) {
        if (curr != s[i]) {
            tt += s[i];
            curr = s[i];
            vc.push_back(cc);
            cc = pl[i];
        }
        else cc += pl[i];
    }
    vc.push_back(cc);
    tuple<string , vector<int>> f(tt , vc); 
    return f;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cou = 0;
    // for (int i = 'z' ; i >= 'a' ; i--) {
    //     for (auto x : s) {
    //         if (x == i) {
    //             cou++; 
    //         }
    //     }
    //     cerr << cou << '\n';
    // }
    vector<int> pl(n , 1);
    tuple<string , vector<int>> vz = change(s , pl); 
    string tt = "";
    vector<int> vc;
    tie(tt , vc) = vz;
    s = tt; 
    int cnt = 0;
    bool status = true;
    for (int i = 'z' ; i >= 'a' ; i--) {
        string tmp = "";
        vector<int> tm;
        for (int j = 0 ; j < s.size() ; j++) {
            if (s[j] == i && ((j - 1 >= 0 && s[j - 1] + 1 == s[j]) || (j + 1 < (int) s.size() && s[j] == s[j + 1] + 1))){
                cnt += vc[j];
            }
            else {
                tmp += s[j];
                tm.push_back(vc[j]);
            }
        }
        //cout << cnt << '\n';
        tuple<string , vector<int>> vv = change(tmp , tm);
        tie(tmp , tm) = vv;  
        s = tmp;
        vc = tm;
        //cout << s << '\n';
    }
    cout << cnt;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); 
	cout.tie(NULL);
	int test = 1;
	//cin >> test;
	while(test--) {
		solve();
	}
	return 0;
}