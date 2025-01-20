#include <iostream>
#include <math.h>

using namespace std;

const int oo=1e9;

int max4(int x, int y ,int z, int t)
{
    return max(max(x,y),max(z,t));
}

int a[57][57];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) 
    {
        int n,m;
        int maxA=-oo,ans=oo;
        cin>>n>>m;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                cin>>a[i][j];
                if (a[i][j]==maxA)
                {
                    int x1=i,x2=j,x3=n-i+1,x4=m-j+1;
                    ans=min(ans,max4(x1*x2,x2*x3,x3*x4,x4*x1));
                }
                else if (a[i][j]>maxA)
                {
                    maxA=max(a[i][j],maxA);
                    int x1=i,x2=j,x3=n-i+1,x4=m-j+1;
                    ans=max4(x1*x2,x2*x3,x3*x4,x4*x1);
                }
            }
            cout<<ans<<"\n";
    }
    return 0;
}