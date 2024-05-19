// 多重背包问题
// 时间复杂度O(n*V*s)
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n, V;
int dp[N];

int main()
{
    // 输入物品数量n和背包容量V
    scanf("%d%d", &n, &V);
    // 逐个处理每件物品
    for (int i = 1; i <= n; i ++ )
    {
        int v, w, s;
        // 输入每件物品的体积v、价值w和数量s
        scanf("%d%d%d", &v, &w, &s);
        // 01背包思想，遍历背包容量j
        for (int j = V; j >= v; j -- )
        {
            // 多重背包思想，遍历每件物品的数量k
            for (int k = 1; k <= s && j >= k * v; k ++ )
            {
                // 更新背包容量j对应的最大总价值
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    // 输出背包容量V对应的最大总价值
    printf("%d\n", dp[V]);
    return 0;
}