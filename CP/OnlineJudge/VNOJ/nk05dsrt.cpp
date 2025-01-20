#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define oo (int) (1e9 + 7)
#define fi freopen("test.inp","r",stdin)
#define fo freopen("test.out","w",stdout);

struct edge{
	int u , v , w;
};

int n , m , c;
vector <ii> adj[1008];
vector <ii> D(1008);
vector <ii> readj[1008];
vector <int> node;
map <ii , int> visited;
vector<edge> saved;
bool checked = false;
ii e;
void init() {
    for (int i = 1 ; i <= m ;i++) {
        D[i].first = oo;
        adj[i].clear();
    }
    visited.clear();
    node.clear();
    return;
}

/*
nếu A+L <= C, trả về A+L
nếu C <= 2L, trả về invalid amount
còn lại, tính t = ceil(A+L-C / C-2L), rồi trả về (2t+1)L + A
cách giải thích là ta thấy để có lượng nước A từ ốc đảo 1 tới ốc đảo 2, độ dài 1-2 là L, 
lượng nước tối đa mang được là C thì các trường hợp dễ thấy là nếu A+L <= C thì ko cần đi 
vòng (số lần đi vòng là t) mà mang thẳng lượng nước A+L từ ốc đảo 1 qua ốc đảo 2 luôn.
Còn nếu ko thì phải đi vòng. Một lần đi vòng tốn 2L nước. Nếu C <= 2L thì mỗi lần đi chả 
tích cóp được tí nước nào nên trả về invalid amount, và sẽ coi như là ko có đường đi giữa 
2 ốc đảo này. Nếu C > 2L thì ví dụ A=16, L=11, C=24, viết giấy ra ta thấy:
phải đi 2 vòng. Số lượng nước cần có ở ốc đảo 1 là 24+24+23=71, hay cũng chính là 16+22+22+11.
Nếu biết số lần đi vòng ít nhất (t) thì lượng nước trả về là A + (2t+1)L
bây giờ đi tìm t. Lượng nước tích cóp được sau t vòng là t(C - 2L), 
vì mỗi vòng đi tích cóp được C-2L lít. Vì A+L > C, 
nên lượng nước cần tích cóp phải >= A+L-C, tốt nhất là bằng,
 nhưng nếu lớn hơn cũng ko sao, nếu ít hơn thì ko được. Vậy ta có công thức
t(C-2L) >= A+L-C
t >= (A+L-C) / (C-2L)
để t min thì t chính là ceil của (A+L-C) / (C-2L). 
Ví dụ A=16, L=11, C=24, A+L-C = 3, C-2L = 2, 3/2 = 1.5, ceil(1.5) = 2. 
Số lần đi vòng là 2. Số lượng nước cần có ở ốc đảo 1 là (2*2+1)*11 + 16 = 55+16 = 71.
*/

int ceil(int a, int b) //return ceil(a/b)
{
    return a/b + (a%b != 0);
}

int getNeededAmount(int A, int L, int C)
{
    if (A+L <= C) return A+L;
    if (C <= 2*L) return -1;
    int t = ceil(A+L-C, C-2*L);
    return (2*t+1)*L + A;
}

void dijkstra() {
    priority_queue<ii , vector<ii> , greater<ii>> pq;
    D[1].first = 0;
    D[1].second = 0;
    pq.push(ii(0 , 1));
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        for (auto e : adj[u]) {
            int v = e.second;
            int uv = e.first;
            if (D[v].first > du + uv) {
                D[v].first = du + uv;
                D[v].second = u;
                pq.push(ii(D[v].first , v));
            }
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    //fi;fo;
    int test ; cin >> test;
    while (test--) {
        cin >> n >> m >> c;
        init();
        int u , v , w;
        for (int i = 1 ; i <= m ; i++) {
            cin >> u >> v >> w;
            adj[u].push_back(ii(w , v));
            adj[v].push_back(ii(w , u));
            visited[ii(u , v)] = w; 
        }
        dijkstra();
        node.push_back(n);
        int pos = D[n].second;
        while (pos != 0) {
           node.push_back(pos);
            pos = D[pos].second;
        }
        reverse(node.begin() , node.end());
        for (int i = 0 ; i < (int) node.size() - 1 ; i ++) {
        	if (visited[ii(node[i] , node[i + 1])] > 0) 
        		saved.push_back((edge) {node[i] , node[i + 1] , visited[ii(node[i] , node[i + 1])]});		
        }
        int len = saved.size();
        vector <int> temp(len + 1);
        temp[len] = 0;
        for (int i = len ; i >= 1 ; i --) {
            temp[i - 1] = getNeededAmount(temp[i] , saved[i - 1].w , c);
        }
        //for (int i = 0 ; i < (int) temp.size() ; i++) cout << temp[i] << " ";
        cout << temp[0] << '\n';
    }

    return 0;
}