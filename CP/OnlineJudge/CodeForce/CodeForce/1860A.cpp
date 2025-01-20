#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
        while(t--){
        string s;
        cin >> s;
        int n = s.size();
        string s1 , s2;
        s1 = s2 = "";
        if (s == "()"){
            cout << "NO" << '\n';
        }
        else{
            for (int i = 1; i <= n; i++){
                s1 = s1 + "()";
                s2 = s2 + "(";
            }   
            for (int i = 1; i <= n; i++){
                s2 = s2 + ")";
            }   
            cout << "YES" << '\n';
            if (s1.find(s) >= s1.length()){
                cout << s1 << '\n';
            }
            else cout << s2 << '\n';
        }
    }
    return 0;
}