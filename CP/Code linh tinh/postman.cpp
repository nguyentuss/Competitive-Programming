#include <iostream>

using namespace std;

const int maxn = 1e7;
int x[maxn] , m[maxn],i,j;

void swap(int x[i], int x[j])
{
	int tam;
	tam = x[i];
	x[i] = x[j];
	x[j] = tam;
	tam = m[i];
	m[i] = m[j]; 
	m[j] = tam;
}

int qs(int l , int r)
{
	i = l ; j = r; 
	a = x[(l+r) / 2];
	do{
		while (x[i] < a) i++;
		while (x[j] > a) j--;
		if (i<=j){
			swap(x[i],x[j]);

			i++;
			j--;
		}
	while (i > j);
	if (l<j) qs(l,j);
	if (i<r) qs(i,r);
}



int main(){

	int n , k  ; cin >> n >> k;
	for (i = 1 ; i <= n ; i ++){
		cin >> x[i] >> m[i];
	}
	qs(1,n);

	for (i = 1 ;i <= n ; i ++)
		cout << x[i] << " " << m[i];


	return 0;
}