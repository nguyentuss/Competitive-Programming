#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    double a , b , c; cin >> a >> b >> c;
    cout << "Sum :" << a + b + c << '\n';
    cout << "Product :" << a*b*c << '\n';
	cout <<  "Average :" << (double) ((double)(a+b+c)/(double)3.0) << '\n';
	cout << "Min :" << min({a , b , c}) << '\n';
    return 0;
}