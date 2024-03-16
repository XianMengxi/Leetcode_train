/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// #include <string>
// #include <unordered_map>
// using namespace std;

// @lc code=start
class Solution
{
public:
    enum CharType
    {
        NUMBER,
        SIGN_CHAR,
        DOT,
        USEFUL_CHAR,
        UNUSED
    };
    bool isNumber(string s)
    {
        if (s.empty())
        {
            return false;
        }
        bool is_number = false;
        bool is_e = false;
        bool is_dot = false;
        bool is_not_zero = false;
        for (int i = 0; i < s.size(); i++)
        {
            switch (isGoodChar(s[i]))
            {
            case SIGN_CHAR:
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                {
                    return false;
                }
                break;
            case NUMBER:
                is_number = true;
                break;
            case DOT:
                if (is_e || is_dot)
                    return false;
                is_dot = true;
                break;
            case USEFUL_CHAR:
                if (is_e || !is_number)
                    return false;
                is_e = true;
                is_number = false;
                break;

            default:
                return false;
            }
        }
        return is_number;
    }

    enum CharType isGoodChar(char &temp)
    {
        switch (temp)
        {
        case '+':
        case '-':
            return SIGN_CHAR;
        case 'E':
        case 'e':
            return USEFUL_CHAR;
        case '.':
            return DOT;
        default:
            if (temp - '0' >= 0 && temp - '0' <= 9)
            {
                return NUMBER;
            }
            return UNUSED;
        }
    }
};
// @lc code=end
