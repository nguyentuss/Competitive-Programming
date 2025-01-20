#include <bits/stdc++.h> 

using namespace std; 
int test; 
int a, b; 
string s; 

int main () {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cout.tie(NULL);
  int t; cin >> t;
  while (t--) {
    cin >> a >> b; 
    cin >> s; 
    int current = 0; 
    int limit = 30; 
    for (int i = 0; i < 10; i++) {
      if (limit < a || current >= b || (current >= a && limit < b)) {
        cout << '-' << endl; 
        continue;
      }
      else if (s[i] == 'H') {
        current++;
        limit -= 2;   
      }
      else if (s[i] == 'B') {
        limit -= 3; 
      }
      else {
        current += 3; 
      }
      cout << limit << endl; 
    }
    if (limit < a) {
      cout << "XUONG_HANG" << endl; 
    }
    else if (current >= a && limit < b) {
      cout << "KHONG_DOI" << endl; 
    }
    else {
      cout << "THANG_HANG" << endl; 
    }
    cout << "##########" << endl; 
  }
  return 0; 
}