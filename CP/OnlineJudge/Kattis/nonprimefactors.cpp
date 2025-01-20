//source:: https://open.kattis.com/problems/nonprimefactors
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,popcnt")

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e9 + 7;
const int N = 2e6 + 7;
const int MOD = 1e9 + 7;

int cntP[N];
int numDiv[N];
vector<int> p;

void sieve() {
    for (int i = 2 ; i < N ; i++) {
        if (cntP[i] == 0)
            for (int j = i ; j < N ; j+=i) {
                cntP[j] ++;
            }
    }
    for (int i = 2 ; i < N ; i++) {
        if (cntP[i] == 1) {
            p.push_back(i);
        }
    }
}

int num(int n) {
    int ans = 1;
    for (int i = 0 ; i < (int) p.size() && p[i] * p[i] <= n ; i++){
        int power = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            power++;
        }
        ans *= (power + 1);
    }
    if (n != 1) ans *= 2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin.exceptions(cin.failbit);
    sieve();
    for (int i = 1 ; i < N ; i++) {
        numDiv[i] = num(i);
    }
    int test; cin >> test;
    while (test--) {
        int n; cin >> n;
        cout << numDiv[n] - cntP[n] << '\n';
    }
    return 0;
}