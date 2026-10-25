#include <iostream>
#include <string>
using namespace std;
 
int n,x[20],i,j,l,m;
string a[20],t1,t2;
bool d[20],kt[20],k=0;

void check () 
{
    int kt[20]{0};
    for (int i = 1 ; i <= n ; i ++) cout << x[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) 
    {
        string t1=a[x[i]];
        string t2=a[x[i+1]];
        cout << t1 << " " << t2 << endl;
        for (l=0;l<t1.size();l++)
            for (m=0;m<t2.size();m++)
                if (t1[l]==t2[m]) {
                	kt[i]=1;
                	break;
                }
    }
    string t1=a[x[n]]; 
    string t2=a[x[1]];
    cout << t1 << " " << t2 << endl;
    for (int i=0;i<t1.size();i++)
        for (int j=0;j<t2.size();j++)
            if (t1[i]==t2[j]) kt[n]=1;          
    k=1;
    for (i=1;i<=n;i++)
        if (kt[i]==0) k=0; 
    if (k==1) for (i=1;i<=n;i++) cout << x[i] << endl;
}

void back (int i) 
{
    if (k) return;
    if (i==n+1) {check();return;}
    for (int j=1;j<=n;j++) 
        if (!d[j]) 
        {
            x[i]=j;
            d[j]=1;
            back(i+1);
            d[j]=0;
        }
}

int main () 
{
	ios::sync_with_stdio(0); cin.tie(NULL);
    freopen ("PARTY.inp","r",stdin);
    freopen ("PARTY.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    back(1);
    if (k==0) cout << "NO SOLUTION";
    return 0;
}