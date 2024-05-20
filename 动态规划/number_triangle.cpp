#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n;
int a[N][N];
int dp[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            dp[i][j] = -INF;
        }
    }
    
    // 从最后一层开始
    for (int i = n; i > 0; i -- )
    {
        // 遍历每一层，利用下面一层两数更新dp
        for (int j = 1; j <= i; j ++ )
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
        }
    }
    printf("%d", dp[1][1]);
    
    return 0;
}