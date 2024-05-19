/***
 * 二进制优化！
 * 采取多重背包问题I的做法1000*2000*2000=8e9超时
 * 可以将多重背包问题看作01背包问题，即将物品分装成更大的物品。
 * 由于每个数都可以由一个二进制数表示，所以我们可以将s拆为2的次方的和，例如
 * 11就可以拆为1、2、4以及4个物品。0-11每个数都可以由1、2、4、4组合成。
 ***/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define v first
#define w second

using namespace std;
typedef pair<int, int> PII;

const int N = 1010, V = 2010;
int n, m;
int dp[V];
vector<PII> goods;

int main()
{
    scanf("%d%d", &n, &m);
    // 将物品分组
    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        scanf("%d%d%d", &v, &w, &s);
        for (int j = 1; j <= s; j *= 2)
        {
            goods.push_back({v * j, w * j});
            s -= j;
        }
        if (s > 0)
            goods.push_back({v * s, w * s});
    }

    // 套01背包模板即可
    for (int i = 0; i < goods.size(); i++)
    {
        int v = goods[i].v;
        int w = goods[i].w;
        for (int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    printf("%d\n", dp[m]);

    return 0;
}