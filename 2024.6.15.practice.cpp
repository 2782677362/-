#include <iostream>
#include <string>
using namespace std;

//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
//示例 1：输入: s = "leetcode"  输出 : 0
//示例 2 :输入: s = "loveleetcode"  输出 : 2
//示例 3 :输入: s = "aabb"  输出 : -1

class Solution {
public:
    static int firstUniqChar(string s) {
        for (size_t i = 0; i < s.size(); i++)
        {
            int found = 0;
            for (size_t j = 0; j < s.size(); j++)
            {
                if (i != j)
                {
                    if (s[i] == s[j])
                    {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    string s("loveleetcode");
    int ret = Solution::firstUniqChar(s);
    cout << ret << endl;

    return 0;
}