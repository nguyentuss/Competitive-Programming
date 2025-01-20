#include <iostream>

using namespace std;

bool check (long long a) 
{
	if (a<2) return 0;
	else	for (long long i = 2 ; i * i <= a ; i ++) 
				if (a % i == 0) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	
	freopen("sntnn.inp","r",stdin);
	freopen("sntnn.out","w",stdout);

	long long n ; cin >> n;
	
		while (1) 
		{
			if (check(n)) {
				cout << n;
				return 0;
			}
			else n ++;
		}

	return 0;
}