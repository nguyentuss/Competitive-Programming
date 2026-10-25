#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int distinct_patterns_count(const string &N_str, int M, int P) {
    int cycle_length = P;
    for (int i = 2; i <= P; ++i) {
        if (P % i == 0 && mod_exp(2, i, P) == 1) {
            cycle_length = i;
            break;
        }
    }

    int N_mod_cycle_length = 0;
    for (char c : N_str) {
        N_mod_cycle_length = (N_mod_cycle_length * 10 + (c - '0')) % cycle_length;
    }

    int result = mod_exp(2, N_mod_cycle_length * M, P);
    return result;
}

main() {
    string N_str;
    int M, P;
    cin >> N_str >> M >> P;

    int result = distinct_patterns_count(N_str, M, P);
    cout << result << endl;
    return 0;
}
