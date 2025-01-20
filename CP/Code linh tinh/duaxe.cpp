#include <iostream>
using namespace std;

const int maxn = 1000000;

long a[maxn] ;long n,i,l,r = 0 , ans = 0;

void findx(long k){
	l = k ;
	r = k;
	while ((l-1 >= 1) && (a[l] < a[l-1])) l--;
	while ((r + 1 <= n) && (a[r] < a[r+1])) r++;
}
int main(){

	scanf("%ld",&n);
	for (i = 1 ; i <= n ; i++)
		scanf("%ld",&a[i]);

	while (r < n){
		cout << r << " ";
		findx(r+1);
		i = r;
		while (a[i] > a[l]) {
			ans += a[i] - a[i-1];
			i --;
		}

	}
	printf("%ld",ans);
	return 0;

}