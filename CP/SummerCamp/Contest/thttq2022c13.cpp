#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 70 ;
const int MOD = 1e9 + 7;
int base;

int n , m;
int POW[100000] , hashA[100000] , hashB[100000];

long long getHash(int i , int j) {
	return (hashA[j] - hashA[i - 1]*POW[j - i + 1]);
}

long long getHashB(int i , int j) {
    return (hashB[j] - hashB[i - 1]*POW[j - i + 1]);
}

int ans = inf;
vector<int> per; 
int X[MAX_N];

void write() {
    int l = 1;
    int one = 0;
    map<int , vector<int>> cnt;
    X[n] = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (X[i]) {
            one++;
            cnt[getHash(l , i)].push_back(i);
            l = i + 1;
        } 
    }
    l = 1;
    vector<int> vv;
    int dem = 0;
    for (int i = 1 ; i <= n ;i ++) {
        int x = getHashB(l , i);
        if (cnt[x].size()) {
            dem++;
            vv.push_back(cnt[x][0]);
            cnt[x].pop_back();
            l = i + 1;
        }
    }
    if (l == (n + 1) &&  ans > dem) {
        ans = dem;
        per = vv;
    }
}

void backtr(int i) {
    for (int j = 0 ; j <= 1 ; j++) {
        X[i] = j; 
        if (n == i) write();
        else {
            backtr(i + 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string a , b; cin >> a >> b;
    n = a.size() , m = b.size();
    a = ' ' + a , b = ' ' + b;
    base = sqrt(n);
    if (n != m) {
        cout << -1;
        return 0;
    }
	POW[0] = 1;
	for (int i = 1 ; i <= 20 ; i++) {
		POW[i] = POW[i - 1]*base;
	}
	for (int i = 1 ; i <= m ; i++) {
		hashB[i] = hashB[i - 1]*base + b[i] - 'a' + 1; 
	} 
	for (int i = 1 ; i <= n ; i++) 
		hashA[i] = hashA[i - 1]*base + a[i] - 'a' + 1; 
    backtr(1);
    cout << ans;
    return 0;
}