//source:: 
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e7 + 7;
const int MOD = 1e9 + 7;
const int MAX_PR = 30000000;

bitset<MAX_PR> isprime;
vector<int> p;
vector<int> eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vector<int> pr;
	for (int i = 2 ; i < lim ; i++) if (isprime[i]) pr.push_back(i);
	return pr;
}

int cnt_factorial(int N , int x) {
    int num = 0;
    int a = x;
    while (x <= N) {
        num += N/x;
        if (LLONG_MAX/x)
        x *= a;
    }
    return num;
}

bool solve(int N , int M) {
    // legendre formula : the largest power of p[i] of factorial n!
    // ans = sigma(1 -> oo): N//p[i] + N//(p[i]^2) + N//(p[i]^3) + ... + N//p[i]^k
    if (M == 1) return true;
    if (M == 0) return false;
    for (int i = 0 ; i < (int) p.size() && p[i]*p[i] <= M ; i++) {
        int cnt = 0;
        while (M % p[i] == 0) {
            M /= p[i];
            cnt ++; 
        }
        int num = cnt_factorial(N , p[i]);
        //cerr << p[i] << " " << cnt << " " << num << '\n';
        if (cnt > num) return false;
    }
    //cerr << M << '\n';
    if (M != 1) {
        int num = cnt_factorial(N , M);
        //cerr << M << " " << 1 << " " << num << '\n';
        return (num >= 1);
    }
    return true;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    p = eratosthenesSieve(30000000);
    int test = 1;
    while (test--) {
        int n , m; 
        while (cin >> n >> m) {
            if (solve(n , m)) cout << m << " divides " << n << "!\n";
            else cout << m << " does not divide " << n << "!\n";
            //cout << solve(n , m) << '\n';
        }
        
    }
    return 0;
}