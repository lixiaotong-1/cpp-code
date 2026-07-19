#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_set<int> set;
    for (const auto num: nums) {
    	if (set.find(num) == set.end()) {
         	set.insert(num);
        } else {
            return true;
        }
    }
    return false;
}

int main()
{
	std::vector<int> nums = {1,2,3,1};
    int res = containsDuplicate(nums);
	std::cout << res << "\n";
    return 0;
}