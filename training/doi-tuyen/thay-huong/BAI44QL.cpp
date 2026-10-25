#include <bits/stdc++.h>
using namespace std;

string X;
int n;

void Write()
{
    for(int i = 1;i<=n;i++){cout<<X[i];}
    cout<<endl;
}

void Try(int i)
{   
    char j;
    for (j = 65; j <= 66; j++)
    {
        if((X[i - 1] != 'B' && j == 'B') || j == 'A')
            {
                X[i] = j;
                if(i == n) Write();
                else Try(i + 1);
            }

    }
}
int main()
{   
    freopen("BAI44QL.INP", "r", stdin);
    freopen("BAI44QL.OUT", "w", stdout);

    cin >> n;
    Try(1);
    return 0;
}
