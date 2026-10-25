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

#pragma GCC optimize("Ofast")
const int oo = -1000111000;
typedef pair<int, int> ii;

vector<ii> a[500007];
int n, m;

int d[500007];

void dijkstra() {
    priority_queue<ii> pq;
    for (int i = 1; i <= n; i++)
        d[i] = oo;
    d[1] = -oo;
    pq.push(ii(-oo, 1));

    while (pq.size()) { 
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < (int) a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] < min(du,uv)) {
                d[v] = min(du,uv);
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main() {
    freopen("tinhcldd.inp","r",stdin);
    freopen("tinhcldd.out","w",stdout);
    int  m , ask;
    n = read();
    m = read();
    ask = read();
    for (int i = 1 ; i <= m ; i++){
        int p , q , w;
        p = read();
        q = read();
        w = read();
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w,p));
    }
   
    dijkstra();
    for (int i = 0 ; i < ask ; i++) {
        int asked;
        asked = read();
        print(d[asked] , '\n');
    }
    
    return 0;
}