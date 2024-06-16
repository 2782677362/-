#include <iostream>
#include <string>
using namespace std;

// ��֤���Ĵ�
// ����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�����Ĵ� ��
// ��ĸ�����ֶ�������ĸ�����ַ���
// ����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

//ʾ�� 1��
//���� : s = "A man, a plan, a canal: Panama"
//�����true
//���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���

// ʾ�� 2��
//���룺s = "race a car"
//�����false
//���ͣ�"raceacar" ���ǻ��Ĵ���

//ʾ�� 3��
//���룺s = " "
//�����true
//���ͣ����Ƴ�����ĸ�����ַ�֮��s��һ�����ַ��� ""��

//�ⷨһ������������ĸ(��дת��ΪСд)�����ֵ�������  =>  ʱ��:0(N) �ռ�:O(N)
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

//�ⷨ������ԭ�ַ�����ֱ���жϣ���β˫ָ�������ƶ�  =>  ʱ��O(N)  �ռ�O(1)
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

            if (left < right)//��ֹԽ��
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