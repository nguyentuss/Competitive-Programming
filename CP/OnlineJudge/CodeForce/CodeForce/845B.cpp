#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second

//const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int ans = 6;
    string str = "";
    int cc = 0;
    for (int i = 0 ; i < 1e6 ; i++) {
        int tm = i;
        //cout << i << " ";
        str = "";
        while (tm > 0) {
            int x = tm%10;
            char a = x + '0'; 
            str = a + str;
            tm /= 10;
        }
        while (str.size() < 6) {
            str = '0' + str;
        }
        int sum_a = 0 , sum_b = 0;
        for (int j = 0 ; j < 3 ; j++) {
            int x = str[j];
            sum_a = sum_a + x - '0';
        }
        for (int j = 3 ; j < 6 ; j++) {
            int x = str[j];
            sum_b = sum_b + x - '0';
        }
        if (sum_a == sum_b) {
            int diff = 0;
            for (int j = 0 ; j < 6 ; j++) {
                if (str[j] != s[j]) {
                    diff++;
                }
            }
            if (ans > diff) {
                ans = diff;
                cc = i;
            }
        }
        //cerr << i << " ";
    }
    //cout << cc << " ";
    cout << ans;
    return 0;
}