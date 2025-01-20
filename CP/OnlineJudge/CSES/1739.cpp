#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll // delete if causing problems
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define mod(a) (a+MOD)%MOD
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define what_is(x) cerr << #x << " is " << x << "\n"
 
const int maxn = (int)3e5+10; // change when needed!
const int MOD = (int)1e9+7; // same!
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
int n, m, x, y, l, r, k, q, t;
map<int, int> M, N;
multiset<int> S, SS;
string s, ss;
int fenwick[1010][1010];
 
void update(int x, int y, int v){
    for(int i = x; i <= n; i+=(i&-i))
        for(int j = y; j <= n; j+=(j&-j))
            fenwick[i][j]+=v;
}
 
int sum(int x, int y){
    int s = 0;
    for(int i = x; i > 0; i-=(i&-i))
        for(int j = y; j > 0; j-=(j&-j))
            s+=fenwick[i][j];
    return s;
}
 
int query(int x1, int y1, int x2, int y2){
    int sum1 = sum(x2,y2);
    int sum2 = sum(x2,y1-1);
    int sum3 = sum(x1-1,y2);
    int sum4 = sum(x1-1,y1-1);
    return sum1-sum2-sum3+sum4;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            update(i+1, j+1, (c=='*'));
        }
    }
    while(q--){
        int t,x1,y1,x2,y2;
        cin >> t >> y1 >> x1; swap(x1,y1);
        if(t==1) update(x1,y1,query(x1,y1,x1,y1)==0?1:-1);
        else{
            cin >> y2 >> x2; swap(x2,y2);
            cout << query(x1,y1,x2,y2) << "\n";
        }
    }
}