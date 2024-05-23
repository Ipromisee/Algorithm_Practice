/**
 * dp[i][j]表示a的前i个字符转为b的前j个字符
 * 需要的操作数。
 * dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1]+1)表示删除第i个数
 * 同时如果a[i]==b[j]，dp[i][j]=dp[i-1][j-1]不需要操作
 * 如果a[i]!=b[j]，则需要操作数加1。（一直取最小）
 **/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;
char a[N], b[N];
int dp[N][N];

int main()
{
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);

    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}