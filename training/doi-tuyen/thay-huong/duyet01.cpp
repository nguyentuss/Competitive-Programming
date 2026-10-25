#include <bits/stdc++.h>
using namespace std;

struct dsk
{
    vector <long long> ke;
};
 
int n,m,u,v,s;
unordered_map <int,int> Free;

vector <dsk> a(2001);

void DFS(int i)
{
    cout << i << " ";
    Free[i]=1;
    for (int j=0;j<(int)a[i].ke.size();j++)
        if (!Free[a[i].ke[j]]) 
            DFS(a[i].ke[j]); 
}
 
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen ("DUYET01.inp","r",stdin);
    freopen ("DUYET01.out","w",stdout);
    cin >> n >> m;
    for (long long i=1;i<=m;i++)
    {
        cin >> u >> v;  
        a[u].ke.push_back(v);
        a[v].ke.push_back(u);
    }
    DFS(1);
    return 0;
}