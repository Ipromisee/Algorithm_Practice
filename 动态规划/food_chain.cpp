/**
 * 带权并查集：这里用并查集维护许多组，每个根节点对应一组数据，各组数据没有关联
 * 每个节点到根节点的距离表示与根节点的关系:d[x]%3=0->与根节点一组，d[x]%3=1->吃根节点，d[x]%3=2->被根节点吃
 * 因为总共才三个组，所以知道两个节点对根节点的关系就可以得知两个节点的关系d[x]-d[y]=1->x吃y......
 **/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;
int n, k;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]); // 先记录根节点
        d[x] += d[p[x]];    // d[x]加上父节点到根节点的距离就是x到根节点的距离
        p[x] = u;           // 再把x移到根节点之下，完成路径压缩
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &k);

    // 初始化p，每个节点各为根节点
    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0;
    while (k--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n)
            res++;
        else
        {
            // 找到x, y在哪个组
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                else if (px != py) // 如果x, y本来就没在一组，此时就可以将两个组合并起来讨论了
                {
                    p[px] = py;          // 将py设为px的父节点
                    d[px] = d[y] - d[x]; // d[px]要使得新的d[y]-new(d[x])=0:new(d[x])=d[px]+d[x]->d[px]=d[y]-d[y]
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py) // 与上同理
                {
                    p[px] = p[y];
                    d[px] = d[y] - d[x] + 1; // x吃y说明x被根节点吃，y吃根节点即new(d[x])%3=2,d[y]%3=1->new(d[x])-d[y]=1->d[px]=d[y]-d[x]+1
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}