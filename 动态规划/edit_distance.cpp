/**
 * dp[i][j] =  min(dp[i-1][j],dp[i][j-1])+1
 * dp[i][j] = min(dp[i-1][j-1], dp[i][j])(a[i]==b[j])
 * dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j])(a[i]!=b[j])
 * 时间复杂度应该为m * n * LEN * LEN= 1e8
 **/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, LEN = 20;
int n, m;
char strs[N][LEN];
int dp[LEN][LEN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", strs[i] + 1);
    }
    while (m--)
    {
        char s[LEN];
        int t;
        scanf("%s%d", s + 1, &t);
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            // lenstr表示目标字符串长度，lens表示操作的字符串的长度
            int lenstr = 0, lens = 0;
            for (int j = 1; s[j] != 0; j++)
            {
                dp[0][j] = j;
                lens++;
            }
            for (int j = 1; strs[i][j] != 0; j++)
            {
                dp[j][0] = j;
                lenstr++;
            }

            for (int j = 1; strs[i][j] != 0; j++)
            {
                for (int k = 1; s[k] != 0; k++)
                {
                    dp[j][k] = min(dp[j - 1][k], dp[j][k - 1]) + 1;
                    if (strs[i][j] == s[k])
                        dp[j][k] = min(dp[j][k], dp[j - 1][k - 1]);
                    else
                        dp[j][k] = min(dp[j][k], dp[j - 1][k - 1] + 1);
                }
            }
            if (dp[lenstr][lens] <= t)
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}