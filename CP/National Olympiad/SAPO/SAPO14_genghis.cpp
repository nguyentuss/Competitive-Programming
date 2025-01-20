#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

int main() {
	int horse_num;
	int stable_num;
	std::cin >> horse_num >> stable_num;
	vector<int> stable_horses(stable_num);
	for (int& h : stable_horses) {
		std::cin >> h;
		assert(0 < h && h <= horse_num);
	}
	// add two "out-of-bounds" horses
	stable_horses.push_back(0);
	stable_horses.push_back(horse_num + 1);

	std::sort(stable_horses.begin(), stable_horses.end());
	
	/*
	 * lowest_ops[i][j] = min operations if we only consider horses
	 * from that exist in the index interval (i, j)
	 * ex: lowest_ops[1][4] and stable_horses = [0, 1, 3, 7, 10, 11]
	 *     means that we only consider horses from (1, 10)
	 */
	vector<vector<int>> lowest_ops(
		stable_num + 2, vector<int>(stable_num + 2, INT32_MAX)
	);
	for (int i = 0; i < stable_num + 2; i++) {
		lowest_ops[i][i] = 0;
		if (i + 1 < stable_num + 2) {
			lowest_ops[i][i + 1] = stable_horses[i + 1] - stable_horses[i] - 1;
		}
		if (i + 2 < stable_num + 2) {
			lowest_ops[i][i + 2] = stable_horses[i + 2] - stable_horses[i] - 1;
		}
	}
	for (int num = 4; num <= stable_num + 2; num++) {
		for (int start = 0; start + num - 1 < stable_num + 2; start++) {
			int end = start + num - 1;
			/*
			 * first handle the beginning and ending edge cases,
			 * where the smallest or largest element has become the root
			 */
			lowest_ops[start][end] = std::min(
				lowest_ops[start][end],
				lowest_ops[start][start + 1]
				+ lowest_ops[start + 1][end]
				+ stable_horses[end] - stable_horses[start + 1]
			);
			lowest_ops[start][end] = std::min(
				lowest_ops[start][end],
				lowest_ops[end - 1][end]
				+ lowest_ops[start][end - 1]
				+ stable_horses[end - 1] - stable_horses[start]
			);

			/*
			 * then get to the actual part where we combine
			 * two parts with top being the root
			 */
			for (int top = start + 2; top < end - 1; top++) {
				lowest_ops[start][end] = std::min(
					lowest_ops[start][end],
					lowest_ops[start][top]
					+ lowest_ops[top][end]
					+ stable_horses[end] - stable_horses[start] - 1
				);
			}
		}
	}
	cout << lowest_ops[0][stable_num + 1] << endl;
}