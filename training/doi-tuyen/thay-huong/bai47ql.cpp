#include <bits/stdc++.h>
using namespace std;

char x[20];
int n,sum=0;

void out()
{
	for (int i=1;i<=2*n;i++) cout <<x[i];
	cout << endl;
}

void Try(int i)
{
    for (char j='(';j<=')';j++)
    {
    	if (sum<=0)
        {
    		x[i]=j;
    		if (x[i]=='(') sum-=1;
    		if (x[i]==')') sum+=1;
    		if (i/2==n){ if (sum==0) out();}
    		else Try(i+1);
    		if (x[i]=='(') sum+=1;
    		if (x[i]==')') sum-=1;
    	}

    }
}

int main (){
	freopen("BAI47QL.INP","r",stdin);
	freopen("BAI47QL.OUT","w",stdout);
    cin >>n;
    Try(1);
    return 0;
}