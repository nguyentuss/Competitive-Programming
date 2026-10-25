#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define modulo (unsigned long long) (1e9 + 7)

unsigned long long a , n , ans; 

unsigned long long solve(unsigned long long x) {
    if (x == 1) return a%modulo;
    unsigned long long power = solve((x / 2)%modulo)%modulo;
    if (x % 2 != 0) return ((solve((x / 2 + 1)%modulo)%modulo)*power%modulo)%modulo;
    else return (power%modulo*power%modulo)%modulo;
}

int main(){
    boost;
    cin >> a >> n;
    cout << solve(n)%modulo;
    return 0;
}