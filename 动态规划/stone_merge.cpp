/**
 * 区间合并问题是先解决小（短）区间，然后解决大（长）区间
 * 先从小到大遍历每个长度（外层循环），再遍历每个起点（内层循环），不断更新
 **/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 310, INF = 0x3f3f3f3f;

int n;
int a[N];
int dp[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INF;
            // 遍历每种情况，即左右合并
            for (int k = 1; k <= len - 1; k++)
            {
                // 合并左右两个石堆，需要先将左右两个石堆合并好，即dp[i][i + k - 1] + dp[i + k][j]
                // 然后将两个石堆合并起来，即a[j] - a[i - 1]（前缀和）
                dp[i][j] = min(dp[i][j], dp[i][i + k - 1] + dp[i + k][j] + a[j] - a[i - 1]);
            }
        }
    }
    printf("%d", dp[1][n]);

    return 0;
}