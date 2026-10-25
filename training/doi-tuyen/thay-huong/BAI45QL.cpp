#include <bits/stdc++.h>
using namespace std;

int n, dem = 0, A[15], k, K[14];
bool VN = true;
bool Check()
{
    int T[30] = {0};
    for(int i = 1; i <= n; i++)
    {
        T[K[i]] += A[i];
    }
    for(int i = 2; i <= k; i++)
    { 
        if(T[i] != T[i - 1])
        return false;
    }
    return true;
}

void GhiNghiem()
{  
    if (!Check()) return;
    for(int i = 1; i <= k; i++)
        {   
            for(int j = 1; j <= n; j++)
            {
                if(K[j] == i) cout << A[j] << " ";
            }
            cout << endl;
        }
        VN = false;
}

void Try(int i)
{
    for (int j = 1; j <= k; j++)
    {
        K[i] = j;
        if(i == n) GhiNghiem();
        else Try(i + 1);
        if (!VN) return;
    }
}
int main()
{   
    freopen("BAI45QL.INP", "r", stdin);
    freopen("BAI45QL.OUT", "w", stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {cin>>A[i];}
    Try(1);
    if(VN==true)cout<<-1;
return 0;
}
