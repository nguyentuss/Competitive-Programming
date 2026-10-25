#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
long long  power(long long  x, unsigned long long  y, long long  p) 
{ 
    long long  res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or 
                // equal to p 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  

bool miillerTest(long long  d, long long  n) 
{ 
    long long  a = 2 + rand() % (n - 3); 
  
    // Compute a^d % n 
    long long  x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 

    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    // Return composite 
    return false; 
} 

bool isPrime(long long  n, long long  k) 
{ 
    // Corner cases 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  
    // Find r such that n = 2^d * r + 1 for some r >= 1 
    long long  d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  
    // Iterate given nber of 'k' times 
    for (long long  i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
} 
  
int  main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    long long  k = 4; 
    long long  t , n; 
    cin >> t;
    for (int i = 0 ; i < t ; i++) 
    {
        scanf("%lld",&n);
        if (isPrime(n , k)) printf("YES\n");
        else printf("NO\n");
    }

    return 0; 
} 