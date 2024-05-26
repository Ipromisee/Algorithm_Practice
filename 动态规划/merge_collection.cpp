#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (op == 'M')
        {
            if (a == b)
                continue;
            p[a] = b;
        }
        else if (op == 'Q')
        {
            if (a == b)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}