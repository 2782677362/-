#include <iostream>
using namespace std;
#include <stdlib.h>

//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回-1。
//你可以认为每种硬币的数量是无限的。

//示例 1：输入：coins = [1, 2, 5], amount = 11  输出：3  解释：11 = 5 + 5 + 1
//示例 2：输入：coins = [2], amount = 3         输出： - 1
//示例 3：输入：coins = [1], amount = 0         输出：0

//思路：
//设最优策略为硬币a1,a2，a3...ax总共x枚硬币，那么将最后一枚硬币ax单独拎出来，最优策略就是a1,a2,a3...a(x-1)加上ax这一枚硬币
//因此，设最后一枚硬币ax的面值为y，则原问题转化为子问题：
//原问题:最少用多少枚硬币凑成amount（x枚）
//子问题:最少用多少枚硬币凑成amount-y（x-1枚）

int coinChange(int* coins, int coinsSize, int amount)
{
    //用dp[i] 表示凑成金额 i 所需的最少硬币数。
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