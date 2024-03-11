/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// #include <iostream>
// #include <math.h>
// #include <bitset>
// using namespace std;

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        double is_min = 1.0;
        if (n == 0)
        {
            return 1;
        }
        else if (fabs(x) < 1e-6)
        {
            return 0.0;
        }
        else if (fabs(x + 1.0) < 1e-6)
        {
            if (n > 0)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if (n == INT_MIN)
        {
            x = 1 / x;
            is_min = x;
            n = INT_MAX;
        }
        else if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }

        // 以下为 n > 0
        bitset<32> bin(n);
        int index = 0;
        int mul = 1;
        double mul_x = 1;
        for (int i = 0; i < 31; i++)
        {
            if (bin[i] != 0)
            {
                index += mul;
                mul_x *= x;
            }
            mul << 1;
            x = x * x;
            if (index == n)
            {
                break;
            }
        }
        return mul_x * is_min;
    }
};
// @lc code=end
