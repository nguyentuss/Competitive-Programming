#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7)
#define int long long
#define ii pair<int , int>
#pragma GCC optimize("Ofast")

struct seg {
    int l , r , id;
};

int r1 , r2;
vector<int> adj[MAX_N];
vector<int> a;
int d[MAX_N];
int ti[MAX_N] , to[MAX_N];
int c[MAX_N];
int dem = 0;
map<int , int> cnt;

int BLOCK;

bool cmp(seg &x , seg &y) {
    return (x.l/BLOCK < y.l/BLOCK || (x.l/BLOCK == y.l/BLOCK && x.r/BLOCK < y.r/BLOCK));
}

void DFS1(int u , int father) {
	ti[u] = ++dem;
	a.push_back(u);	
	for (auto v : adj[u]) {
		if (v != father) {
			DFS1(v , u);
		}
	}
	to[u] = ++dem;
}
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
    //freopen("spc3.inp","r",stdin);
    //freopen("spc3.out","w",stdout);   
    int t; cin >> t;
    while (t--) {
        int n ; cin >> n;
        BLOCK = sqrt(n);
        dem = 0;
        cnt.clear();
        for (int i = 1 ; i <= n ; i++) {
            cin >> c[i];
            ti[i] = to[i] = d[i] = 0;
            adj[i].clear();
        }
        a.clear();
        vector<seg> query;
        a.push_back(0);
        for (int i = 1 ; i <= n ; i++) {
            int len; cin >> len;
            for (int j = 1 ; j <= len ; j++) {
                int u; cin >> u;
                adj[i].push_back(u);
            }
        }
        for (int i = 1 ; i <= n ; i++) 
            sort(adj[i].begin() , adj[i].end());
        DFS1(1 , -1);
        for (int i = 1 ; i <= n ; i++) 
            d[i] = c[a[i]];
        // for (int i = 1 ; i <= n ; i++) cerr << a[i] << " ";
        // cerr << '\n';
        // for (int i = 1 ; i <= n ; i++) cerr << d[i] << " ";
        // cerr << '\n';
        for (int i = 1 ; i <= n ;i ++) 
            query.push_back({i , i + (to[a[i]] - ti[a[i]] + 1)/2 - 1 , a[i]});
        sort(query.begin() , query.end() , cmp);
        int currL = query[0].l , currR = query[0].r;
        int diff = 0;
        for (int i = currL ; i <= currR ; i++) {
            if (!cnt[d[i]]) diff++;
            cnt[d[i]]++;
        }
        vector<ii> res;
        res.push_back(ii(query[0].id , diff));
        for (int i = 1 ; i < query.size() ; i++) {
            int L = query[i].l , R = query[i].r;
            while (currL < L) {
                cnt[d[currL]] --;
                if (!cnt[d[currL]]) diff--;
                currL++;
            }
            while (currL > L) {
                currL--;
                if (!cnt[d[currL]]) diff++;
                cnt[d[currL]]++;
            }
            while (currR < R) {  
                currR++;
                if (!cnt[d[currR]]) diff++;
                cnt[d[currR]]++;
            }
            while (R < currR) {
                cnt[d[currR]]--;
                if (!cnt[d[currR]]) diff--;
                currR--;
            }
            res.push_back(ii(query[i].id , diff));
        }
        sort(res.begin() , res.end());
        for (auto x : res) cout << x.second << " ";
        cout << '\n';
    }
	return 0;
}