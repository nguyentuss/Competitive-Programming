#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define eps 1e-8
#define div divv

const int N = 3e5 + 5;
int a[N] , b[N] , c[N];
int t[N] , l[N] , r[N];

int main(int argc, char* argv[])
{
    registerValidation(argc , argv);
    int n = inf.readInt(1 , 3 * 100 * 1000 , "n");
    inf.readSpace();
    int m = inf.readInt(1 , 3 * 100 * 1000 , "m");
    inf.readEoln();
    FOR(i , 1 , n)
    {
        a[i] = inf.readInt(1 , 1000 * 1000 , "a[i]");
        if(i != n)
            inf.readSpace();
    }
    inf.readEoln();
    FOR(i , 1 , m) {
        t[i] = inf.readInt(1 , 2 , "t[i]");
        inf.readSpace();
        l[i] = inf.readInt(1 , 3 * 100 * 1000 , "l[i]");
        inf.readSpace();
        r[i] = inf.readInt(1 , 3 * 100 * 1000 , "r[i]");
        inf.readEoln();
    }
    inf.readEof();
}




