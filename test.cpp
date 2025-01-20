#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    long long max = 1500;
    // sieve
    vector <int> isPrime (max, 0);
    vector <long long> primes;
    for (long long i =2; i < max; i++){
        if (isPrime[i]==0){
            primes.push_back (i);
            if (i*i < max){
                for (long long j = i*i; j < max; j+=i){
                    isPrime[j]= 1;
                }
            }
        }
    }
    cin >> n;
    map <long long, vector <int>> mark;
    for (long long testcase =1; testcase <=n; testcase ++){
        long long num;
        cin >> num;
        int des = upper_bound (primes.begin(), primes.end(), sqrt (num) + 3)- primes.begin();
        for (int i =0; i <= des; i++){
            long long current = primes[i];
            if (num % current==0){
                mark[current].push_back(testcase);
                while (num % current ==0){
                    num /= current;
                }
            }
            if (num < current || num ==1){
                break;
            }
        }
        if (num != 1){
            mark [num].push_back (testcase);
        }
    }
    vector <long long> result (n+1, -1);
    // 1 5 6 5 4 5 2
    for (const auto& pair : mark) {
        vector<int> current = pair.second;
        if (current.size() >1) {  
           int firstElementInRow = current [0];
           int nextElement = current [1];
           if ((result[firstElementInRow]== -1)|| (abs(result[firstElementInRow]-firstElementInRow) > abs(nextElement- firstElementInRow))|| ((abs(result[firstElementInRow]-firstElementInRow) == abs(nextElement- firstElementInRow) && nextElement < result[firstElementInRow]) )){
               result[firstElementInRow]= nextElement;
           }
           for (int i = 1; i < current.size(); i++){
               int currentElement = current[i];
               int lastElement = current [i-1];
               if (i == current.size()-1){
                   if (result[currentElement]==-1 || (abs(result[currentElement]- currentElement)> abs(currentElement - lastEle ment)) || ( abs(result[currentElement]- currentElement) ==  abs(currentElement - lastElement) && lastElement < result[currentElement] )){
                       result[currentElement]= lastElement;
                   }
               }
               else{
                   int nextElement = current [i+1];
                   int compare = 0;
                   if (abs(nextElement- currentElement) >= abs(currentElement- lastElement) ){
                       compare = lastElement;
                   }
                   else{
                       compare = nextElement;
                   }
                   if (result[currentElement]==-1 || (abs(result[currentElement]- currentElement) > abs(currentElement - compare) )||((abs(result[currentElement]- currentElement)== abs(currentElement - compare))&& compare < result[currentElement]) ){
                       result[currentElement]= compare;
                   }
               }
           }
        }
    }
    for (int i =1; i <= n;i ++){
        cout << result[i]<< " ";
    }
    return 0;
}