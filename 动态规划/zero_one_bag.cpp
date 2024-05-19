// 动态规划解决01背包问题的代码
#include <iostream>

using namespace std;

const int N = 1010; // 背包物品数量上限
int n, V;           // n表示物品的数量，V表示背包的容量
int dp[N];          // dp数组存储背包在不同容量下的最大价值

int main()
{
    scanf("%d%d", &n, &V); // 输入物品的数量n和背包的容量V

    for (int i = 1; i <= n; i++)
    {
        int v, w;
        scanf("%d%d", &v, &w); // 输入当前物品的体积v和价值w
        for (int j = V; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + w); // 根据当前物品的体积和价值更新dp数组
        }
    }
    printf("%d", dp[V]); // 输出背包在容量V下的最大价值
    return 0;
}