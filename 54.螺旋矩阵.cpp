/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>
using namespace std;
#include <unordered_map>

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return vector<int>();
        }
        int row_col_table[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> ret;
        int rotate_dir = 0; // 0向右，1向下，2向左，3向上
        int temp;
        bool can_change = false; // 沿着某一方向运动次数
        int row_col_num[2] = {0};
        while (1)
        {
            temp = matrix[row_col_num[1]][row_col_num[0]];
            cout << temp << endl;

            if (temp <= 100 && temp >= -100)
            {
                ret.push_back(temp);
                matrix[row_col_num[1]][row_col_num[0]] = 101;
                can_change = true;
            }
            else if (!can_change)
            {
                cout << "1break" << endl;

                break;
            }
            else
            {
                rotate_dir = (rotate_dir + 1) % 4;
                can_change = false;
            }

            if (row_col_num[0] + row_col_table[rotate_dir][0] >= matrix[0].size() || row_col_num[1] + row_col_table[rotate_dir][1] >= matrix.size())
            {
                rotate_dir = (rotate_dir + 1) % 4;

                // 如果切换方向依然无路可走
                if (row_col_num[0] + row_col_table[rotate_dir][0] > matrix.size() || row_col_num[1] + row_col_table[rotate_dir][1] > matrix[0].size())
                {
                    cout << "2break" << endl;

                    break;
                }
            }
            row_col_num[0] += row_col_table[rotate_dir][0];
            row_col_num[1] += row_col_table[rotate_dir][1];
            cout << rotate_dir << " " << row_col_num[0] << "  " << row_col_num[1] << endl;
        }
        return ret;
    }
};
// @lc code=end
