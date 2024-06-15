#include <iostream>
#include <string>
using namespace std;

//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
//ʾ�� 1������: s = "leetcode"  ��� : 0
//ʾ�� 2 :����: s = "loveleetcode"  ��� : 2
//ʾ�� 3 :����: s = "aabb"  ��� : -1

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