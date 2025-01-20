//source:: https://vjudge.net/problem/UVA-12043
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

bitset<1000000> isPrime;
vector<int> p;
int sumDiv[N];
int numDiv[N];

void eratosthenes(int lim)  {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 4 ; i < lim ; i+=2) isPrime[i] = 0;
    for (int i = 3 ; i*i < lim ; i += 2) {
        if (isPrime[i])
            for (int j = i * i ; j < lim ; j += i * 2) {
                isPrime[j] = 0;
            }   
    }
    
    for (int i = 2 ; i < lim ; i++) {
        if (isPrime[i]) {
            p.push_back(i);
        }
    }
}

int num(int n) {
    int ans = 1;
    for (int i = 0 ; i < ((int) p.size()) && (p[i]*p[i] <= n) ; i++) {
        if (n % p[i] == 0) {
            int power = 0;
            while (n % p[i] == 0) {
                n/=p[i];
                power++;
            }
            ans *= (power + 1);
        }
    }
    return (n != 1 ? 2*ans : ans);
}

int sum(int n) {
    int ans = 1;
    for (int i = 0 ; i < ((int) p.size()) && (p[i]*p[i] <= n) ; i++) {
        if (n % p[i] == 0) {
            int total = 1;
            int multi = p[i];
            while (n % p[i] == 0) {
                n/=p[i];
                total += multi;
                multi *= p[i];
            }
            ans *= total;
        }
    }
    if (n != 1) ans *= (n + 1);
    return ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthenes(N);
    int test; cin >> test;
    for (int i = 1 ; i < N ; i++) {
        numDiv[i] = num(i);
        sumDiv[i] = sum(i);
        //cout << numDiv[i] << " ";
    }
    //cerr << "YES";
    while (test--) {
        int a , b , k; cin >> a >> b >> k;
        int div = a / k;
        if (a % k != 0) div++; 
        div *= k;
        int res_1 = 0 , res_2 = 0;
        for (int i = div ; i <= b ; i += k) {
            res_1 += numDiv[i]; 
            res_2 += sumDiv[i];
        }
        cout << res_1 << " " << res_2 << '\n';
    }
    return 0;
}