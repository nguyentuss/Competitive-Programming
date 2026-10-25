#include <bits/stdc++.h>
using namespace std;

struct data
{
    int ch_1;
    int ch_A;
    int ch_a;
} pass[1000006];

int check_safe (int begin, int end)
{
    int num_1= pass[end].ch_1-pass[begin-1].ch_1;
    int num_a= pass[end].ch_a-pass[begin-1].ch_a;
    int num_A= pass[end].ch_A-pass[begin-1].ch_A;
    if (num_1>0 && num_a>0 && num_A>0 && end-begin+1>=6) return 1;
    else return 0;
}

int cnp(int begin,int front,int back)
{
    int vt=-1;
    while (front<=back&&back-begin+1>=6)
    {
        int mid=(front+back)/2;
        if (check_safe(begin,mid)==1)
        {
            vt=mid;
            back=mid-1; 
        }
        else front=mid+1;
    }
    return vt;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("matkhau.inp","r",stdin); 
    freopen("matkhau.out","w",stdout);
    string xau;
    cin >> xau;
    pass[0].ch_1=0;
    pass[0].ch_a=0;
    pass[0].ch_A=0;
    int n=xau.length();
    for (int i=1; i<=n; i++)
        if (xau[i-1]>='0' && xau[i-1]<='9')
        {
            pass[i] = pass[i-1];
            pass[i].ch_1++; 
        }
        else if (xau[i-1]>='a' && xau[i-1]<='z')
        {
            pass[i] = pass[i-1];
            pass[i].ch_a++;
        }
        else if (xau[i-1]>='A' && xau[i-1]<='Z')
        {
            pass[i] = pass[i-1];
            pass[i].ch_A++;
        }
    long long count=0;
    for (int i=1; i<=xau.length()-6+1; i++)
    {
        int VT=cnp(i,i,n);
        if (VT!=-1)
        {
            count+=n-VT+1;
        } 
        else break;
    }
    return (cout << count,0);    
}