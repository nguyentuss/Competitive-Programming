#include<bits/stdc++.h>
using namespace std;

long long n , t  , ok = 0;
bool kt (long long t)
{
    if ( t == 1 || t == 0 ) return 0;
    for (int i = 2 ; i * i <= t ; i++ ) 
        if ( t % i == 0 ) return 0;
    return 1;
}

void backtrack(int i)
{
    for (int i = 0 ; i < 10 ; i++ )
    {
        if (kt(t * 10 + i))
        {
            t = t * 10 + i ;
            if (vt == n) cout << t << endl , ok = 1;
            else backtrack(vt + 1);
            t /= 10;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n ;
    backtrack(1);
    if (ok == 0) cout << -1;
}

