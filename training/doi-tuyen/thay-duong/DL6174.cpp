#include<bits/stdc++.h>
using namespace std;
 
int k = 1 , a;

int kaprekarRec(int n, int &prev)
{
    if (n == 0)
       return 0;
 
    prev = n;
 
    int digits[4];
    for (int i=0; i<4; i++)
    {
       digits[i] = n%10;
       n = n/10;
    }
 
    sort(digits, digits+4);
    int asc = 0;
    for (int i=0; i<4; i++)
       asc = asc*10 + digits[i];
    sort(digits, digits+4, std::greater<int> ());
    int desc = 0;
    for (int i=0; i<4; i++)
       desc = desc*10 + digits[i];
 
    int diff = abs(asc - desc);
 
    if (diff == prev)
        return diff;
    k++;
    return kaprekarRec(diff, prev);
}

int kaprekar(int n)
{
    int prev = 0;
    kaprekarRec(n, prev);
    return k;
}
 
int main()
{
    freopen("DL6174.inp","r",stdin);
    freopen("DL6174.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    cout << kaprekar(a);
    return 0;
}