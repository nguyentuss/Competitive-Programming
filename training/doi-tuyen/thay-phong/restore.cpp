#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first 
#define s second
#define MAX_VAL (int) (1e6 + 7)

int before[MAX_VAL];
int after[MAX_VAL];
int cnt[MAX_VAL];
vector <int> s;
int a[MAX_VAL] , n;

void check(int x) {
      if (cnt[x] == 0) {
            s.push_back(x);
            cnt[x] = 1;
      }
}

void calc(int status) {
      int trace = 0 , pos = 0;
      int checked = (status == 0 ? -1 : 0);
      while (true) {
            if (after[trace] == checked) break;
            pos += 2;
            a[pos] = after[trace];
            trace = after[trace];
      }
      trace = 0 , pos = n;
      if (status == 1) {
            for (int i = 0 ; i < s.size() ; i++) 
                  if (after[s[i]] == -1) {
                        trace = s[i];
                        a[n] = s[i];
                        break;
                  }
      }
      else pos = n + 1;
      while (true) {
            if (before[trace] == -1) break;
            pos -= 2;
            a[pos] = before[trace];
            trace = before[trace];
      }     
      for (int i = 1 ; i <= n ; i++) 
            cout << a[i] << " ";
}

int main() {
      ios_base::sync_with_stdio(0);cin.tie(NULL);
      cout.tie(NULL);
      freopen("restore.inp","r",stdin);
      freopen("restore.out","w",stdout);
      memset(before , -1 , sizeof before);
      memset(after, -1 , sizeof after);
      cin >> n;
      for (int i = 1 ; i <= n ; i++) {
            int a , b; cin >> a >> b;
            if (a != 0) check(a);
            if (b != 0) check(b);
            after[a] = b , before[b] = a;
      }
      if (n % 2) calc(1);
      else calc(0);

      return 0;
}