#include <bits/stdc++.h>


using namespace std;


bool canPartition(vector<int>& set, int length, int target) {
    if (target == 0) return true;
    if (length == 0 && target != 0) return false;
    if (set[length - 1] > target) return canPartition(set, length - 1, target);
    return canPartition(set, length - 1, target) || canPartition(set, length - 1, target - set[length - 1]);
}

bool distributeWeights(vector<int>& set, int length, int subsetA, int subsetB, int subsetC, vector<int>& groupA, vector<int>& groupB, vector<int>& groupC) {
    if (subsetA == 0 && subsetB == 0 && subsetC == 0) return true;
    if (length == 0) return false;

    bool inA = false, inB = false, inC = false;

    if (subsetA >= set[length - 1]) {
        groupA.push_back(length);
        inA = distributeWeights(set, length - 1, subsetA - set[length - 1], subsetB, subsetC, groupA, groupB, groupC);
        if (!inA) groupA.pop_back();
    }
    if (!inA && subsetB >= set[length - 1]) {
        groupB.push_back(length);
        inB = distributeWeights(set, length - 1, subsetA, subsetB - set[length - 1], subsetC, groupA, groupB, groupC);
        if (!inB) groupB.pop_back();
    }
    if ((!inA && !inB) && subsetC >= set[length - 1]) {
        groupC.push_back(length);
        inC = distributeWeights(set, length - 1, subsetA, subsetB, subsetC - set[length - 1], groupA, groupB, groupC);
        if (!inC) groupC.pop_back();
    }

    return inA || inB || inC;
}

int main() {
    int count;
    cin >> count; 

    vector<int> set(count);
    int totalSum = 0;

    for (int i = 0; i < count; ++i) {
        cin >> set[i]; 
        totalSum += set[i];
    }

    if (totalSum % 3 != 0) {
        cout << "No solution" << endl;
        return 0;
    }

    int eachSubsetSum = totalSum / 3;

    if (!canPartition(set, count, eachSubsetSum) ||
        !canPartition(set, count, eachSubsetSum) ||
        !canPartition(set, count, eachSubsetSum)) {
        cout << "No solution" << endl;
        return 0;
    }

    vector<int> groupA, groupB, groupC;
    if (distributeWeights(set, count, eachSubsetSum, eachSubsetSum, eachSubsetSum, groupA, groupB, groupC)) {
        for (int num : groupA) cout << num << " ";
        cout << '\n';
        for (int num : groupB) cout << num << " ";
        cout << '\n';
        for (int num : groupC) cout << num << " ";
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}