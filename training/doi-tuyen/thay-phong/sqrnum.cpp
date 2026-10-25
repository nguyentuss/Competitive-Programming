#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int sieve[MAX_N];
vector<int> v;
int minPrime[MAX_N];
int odd = 0;
int func[MAX_N];
bool previ = false;
int numodd = 0;
int IT[4 * MAX_N];

void eratosthene() {
    for (int i = 2 ; i * i < MAX_N ; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i ; j < MAX_N ; j+=i) {
                if (minPrime[j] == 0)
                    minPrime[j] = i;
            }
        }
    }
    for (int i = 2 ; i < MAX_N ; i++) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    return;
}

void update(int id , int i , int L , int R , int val) {
    if (i > R || i < L) return;
    if (L == R) {
        IT[id] = val; 
        return;
    }
    int mid = (L + R)/2;
    update(2 * id , i , L , mid , val);
    update(2 * id + 1 , i , mid + 1 , R , val);
    IT[id] = IT[2 * id] + IT[2 * id + 1];
}

bool calc(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n/= minPrime[n];
    }
    res.push_back(0);
    int sl = 0 , num = 0;
    bool found = true;
    for (int i = 0 ; i < (res.size() - 1) ; i++) {
        if (res[i] != res[i + 1]) {
            sl++;
            num = res[i];
            if ((func[num] + sl) % 2 != 0) {
                update(1 , num , 1 , MAX_N , 1);
            }
            else update(1 , num , 1 , MAX_N , 0);
            func[num] += sl;
            sl = 0;
            num = 0;
        }   
        else {
            sl++;
            num = res[i];
        }
    }
    if (!IT[1]) return 1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    eratosthene();
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        bool cm = calc(x);
        if (cm) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}