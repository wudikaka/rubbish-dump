#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            while (!isalnum(s[l]) && l < r)
            {
                ++l;
            }
            while (!isalnum(s[r]) && l < r)
            {
                --r;
            }

            if (s[l] < 'a')
            {
                s[l] += 32;
            }
            if (s[r] < 'a')
            {
                s[r] += 32;
            }

            if (s[r] != s[l])
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};