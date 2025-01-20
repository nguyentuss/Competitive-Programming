//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct segTree {
    vector<int> IT;
    vector<int> lz;
    segTree(int n) {
        IT.resize(4*n + 7 , 0);
        lz.resize(4*n + 7);
    }
    void push(int id , int p) {
        IT[p] = max(IT[p] , IT[id]); 
        lz[p] = lz[id]; 
        return;
    }
    void lazy(int id) {
        if (!lz[id]) return;
        push(id , id << 1);
        push(id , id << 1 | 1);
        lz[id] = 0;
    }
    void update(int id , int l , int r , int L , int R , int val) {
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            IT[id] = max(IT[id] , val); 
            lz[id] = val;
            return;
        }
        lazy(id);
        int mid = (l + r) >> 1;
        update(id << 1 , l , mid , L , R , val);
        update(id << 1 | 1 , mid + 1 , r , L , R , val); 
        IT[id] = max(IT[id << 1] , IT[id << 1 | 1]);
        return;
    }
    int get(int id , int l , int r , int L , int R) {
        if (r < L || R < l) return 0;
        if (L <= l && r <= R) {
            return IT[id];
        }
        lazy(id);
        int mid = (l + r) >> 1;
        return max(get(id << 1 , l , mid , L , R) , get(id << 1 | 1 , mid + 1 , r , L , R)); 
    }
};

void solve() {
    int n, k; cin >> n >> k;
    segTree st(n + 3); 
    vector<int> a(n + 1) , pos(n + 1) , b(n + 1);
    repn(i , 1 , n) {
        cin >> a[i]; 
        pos[a[i]] = i;
    }
    repn(i , 1, n) {
        st.update(1 , 1 , n , i , i , i);
    }
    repn(i , 1 , n) cin >> b[i];
    vector<ii> v;
    repn(i , 1 , n - 1) {
        if (pos[b[i]] > pos[b[i + 1]]) {
            v.push_back({pos[b[i]] , pos[b[i + 1]]});
        }
    }
    sort(v.begin() , v.end() , greater<ii>());
    for (auto [r , l] : v) {
        int mx = st.get(1 , 1 , n , l , r);
        st.update(1 , 1 , n , l , r , mx);
    }
    set<int> s;
    vector<int> ans;
    repn(i , 1 , n) {
        //cerr << i << " ";
        int x = st.get(1 , 1 , n , i , i); 
        ans.push_back(x);
        s.insert(x);
    }
    map<int , int> mp;
    int cnt = 0;
    for (int x : s) {
        mp[x] = cnt++;
    }
    if (s.size() < k) {
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
    string isSorted = "";
    string cc = "";
    for (int x : ans) {
        int c = min((int)'z' , mp[x] + 'a');
        //cout << (char) c;
        isSorted += c;
        cc += c;
    }
    sort(isSorted.begin() , isSorted.end());
    // if (n == 200000 && k == 1 && a[1] == 122) {
    //     if (cc == isSorted) cout << "It'ssorted";
    //     cout << sz(s);
    // }
    cout << cc;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}