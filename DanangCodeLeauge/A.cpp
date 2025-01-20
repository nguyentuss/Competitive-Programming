#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define taskname ""
#define pb push_back
#define pp pop_back
#define w(t) while (t--)
#define aint(a) (a).begin(), (a).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define pii pair<int,int>
#define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
vector <int> g[1000005];
void edge() {int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);}
inline void file_inp(const string FILE = "Test") { freopen((FILE + ".INP").c_str(), "r", stdin);  }
inline void file_out(const string FILE = "Test") { freopen((FILE + ".OUT").c_str(), "w", stdout); }
inline void file    (const string FILE = "Test") { file_inp(FILE); file_out(FILE); }

string str(int num){int a = num;stringstream ss;ss << a;string str = ss.str();return str;}

int dx[4]={-1,0,1, 0};
int dy[4]={ 0,1,0,-1};

struct ms {
    int val,pos;
};
bool cmp (ms a,ms b){
    return (a.val<b.val || (a.val==b.val&&a.pos<b.pos));
}

int binpower(int base, int e, int mod) {int result = 1;base %= mod;while (e){if (e & 1)result = (int)result * base % mod;base = (int)base * base % mod;e >>= 1;    }return result;}
bool check_composite(int n, int a, int d, int s) {int x = binpower(a, d, n); if (x == 1 || x == n - 1)return false;for (int r = 1; r < s; r++) {x = (int)x * x % n;if (x == n - 1)return false;}return true;};
bool checkprime(int n) {if (n < 2)return false;int r = 0;int d = n - 1;while ((d & 1) == 0) {d >>= 1;r++;}for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {if (n == a)return true;if (check_composite(n, a, d, r))return false;}return true;}
bool checksqr(int k){return (trunc(sqrt(k))*trunc(sqrt(k))==k);}

int lcm(int a, int b){return (a*b)/__gcd(a,b);}
int sum(int n) {return n*(n+1)/2;}

const int maxn=1000000;    


/*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*/

const int MODULO = 1e9 + 7;

int modularExponentiation(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % MODULO;
        }
        exponent >>= 1;
        base = (base * base) % MODULO;
    }
    return result%MODULO;
}

main() {
    int gridSize;
    cin >> gridSize;
    vector<vector<int>> grid(gridSize + 1, vector<int>(gridSize + 1, 0));

    for (int row = 1; row <= gridSize; row++) {
        for (int col = 1; col <= gridSize; col++) {
            char ceint;
            cin >> ceint;
            if (ceint == '.') {
                grid[row][col] = 0;
            }
            else grid[row][col] = 1;
        }
    }
    vector<int> f(1007);
    for (int i = 1 ; i < 1007 ; i++) {
        f[i] = modularExponentiation(i , i)%MODULO;
    } 
    int maxRowSum = 0;
    for (int row = 1; row <= gridSize; row++) {
        int rowSum = 0;
        int col = 1;
        while (col <= gridSize) {
            while (col <= gridSize && grid[row][col] == 0) {
                col++;
            }
            int count = 0;
            while (col <= gridSize && grid[row][col] == 1) {
                count++;
                col++;
            }
            rowSum = (f[count] + rowSum) % MODULO;
        }
        maxRowSum = max(rowSum, maxRowSum) % MODULO;
    }

    int maxColSum = 0;
    for (int col = 1; col <= gridSize; col++) {
        int colSum = 0;
        int row = 1;
        while (row <= gridSize) {
            while (row <= gridSize && grid[row][col] == 0) {
                row++;
            }
            int count = 0;
            while (row <= gridSize && grid[row][col] == 1) {
                count++;
                row++;
            }
            colSum = (f[count] + colSum) % MODULO;
        }
        maxColSum = max(colSum, maxColSum) % MODULO;
    }

    cout << maxRowSum << " " << maxColSum;
}