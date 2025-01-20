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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int anagramic[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};

void solve() {
    int size = 22;
    int wanted;
    
    while (cin >> wanted && wanted != 0) {
        int best = size;
        for (int i = size - 1; i >= 0 && anagramic[i] > wanted; --i, --best);
        if (best < size)
        {
            int max = 1;
            while (wanted)
            {
                wanted /= 10;
                max *= 10;
            }
            
            if (anagramic[best] < max)
                cout << anagramic[best] << '\n';
            else
                cout << 0 << '\n';
        }
        else cout << 0 << '\n';
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