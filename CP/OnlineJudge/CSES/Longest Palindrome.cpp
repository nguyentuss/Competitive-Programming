//
// Created by tuloc on 3/25/2024.
//
#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1e6 + 5;
int D_odd[MaxN];
int D_even[MaxN];
string S;
int N;
int bestl = 1 , bestr = 1;

//abaxabaxab

void Calc_D_odd() {
    int L = 1;
    int R = 0;
    for(int i = 1 ; i <= N ; i++) {
        if(i > R) D_odd[i] = 0;
        else D_odd[i] = min(R - i, D_odd[L + (R - i)]);
        //if (i == 8) cout << D_odd[i];
        while(i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= N && S[i - D_odd[i] - 1] == S[i + D_odd[i] + 1]) {
            D_odd[i]++;
        }
        if (D_odd[i] * 2 + 1 > bestr - bestl + 1) {
            bestl = i - D_odd[i];
            bestr = i + D_odd[i];
        }
        if(i + D_odd[i] > R) {
            R = i + D_odd[i];
            L = i - D_odd[i];
        }
    }
}

void Calc_D_even() {
    int L = 1;
    int R = 0;
    for(int i = 1 ; i < N ; i++) {
        int j = i + 1;
        if(j > R) D_even[i] = 0;
        else D_even[i] = min(R - j + 1, D_even[L + (R - j)]);
        while(i - D_even[i] > 0 && j + D_even[i] <= N && S[i - D_even[i]] == S[j + D_even[i]]) {
            D_even[i]++;
        }
        if (D_even[i] * 2 > bestr - bestl + 1) {
            bestl = i - D_even[i] + 1;
            bestr = i + D_even[i];
        }
        if(i + D_even[i] > R) {
            R = i + D_even[i];
            L = j - D_even[i];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> S;
    N = S.length();
    S = ' ' + S; // for 1-base
    Calc_D_odd();
    Calc_D_even();
    int ans = 0;
    for (int i = bestl ; i <= bestr ; i++) {
        cout << S[i];
    }
}