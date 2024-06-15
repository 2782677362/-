#include <iostream>
using namespace std;
#include <stdlib.h>

//����һ���������� coins ����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount ����ʾ�ܽ�
//���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��� �����û���κ�һ��Ӳ�����������ܽ�����-1��
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�

//ʾ�� 1�����룺coins = [1, 2, 5], amount = 11  �����3  ���ͣ�11 = 5 + 5 + 1
//ʾ�� 2�����룺coins = [2], amount = 3         ����� - 1
//ʾ�� 3�����룺coins = [1], amount = 0         �����0

//˼·��
//�����Ų���ΪӲ��a1,a2��a3...ax�ܹ�xöӲ�ң���ô�����һöӲ��ax��������������Ų��Ծ���a1,a2,a3...a(x-1)����ax��һöӲ��
//��ˣ������һöӲ��ax����ֵΪy����ԭ����ת��Ϊ�����⣺
//ԭ����:�����ö���öӲ�Ҵճ�amount��xö��
//������:�����ö���öӲ�Ҵճ�amount-y��x-1ö��

int coinChange(int* coins, int coinsSize, int amount)
{
    //��dp[i] ��ʾ�ճɽ�� i ���������Ӳ������
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX; 
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < coinsSize; j++)
        {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
        }
    }
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int main()
{
    int coins[] = {1,2,5};
    int coinsSize = 3;
    int amount = 11;
    int ret = coinChange(coins, coinsSize, amount);
    cout << ret << endl;
    return 0;
}