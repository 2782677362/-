#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��¥�ݣ�������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

// ˼·��
// ������x��̨�׵ķ�������������x-1��̨�׺�x-2��̨�׵ķ�����֮��(x>2)
// ��f(x)��ʾ������x��̨�׵ķ���������f(x)=f(x-1)+f(x-2)

//�ⷨһ��ȱ�㣺����ջ���
int climbStairs_1(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n > 2)
        return climbStairs_1(n - 1) + climbStairs_1(n - 2);
}

//�ⷨ����
int climbStairs_2(int n) 
{
    int n1 = 0;
    int n2 = 0;
    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        n2 = n1;
        n1 = ret;
        ret = n1 + n2;
    }
    return ret;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d\n", climbStairs_1(n));
    printf("%d\n", climbStairs_2(n));
    return 0;
}
