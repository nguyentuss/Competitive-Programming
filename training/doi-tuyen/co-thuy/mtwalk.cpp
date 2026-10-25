#include <bits/stdc++.h>
using namespace std;
int n;
int A[101][101],P[101][101];
int l,h;
int minp,maxp;
int maxa=0,mina=111;
pair <int,int> q[10001];

const vector <int> dxy{0,1,0,-1,0};

bool BFS(){
    int l=1,r=0;
    if(A[1][1]>=minp&&A[1][1]<=maxp)
    {
        P[1][1]=1;
        q[++r]=pair <int,int>(1,1);
    }
    while(l<=r)
    {
        pair <int,int> t=q[l++];
        int u=t.first,v=t.second;
        for(int p=0;p<4;p++)
        {
            int u1=u+dxy[p],v1=v+dxy[p+1];
            if(u1>0&&u1<=n&&v1>0&&v1<=n&&P[u1][v1]==0&&A[u1][v1]>=minp&&A[u1][v1]<=maxp)
            {
                if(u1==n&&v1==n) return 1;
                P[u1][v1]=1;
                q[++r]=pair <int,int>(u1,v1);
            }
        }
    }
    return 0;
}
bool get(int k)
{
    for(int i=mina;i<=maxa-k;i++)
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        P[i][j]=0;
        minp=i;
        maxp=i+k;
        if (BFS()) return 1;
    }
    return 0;
}

void process()
{
    while(h-l>1)
    {
        int mid=(h+l)/2;
        if(get(mid)) h=mid;
        else l=mid;
    }
    cout<<h;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("MTWALK.inp","r",stdin);
	freopen("MTWALK.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    	{
        	cin >> A[i][j];
        	maxa=max(maxa,A[i][j]);
        	mina=min(mina,A[i][j]);
    	}
    l=-1;
    h=maxa-mina;
    process();
    return 0;
  }