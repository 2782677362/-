#include <iostream>
#include <string>
using namespace std;

// 字符串相加、相乘
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和、积并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//1 <= num1.length, num2.length <= 10^4
//num1 和num2 都只包含数字 0 - 9
//num1 和num2 都不包含任何前导零


//一：相加
//思路：逆序遍历这两个字符串，从后往前一位一位相加，注意进位，再将每一位结果存入新字符串

//解法一：存入新字符串从后往前存储  =>  时间：O(max(M,N)^2)  M/N为两字符串的长度
class SolutionAdd1 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //进位
        while (i >= 0 || j >= 0)
        {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int n = n1 + n2 + next;
            next = n / 10;
            n = n % 10;
            //用insert函数头插时，会存在数组元素依次向后移动一位的过程，时间复杂度较高
            ret.insert(ret.begin(), (n + '0'));  
            i--;
            j--;
        }
        if (next == 1)
            ret.insert(ret.begin(), '1');

        return ret;
    }
};

//解法二：存入新字符串从前往后存储，最后在逆序  =>  时间：O(max(M,N))  M/N为两字符串的长度
class SolutionAdd2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //进位
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

        reverse(ret.begin(), ret.end());//逆序
        return ret;
    }
};



//二：相乘
//思路：例如123*200
// 思路一：可以看作将200个123加起来（或将123个200加起来） --> 解法一  
// 思路二：可以看作3*200 + 20*200 + 100*200   --> 解法二(优化时间复杂度)
// 思路三：模拟手工乘法  --> 解法三(再次优化时间复杂度)

// 解法一：
class SolutionMul1 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //进位
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

// 解法二： 
class SolutionMul2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //进位
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

//解法三：
class SolutionMul2 {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int next = 0; //进位
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
            int carry = 0; //进位
            for (int j = n - 1; j >= 0; j--)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ret[i + j + 1] - '0') + carry;
                carry = sum / 10;
                ret[i + j + 1] = sum % 10 + '0';
            }
            ret[i] += carry; //处理进位
        }
        //去除前导零
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