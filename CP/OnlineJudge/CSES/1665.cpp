//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;


/**
 * Author: Tus
 * Date: 2024-05-06
 * License: CC0
 * Source: Tus
 * Description: Trie
 * Can be changed to other things. 
 * Time: O(\log N).
 * Status: tested
 */

struct Trie {

    struct Node {
        Node *child[2]; // change here
        int cnt, exist;

        Node() {
            for (int i = 0 ; i < 2 ; i++) child[i] = NULL; 
            exist, cnt = 0;
        }
    };

    int cur;
    Node *root; 
    Trie() : cur(0) {
        root = new Node();
    };

    void add(string s) {
        Node *p = root;
        for (auto x : s) {
            int c = x - '0'; 
            if (p -> child[c] == NULL) p -> child[c] = new Node();
            p = p -> child[c]; 
            p -> cnt++;
        }
        p -> exist ++;
    }

    bool find_string(string s) {
        Node *p = root;
        for (auto x : s) {
            int c = x - '0'; // change here
            if (p -> child[c] == NULL) return false;
            p = p -> child[c];
        }
        return (p -> exist != 0);
    }

    bool delete_string_recursive(Node *p , string &s , int i) {
        if (i != (int)s.size()) {
            int c = s[i] - '0'; // change here
            bool isChildDeleted = delete_string_recursive(p -> child[c] , s , i + 1); 
            if (isChildDeleted) p -> child[c] = NULL;
        }
        else {
            p -> exist --;
        }

        if (p != root) {
            p -> cnt --;
            if (p -> cnt == 0) {
                delete(p); 

                return true;
            }
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return; 

        delete_string_recursive(root , s , 0);
    }
    // cmp maximum xor
    int cmp(string s) {
        Node *p = root; 
        int as = 0;
        int i = sz(s) - 1;
        for (auto x : s) {
            int c = x - '0'; 
            int op = c ^ 1;
            if (p -> child[op] != NULL) p = p -> child[op] , as = as | (1 << i);
            else if (p -> child[c] != NULL) p = p -> child[c];
            i --;
        }
        return as;
    }
    // can add sth here

};

trie

string change(int x) {
    string s = "";
    while (x) {
        int c = x % 2; 
        if (!c) s += '0'; 
        else s += '1';
        x /= 2;
    }
    while (sz(s) < 30) {
        s += '0';
    }
    reverse(s.begin() , s.end());
    return s;
}

// f(0 , r) = f(0 , l - 1) ^ f(l , r) 
// f(l , r) = f(0 , r) ^ f(0 , l - 1)

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    for (int &u : a) cin >> u;
    Trie tr;
    tr.add(change(0));
    int ans = 0;
    int cur = 0;
    for (int u : a) {
        cur = cur ^ u;
        string s = change(cur); 
        //cout << change(u) << " ";
        ans = max(ans , tr.cmp(s));
        tr.add(change(cur));
        //cerr << ans << " ";
    }
    cout << ans << '\n';
} 

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}