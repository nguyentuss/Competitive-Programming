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
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define eps 1e-8
#define div divv

/// control using cmd

int main(int argc , char *argv[])
{
    registerGen(argc , argv , 1);
    int n = atoi(argv[1]);
    int seed = atoi(argv[2]);
    cout << n << endl;
    FOR(i , 1 , n)
    {
        cout << rnd.wnext(1 , 1000 * 1000 * 1000 , seed);
        if(i != n)
            cout << " ";
    }
    cout << endl;
}


