#include <bits/stdc++.h>

#define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
namespace IO {
    const int SIZE = 1 << 23;
    char ibuf[SIZE], *iS, *iT;
    char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
    bool flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return true;
    }
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    #define pc(x) (*oS++ = x) 
    int read() {
        int x = 0, f = 0;
        char c = gc();
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = 10 * x + c - '0', c = gc();
        return f ? -x : x;
    }
    char qu[55]; int qlen;
    template <class T> void print(T x) {
        if (!x) pc('0');
        if (x < 0) pc('-'), x = -x;
        while (x) qu[++qlen] = x % 10 + '0', x /= 10;
        while (qlen) pc(qu[qlen--]);
    }
    template <class T> void print(T x, char charset) {
        print(x), pc(charset);
    }
    struct Flusher {
        ~Flusher() {
          flush();
        }
    } flusher;
}
using namespace IO;
using namespace std;

//#define int long long
#define MAX_N (int) (1e5 + 7)
const int inf = 1e9 + 7;

int n , m;
vector<int> adj[MAX_N];
int num[MAX_N] , low[MAX_N] , tail[MAX_N];
bool found[MAX_N];
int H[MAX_N];
vector<vector<int>> P(MAX_N , vector<int> (20 , 0));
int timeDFS = 0;
int bridge = 0;

void DFS(int u , int father) {
    int child = 0;
    num[u] = low[u] = ++timeDFS;
    for (auto v : adj[u]) {
        if (v == father) continue;
        child++;
        if (!num[v]) {
            P[v][0] = u; 
            H[v] = H[u] + 1;
            DFS(v , u);
            low[u] = min(low[u] , low[v]);
            if (u == father) {
                if (child >= 2) found[u] = true;
            }
            else if (low[v] >= num[u]) found[u] = true;
        } 
        else low[u] = min(low[u] , num[v]);
    }
    tail[u] = timeDFS;
}

bool inside(int u , int v) {
    return (num[u] <= num[v] && num[v] <= tail[u]);
}
int find_ancestor(int u , int v) {
    if (H[u] < H[v]) swap(u , v);
    while (H[u] > (H[v] + 1)) {
        for (int k = 19 ; k >= 0 ; k--) {
            if (H[P[u][k]] > H[v]) {
                u = P[u][k];
                break;    
            }
        }
    }
    return u;
}

bool query1(int a , int b , int g1 , int g2) {
    if (num[g1] < num[g2]) swap(g1 , g2);   
    if (low[g1] != num[g1]) return true; 
    if ((inside(g1 , a) && inside(g1 , b)) || (!inside(g1 , a) && !inside(g1 , b))) return true;
    if (inside(g1 , a) && !inside(g1 , b)) return false;
    if (inside(g1 , b) && !inside(g1 , a)) return false;
    //return true;
}

bool query2(int a , int b , int c) {
    if (found[c]) {
        int ances_a = 0 , ances_b = 0;
        if (inside(c , a)) ances_a = find_ancestor(a , c); 
        if (inside(c , b)) ances_b = find_ancestor(b , c);
        //cerr << "DEBUG";
        if (!ances_a && !ances_b) return true;
        if (ances_a == ances_b) return true;
        if (!ances_a && low[ances_b] < num[c]) 
            return true;
        if (!ances_b && low[ances_a] < num[c])
            return true;
        if (ances_a && ances_b && low[ances_a] < num[c] && low[ances_b] < num[c]) 
            return true;
        return false;
    }
    else return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    n = read();
    m = read();
    for (int i = 1 ; i <= m ; i++) {
        int u , v; u = read(); v = read();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1 , 1);
    P[1][0] = 1;
    for (int k = 1 ; k <= 19 ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            P[i][k] = P[P[i][k - 1]][k - 1]; 
        }
    }
    int q; q = read();
    while (q--) {
        int ask; ask = read();
        if (ask == 1) {
            int a , b , g1 , g2; a = read(); b = read(); g1 = read(); g2 = read(); 
            if (query1(a , b , g1 , g2)) printf("yes\n");
            else printf("no\n");
        }
        else {
            int a , b , c; a = read(); b = read(); c = read();
            if (query2(a , b , c)) printf("yes\n");
            else printf("no\n");
        }
        //cerr << "DEBUG";
    }
    return 0;
}