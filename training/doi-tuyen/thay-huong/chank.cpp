#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <utility>
#include <queue>
#include <map>
#include <assert.h>
#include <stack>
#include <string>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std ;

unsigned long long a[21],n,k,i;

int main() 
{

	freopen("chank.inp","r",stdin);
	freopen("chank.out","w",stdout);
	
	cin >> n >> k; 
	a[0]=1;
	for (i=1;i<=n;i++) a[i]=a[i-1]*i;
	cout << a[n] / a[n-k];

	return 0;

}