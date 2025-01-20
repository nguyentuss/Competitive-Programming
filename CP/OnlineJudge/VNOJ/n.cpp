#include <bits/stdc++.h> 

using namespace std; 
const int lim = 1000000000;
long long ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; 
  fflush(stdout); 
  long long square; 
  cin >> square; 
  if (square == -1) {
    exit(0);
  }
  return square; 
}

int main () {
  //freopen("test.inp","r",stdin);
  long long S = ask(1, 1, lim, lim);
  int lo = 1; int hi = lim; 
  int leftMost = -1; 
  int rightMost = -1;
  int up = -1; 
  while (lo <= hi) {
    int mid = (lo + hi) >> 1; 
    long long value = ask(1, 1, mid, lim); 
    if (value == 0) {
      up = mid; 
      lo = mid + 1; 
    }
    else {
      if (value == S) {
        rightMost = mid; 
      } 
      else {
        leftMost = mid; 
      }
      hi = mid - 1; 
    }
  } 
  up++; 
  int down = -1; 
  lo = leftMost;
  hi = rightMost;  
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    long long value = ask(mid, 1, lim, lim);
    if (value == 0) {
      down = mid; 
      hi = mid - 1; 
    }  
    else {
      lo = mid + 1; 
    }
  }
  down--;
  long long x = down - up + 1; 
  long long y = S / x; 
  int left = -1; 
  lo = 1; 
  hi = lim; 
  while (lo <= hi) {
    int mid = (lo + hi) >> 1; 
    long long value = ask(1, 1, lim, mid);
    if (value == 0) {
      left = mid; 
      lo = mid + 1; 
    } 
    else {
      
      hi = mid - 1; 
    }
  }
  left++; 
  int right = left + y - 1; 
  cout << "! " << up << ' ' << left << ' ' << down << ' ' << right << endl; 
  fflush(stdout); 
  return 0; 
}