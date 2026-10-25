//source::
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

void resize(string &a , int n) {
    while ((int) a.size() < n) {
        a = "?" + a;
    }   
}

int change(char x) {
    if (x == '?') return -1; 
    return (x - '0');
} 

void solve() {
    string s; cin >> s;
    int pos = 0;
    string a = "" , b = "" , c = "";
    for (auto i : s) {
        pos++;
        if (i == '+') break;
        a += i;
    }    
    int tmp = pos;
    for (int i = pos ; i < (int) s.size() ; i++) {
        tmp ++;
        if (s[i] == '=') break;
        b += s[i];
    }
    int sz = c.size();
    for (int i = tmp ; i < (int) s.size() ; i++) c += s[i]; 
    int mx = max({(int) a.size() , (int) b.size() , (int) c.size()});
    resize(a , mx); resize(b , mx); resize(c , mx);
    reverse(a.begin() , a.end()); 
    reverse(b.begin() , b.end());
    reverse(c.begin() , c.end());
    int miss = 0;
    for (int i = 0 ; i < sz ; i++) {
        int x = change(a[i]); 
        int y = change(b[i]); 
        int z = change(c[i]);
        if (z != -1) {
            if (x > y) swap(x , y); 
            if (x == -1 && y == -1) {
                if (z == 0) a[i] = '0' , b[i] = '0';
                else {
                    a[i] = '1'; 
                    b[i] = z - 1 + '0';
                } 
            }
            else if (x == -1) {
                if (y > z) {
                    
                }
            }
        }
    }
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