#include <iostream>
#include <string>
using namespace std;

// �ַ�����ӡ����
//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�����ͬ�����ַ�����ʽ���ء�
//�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
//1 <= num1.length, num2.length <= 10^4
//num1 ��num2 ��ֻ�������� 0 - 9
//num1 ��num2 ���������κ�ǰ����


//һ�����
//˼·����������������ַ������Ӻ���ǰһλһλ��ӣ�ע���λ���ٽ�ÿһλ����������ַ���

//�ⷨһ���������ַ����Ӻ���ǰ�洢  =>  ʱ�䣺O(max(M,N)^2)  M/NΪ���ַ����ĳ���
class SolutionAdd1 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //��λ
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            //��insert����ͷ��ʱ�����������Ԫ����������ƶ�һλ�Ĺ��̣�ʱ�临�ӶȽϸ�
            ret.insert(ret.begin(), (n + '0'));  
            i--;
            j--;
        }
        if (next == 1)
            ret.insert(ret.begin(), '1');

        return ret;
    }
};

//�ⷨ�����������ַ�����ǰ����洢�����������  =>  ʱ�䣺O(max(M,N))  M/NΪ���ַ����ĳ���
class SolutionAdd2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //��λ
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            ret += (n + '0');
            i--;
            j--;
        }
        if (next == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());//����
        return ret;
    }
};



//�������
//˼·������123*200
// ˼·һ�����Կ�����200��123����������123��200�������� --> �ⷨһ  
// ˼·�������Կ���3*200 + 20*200 + 100*200   --> �ⷨ��(�Ż�ʱ�临�Ӷ�)
// ˼·����ģ���ֹ��˷�  --> �ⷨ��(�ٴ��Ż�ʱ�临�Ӷ�)

// �ⷨһ��
class SolutionMul1 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //��λ
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            ret += (n + '0');
            i--;
            j--;
        }
        if (next == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        string i;
        string ret;
        for (i = "0"; i != num1; i = addStrings(i, "1"))
            ret = addStrings(ret, num2);
        return ret;
    }
};

// �ⷨ���� 
class SolutionMul2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //��λ
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            ret += (n + '0');
            i--;
            j--;
        }
        if (next == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        int size = num1.size();
        string ret;
        for (int i = 0; i < size; i++)
        {
            string tmp;
            for (int j = 0; j < num1[size-1-i] - '0'; j++)
            {
                tmp = addStrings(tmp, num2);
            }
            tmp.insert(tmp.size(), i, '0');
            ret = addStrings(ret, tmp);
        }
        return ret;
    }
};

//�ⷨ����
class SolutionMul2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //��λ
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            ret += (n + '0');
            i--;
            j--;
        }
        if (next == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();
        string ret(m + n, '0');
        for (int i = m - 1; i >= 0; i--)
        {
            int carry = 0; //��λ
            for (int j = n - 1; j >= 0; j--)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ret[i + j + 1] - '0') + carry;
                carry = sum / 10;
                ret[i + j + 1] = sum % 10 + '0';
            }
            ret[i] += carry; //�����λ
        }
        //ȥ��ǰ����
        int pos = ret.find_first_not_of('0');
        if(pos != string::npos)
            ret = ret.substr(pos);
        
        return ret;
    }
};

int main()
{
    SolutionMul2 s1;
    string str1("123");
    string str2("200");
    string ret = s1.multiply(str1, str2);
    cout << ret << endl;
    return 0;
}