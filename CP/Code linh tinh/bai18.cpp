#include <bits/stdc++.h>
using namespace std;

bool a[405][405] = {{false}};
int n , dt  = 0;
void phuhcn(int x1,int y1,int x2,int y2){
	for (int i = x1 ; i < y1 ; i++)
		for (int j = x2 ; j < y2 ; j++)
			a[i][j] = true;
}

int main(){
	freopen("bai18.inp","r", stdin);
	freopen("bai18.out","w",stdout);
	int d1,c1,d2,c2;
	scanf("%d",&n);
	for (int i = 1 ; i<=n ; i ++){
		scanf("%d %d %d %d",&d1,&c1,&d2,&c2);
		phuhcn(d1+100,c1+100,d2+100,c2+100);
	}
	for (int i = 0; i <= 200 ; i++)
		for (int j = 0 ; j <= 200; j ++)
			if (a[i][j] == true){
				dt ++;
			}
	printf("%d",dt);
	return 0;
}