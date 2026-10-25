#include<bits/stdc++.h>
using namespace std;

int d[11] = {0}, n, l = 0, k = 0;

void process(int vt)
{
    for (int i = 0; i <= 9; i++)
    {
        if (vt == 1 && i == 0) continue;
        if (d[i])
        {
            k = k * 10 + i;
            --d[i];
            if (vt == l) cout << k << endl;
            else process(vt + 1);
            ++d[i];
            k = k / 10;
        }
    }
}

int main(){
    //freopen(("BAI41QL.inp"), "r", stdin);
    //freopen("BAI41QL.out", "w", stdout);

    cin >> n;

    while (n)
    {
        ++d[n % 10], ++l, n /= 10;
    }
    process(1);
}