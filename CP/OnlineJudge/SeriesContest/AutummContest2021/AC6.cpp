#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("AC6.inp","r",stdin);
	//freopen("AC6.out","w",stdout);
	int t;
	cin >> t;
	while (t--)
	{
		long long a , b , n;
		cin >> a >> b >> n;
		if (!n) cout << 0 << '\n';
		else if (n < a && n < b) cout << -1 << '\n';
		else if ((!a && n % b)||(!b && n%a)) cout << -1 << '\n';
		else
		{
			long long g = __gcd(a,b);
			if (n % g) cout << "-1\n";
			else 
			{
				n /= g ;a /= g;b /= g;
				long long y=0;
				if ( a < b ) 
					swap(a , b);
				while ((n - b * y) % a) y++;
				if ((n-b*y)/a < 0) cout << -1 << '\n';
				else cout << (n-b*y)/a+y << '\n';
				//cout << (n - b*y)/a << " " << y << '\n';
			}
		}
	}
	return 0;
}