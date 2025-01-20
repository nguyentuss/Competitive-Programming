//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2 ; i * i <= n ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int sum_divisor(int n) {
    int sum = 1;
    for (int i = 2 ; i * i <= n ; i ++) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;
            }
            else sum += i + n/i;
        }
    }
    return sum;
}

int pow(int k) {
    return (1 << k);
}

void solve() {
    int n; 
    while (cin >> n && n) {
        int f = (1LL << n) - 1;

		if (is_prime(f))
			cout << "Perfect: " << f * (1 << (n - 1)) << "!\n";
		else if(is_prime(n))
			cout << "Given number is prime. But, NO perfect number is available.\n";
		else
			cout << "Given number is NOT prime! NO perfect number is available.\n";
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}