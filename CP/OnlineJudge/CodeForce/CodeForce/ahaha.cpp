#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
  FAST;
    ll t;
    cin>>t;
    while(t--)
    {
        int n,o=0,z=0;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i])    o++;
            else    z++;
        }
        if(o>z)
        {
            if(o%2)
                o--;
            cout<<o<<endl;
            for(int i=1;i<=o;i++)
                cout<<1<<" ";
            cout<<endl;
        }
        else
        {
            cout<<z<<endl;
            for(int i=1;i<=z;i++)
                cout<<0<<" ";
            cout<<endl;
        }
    }
    return 0;
}