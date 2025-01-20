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
const int N = 32000 + 100;
const int MOD = 1e9 + 7;

bool isPrime[N] ;
vector <int> prime , ana;
void sieve() {
    isPrime[0] = 1;
    isPrime[1] = 1;
    for(int i = 4 ; i < N ; i += 2)
        isPrime[i] = 1 ;
    for(int i = 3 ; i * i < N ; i += 2) {
        if(!isPrime[i]) {
            for(int j = i * i ; j < N ; j += 2*i) {
                isPrime[j] = 1;
            }
        }
    }
    prime.push_back(2) ;
    for(int i = 3 ; i < N ; i += 2 ) {
        if(!isPrime[i]) {
            prime.push_back(i);
        }
    }
}

main() {
    sieve() ;
    int x , y ;
    while(cin >> x >> y && x && y) {
        if(x == 0 && y == 0)
            break ;
        if(x > y) 
            swap(x , y) ;
        int i = 0 ;
        while(prime[i] < x)
            i++ ;
        while(prime[i + 2] <= y) {
            if(prime[i + 2] - prime[i + 1] == prime[i + 1] - prime[i]) {
                int start = i ;
                int end = i + 2 ;
                int diff = prime[i + 1] - prime[i] ;
                while(i + 3 < prime.size() && prime[i + 3] - prime[i + 2] == diff) {
                    end++ ;
                    i++ ;
                }
                if(prime[end] <= y) {
                    if(start == 0 || prime[start] - prime[start - 1] != diff) {
                        cout << prime[start] << " ";
                        for(int i = start + 1 ; i <= end ; i++) {
                            cout << prime[i] << " ";
                        }
                        cout << '\n';
                    }
                }
                else 
                    break ;
            }
            i++ ;
        }
    }
    return 0 ;
}