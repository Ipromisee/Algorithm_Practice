/**
 * n = 1000，动态规划dp[i] = max(dp[j]) + 1(j < i, a[j] < a[i])
 * 时间复杂度O(n^2)
 **/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;
int n;
int a[N];
int dp[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int t = 0;
        // 找到前面最长的上升子序列
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
                t = max(t, dp[j]);
        }
        dp[i] = t + 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    printf("%d", res);
    return 0;
}