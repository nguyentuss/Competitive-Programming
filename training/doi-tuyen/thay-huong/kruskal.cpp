#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

#define ii pair<int ,int>

struct val{
	long u,v,va;
};
val A[1000000],kq[1000000];
long maxn,minx,ans,nhan[1000000],d,n,m;
bool cmp(val c, val d){
	return c.va<d.va;
}
bool chon(long a){
	if(nhan[A[a].u]==nhan[A[a].v]) return false;
	else{
		maxn=max(nhan[A[a].u],nhan[A[a].v]);
		minx=min(nhan[A[a].u],nhan[A[a].v]);
		for(long j=1; j<=n; j++){
			if(nhan[j]==maxn) nhan[j]=minx;
		}
	}
	return true;
}
int main(){
	//freopen("city.inp","r",stdin);
	//freopen("city.out","r",stdin);
	cin>>n>>m;
	for(long i=1; i<=m; i++){
		cin>>A[i].u>>A[i].v>>A[i].va;
	}
	sort(A+1,A+m+1,cmp);
	for(long i=1; i<=n; i++) nhan[i]=i;
	for(long i=1; i<=n; i++){
		if(chon(i)){
			ans+=A[i].va;
			d+=1;
			kq[d].u=A[i].u;
			kq[d].v=A[i].v;
			kq[d].va=A[i].va;
		}
	}
	cout<< n - 1 << " " << ans<<endl;
	vector <ii> adj;
	for(long i=1; i<=d; i++){
		adj.push_back(ii(kq[i].u , kq[i].v));
	}
		sort(adj.begin() , adj.end());
		for (ii e : adj) {
			cout << e.first << " " << e.second << '\n';
		}

	return 0;
}