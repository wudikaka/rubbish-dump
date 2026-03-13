#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // m行
        int n = matrix[0].size(); // n列

        vector<int> perLineMax; // 每行最后一列--最大值
        for (int i = 0; i < m; i++)
        {
            perLineMax.push_back(matrix[i][n - 1]);
        }

        // 找target可能在哪行
        // 找第一个 > target 的元素
        int line;
        int low = 0;
        int high = m - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (perLineMax[mid] < target)
            {
                low = mid + 1;
            }
            else if (perLineMax[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                return 1;
            }
        }
        if (low > m - 1)
            return 0;

        line = low;

        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (matrix[line][mid] == target)
            {
                return 1;
            }
            else if (matrix[line][mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return 0;
    }
};