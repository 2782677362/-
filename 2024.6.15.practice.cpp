#include <iostream>
#include <string>
using namespace std;

//����һ���ַ���s���ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻�-1��
//sֻ����Сд��ĸ
//ʾ�� 1������: s = "leetcode"  ��� : 0
//ʾ�� 2 :����: s = "loveleetcode"  ��� : 2
//ʾ�� 3 :����: s = "aabb"  ��� : -1

//�ⷨһ��������⣬ʱ�临�Ӷ�O(N*N)
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

//�ⷨ����ӳ�䣬ʱ�临�Ӷ�O(N)
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