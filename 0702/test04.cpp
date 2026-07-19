#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
	int sz = nums.size();
	std::unordered_map<int, int> map;
	for (int i = 0; i < sz; ++i) {
		if (map.find(nums[i]) == map.end()) {
			map.insert({nums[i], i});
		} else {
			if (i - map[nums[i]] <= k) {
				return true;
			}
			map[nums[i]] = i;
		}
	}
	return false;
}

int main()
{
	std::vector<int> nums = {1, 2, 3, 1};
	int k = 3;
	
    bool res = containsNearbyDuplicate(nums, k);
	std::cout << res << "\n";
    return 0;
}