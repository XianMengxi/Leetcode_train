/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// #include <vector>
// #include <unordered_map>

// using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        if (nums.size() < 2)
        {
            return vector<int>();
        }
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++)
        {
            auto pointer = hash_table.find(target - nums[i]);
            if (hash_table.end() == pointer)
            {
                hash_table.insert({nums[i], i});
            }
            else
            {
                return vector<int>({(*pointer).second, i});
            }
        }
        return vector<int>();
    }
};
// @lc code=end
