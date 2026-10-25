#include <bits/stdc++.h>
using namespace std;

struct dsk
{
    public: vector <long long> ke;
};
 
int n,m,u,v,s;
unordered_map <int,int> Free;
queue <int> q;
vector <dsk> a(2001);

void BFS(int s)
{
    q.push(s);
    Free[s]=1;
    while (!q.empty())
    {
        int i=q.front();
        q.pop();
        cout << i << " ";
        for (int j=0;j<a[i].ke.size();j++)
            if (!Free[a[i].ke[j]])
            {
                Free[a[i].ke[j]]=1;
                q.push(a[i].ke[j]);
            }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen ("DUYET02.inp","r",stdin);
    freopen ("DUYET02.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=m;i++)
    {
        cin >> u >> v;  
        a[u].ke.push_back(v);
        a[v].ke.push_back(u);
    }
    BFS(1);
    return 0;
}