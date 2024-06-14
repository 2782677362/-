#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//爬楼梯：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 思路：
// 爬到第x个台阶的方法数就是爬到x-1个台阶和x-2个台阶的方法数之和(x>2)
// 用f(x)表示爬到第x个台阶的方法数，则f(x)=f(x-1)+f(x-2)

//解法一：缺点：容易栈溢出
int climbStairs_1(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n > 2)
        return climbStairs_1(n - 1) + climbStairs_1(n - 2);
}

//解法二：直观
int climbStairs2(int n) {
    if (n < 2)
        return 1;
    if (n == 2)
        return 2;

    int n2 = 1;//到x-2个台阶的方法数
    int n1 = 2;//到x-1个台阶的方法数
    int ret = 0;
    for (int i = 2; i < n; i++)
    {
        ret = n1 + n2;
        n1 = n2;
        n2 = ret;
    }
    return ret;
}

//解法二优化：代码简洁但不如优化前直观
int climbStairs_2(int n) 
{
    int n2 = 0;//到x-2个台阶的方法数
    int n1 = 0;//到x-1个台阶的方法数
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
