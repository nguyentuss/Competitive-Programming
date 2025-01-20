#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >>n;
	cout <<(int) (floor((2*pow(n , 3.0) + 5*pow(n,2.0) + 2.0*n)/8.0) 
	+ 2*floor((pow(n , 3.0) - 1.0/(3.0*n))/2.0) + 6*(n*(n+1)*(n+2)/6.0               
    + floor((2*pow(n , 3.0) + 5*pow(n , 2.0) + 2*n)/8.0) 
    + floor((2*pow(n , 3.0) + 3*pow(n , 2.0) - 3*n)/18.0)
    + floor((2*pow(n , 3.0) + 3*pow(n , 2.0) - 3*n)/10.0))
	+ 3*floor((22*(n , 3.0) + 45*pow(n , 2.0) - 4*n)/48.0));

	cout << floor((2*n*n*n + 5 + 2n)/8) + 2*floor( (n^3 - 1/3 n)/2 )

          + 6*(  n*(n+1)*(n+2)/6               
               + floor( (2 n^3 + 5 n^2 + 2 n)/8 ) 
               + floor( (2 n^3 + 3 n^2 - 3 n)/18 )
               + floor( (2 n^3 + 3 n^2 - 3 n)/10 )  )

          + 3 * floor( (22 n^3 + 45 n^2 - 4 n)/48 )



	return n;
}