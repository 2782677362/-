#include <iostream>
#include <string>
using namespace std;

// 验证回文串
// 如果在将所有大写字符转换为小写字符，并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个回文串 。
// 字母和数字都属于字母数字字符。
// 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

//示例 1：
//输入 : s = "A man, a plan, a canal: Panama"
//输出：true
//解释："amanaplanacanalpanama" 是回文串。

// 示例 2：
//输入：s = "race a car"
//输出：false
//解释："raceacar" 不是回文串。

//示例 3：
//输入：s = " "
//输出：true
//解释：在移除非字母数字字符之后s是一个空字符串 ""。

//解法一：遍历拷贝字母(大写转化为小写)和数字到新数组  =>  时间:0(N) 空间:O(N)
class Solution1 {
public:
    static bool isPalindrome(string s) {
        string s1;
        for (auto ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
                s1 += ch + 32;
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                s1 += ch;
            //if (isalnum(ch))
            //{
            //  s1 += tolower(ch);
            //}
        }

        string s2;
        string::const_reverse_iterator rit = s1.rbegin();
        while(rit!=s1.rend())
        {
            s2+=*rit;
            rit++;
        }
        //string s2(s1.rbegin(), s1.rend());

        if (s1 == s2)
            return true;
        return false;
    }
};

//解法二：在原字符串上直接判断：收尾双指针相向移动  =>  时间O(N)  空间O(1)
class Solution2 {
public:
    static bool isPalindrome(string s) {
        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;
            if (left < right && tolower(s[left]) != tolower(s[right]))
                return false;

            if (left < right)//防止越界
            {
                left++;
                right--;
            }
        }
        return true;
    }
};

int main()
{
    string s("A man, a plan, a canal: Panama");
    cout << Solution1::isPalindrome(s) << endl;
    cout << Solution2::isPalindrome(s) << endl;
    return 0;
}