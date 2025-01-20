#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using std::cout;
using std::endl;
using std::vector;
using std::pair;
 
int main() {
	int size;
	std::cin >> size;
	vector<int> arr(size);
	for (int& i : arr) {
		std::cin >> i;
	}
 
	int best_len = 1;
	// given the ending limit, stores the longest consecutive sequence
	std::map<int, pair<int, int>> ending_max_len;
	std::map<int, int> come_from;
	for (int i = 0; i < size; i++) {
		int n = arr[i];
		if (!ending_max_len.count(n - 1)) {
			ending_max_len[n] = {1, i};
			come_from[i] = -1;
		} else {
			int new_len = ending_max_len[n - 1].first + 1;
			if (!ending_max_len.count(n) || ending_max_len[n].first < new_len) {
				ending_max_len[n] = {new_len, i};
				best_len = std::max(best_len, new_len);
				come_from[i] = ending_max_len[n - 1].second;
			}
		}
	}
 
	int at_ind = -1;
	for (const pair<int, pair<int, int>>& end : ending_max_len) {
		if (end.second.first == best_len) {
			at_ind = end.second.second;
		}
	}
	vector<int> reverse_inds;
	for (int i = 0; i < best_len; i++) {
		reverse_inds.push_back(at_ind);
		at_ind = come_from[at_ind];
	}
 
	cout << best_len << endl;
	for (int i = best_len - 1; i > 0; i--) {
		cout << reverse_inds[i] + 1 << ' ';
	}
	cout << reverse_inds.front() + 1 << endl;
}