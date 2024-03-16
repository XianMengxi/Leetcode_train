/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// #include <vector>
// #include <string>
// using namespace std;

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return string({'1'});
        string str = countAndSay(n - 1);
        string ret;
        char ss = 'l';
        int ss_count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (i == 0) // 清0后
            {
                ss = str[i];
            }

            if (ss_count > 0 && ss != str[i])
            {
                // 结算
                ret.append(to_string(ss_count));
                ret.push_back(ss);

                ss_count = 0;
                ss = str[i];
            }

            ss_count++;
        }

        // 最后结算
        if (ss_count != 0)
        {
            ret.append(to_string(ss_count));
            ret.push_back(ss);
        }
        // cout << ret << endl;
        return ret;
    }
};
// @lc code=end
