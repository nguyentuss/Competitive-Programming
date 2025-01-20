/**
 * Author: Tomatoes
 * Date: 2015-03-19
 * License: CC0
 * Source: me
 * Description: Allow using pair with hash-based containers
 */
#pragma once

namespace std {
	template<>
	struct hash<pair<int, int>> {
	public:
		size_t operator()(const pair<int,int>& x) const {
			return 1000000009LL * x.first + x.second;
		}
	};
}

