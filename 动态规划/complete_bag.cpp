#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, V;
int dp[N];

int main()
{
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i++)
    {
        // 读入每件物品的体积v和价值w
        int v, w;
        scanf("%d%d", &v, &w);
        for (int j = v; j <= V; j++) // 与01背包问题的区别，因为有无数多物品，所以从小遍历到大即可重复取该物品
        {
            // 状态转移方程，更新背包容量为j时的最大价值
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    // 输出最终背包容量为V时的最大价值
    printf("%d\n", dp[V]);
    return 0;
}