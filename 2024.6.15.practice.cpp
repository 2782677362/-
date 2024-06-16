#include <iostream>
#include <string>
using namespace std;

//给定一个字符串s，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回-1。
//s只包含小写字母
//示例 1：输入: s = "leetcode"  输出 : 0
//示例 2 :输入: s = "loveleetcode"  输出 : 2
//示例 3 :输入: s = "aabb"  输出 : -1

//解法一：暴力求解，时间复杂度O(N*N)
class Solution1 {
public:
    static int firstUniqChar(string s) 
    {
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

//解法二：映射，时间复杂度O(N)
class Solution2 {
public:
    static int firstUniqChar(string s)
    {
        int begin = 0;
        int end = s.size()-1;
        int array[26] = { 0 };
        for (auto ch : s)
        {
            array[ch - 'a']++;
        }
        for (size_t i = 0; i < s.size(); i++)
        {
            if (array[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};


int main()
{
    string s("loveleetcode");
    int ret1 = Solution1::firstUniqChar(s);
    int ret2 = Solution2::firstUniqChar(s);
    cout << ret1 << endl;
    cout << ret2 << endl;

    return 0;
}