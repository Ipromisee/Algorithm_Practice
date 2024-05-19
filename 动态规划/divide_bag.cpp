// 动态规划解决分组背包问题
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, m;              // 物品数量和背包容量
int dp[N], v[N], w[N]; // dp为动态规划数组，v为物品体积，w为物品价值

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int s;
        scanf("%d", &s);
        for (int k = 1; k <= s; ++k)
            scanf("%d%d", &v[k], &w[k]);
        for (int j = m; j >= 0; j--) // 背包容量递减遍历和O1背包一样
        {
            for (int l = 1; l <= s; l++)
            {
                if (j >= v[l])                               // 防止数组越界
                    dp[j] = max(dp[j], dp[j - v[l]] + w[l]); // 动态规划状态转移方程
            }
        }
    }

    printf("%d", dp[m]);
    return 0;
}