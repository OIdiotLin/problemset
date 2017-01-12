#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
using namespace std;
const double eps = 1e-6;
const int MAXN = 1500 + 10;
const int MOD = 1000007;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
typedef pair<int, int> pii;
typedef vector<int>::iterator viti;
typedef vector<pii>::iterator vitii;
int ans[10], input[10];
bool flag = true;
bool Solve(int n)
{
    if (n == 0)
    {
        puts("YES");
        printf("%d\n%d\n%d\n%d\n", 1, 1, 3, 3);
    }
    if (n == 1)
    {
        puts("YES");
        ans[1] = input[1], ans[4] = ans[1] * 3, ans[2] = ans[1], ans[3] = ans[4];
        for (int i = 2; i <= 4; i++) printf("%d\n", ans[i]);
    }
    if (n == 2)
    {
        if (input[2] % 3)
        {
            if (input[1] * 3 < input[2]) return flag = false;
            puts("YES");
            ans[1] = input[1], ans[4] = ans[1] * 3;
            int tmp = 4 * ans[1] - input[2];
            printf("%d\n%d\n", ans[4], tmp);
        }
        else
        {
            if (input[2] / 3 > input[1]) return flag = false;
            puts("YES");
            ans[1] = input[2] / 3;
            int tmp = 4 * ans[1] - input[1];
            printf("%d\n%d\n", ans[1], tmp);
        }
    }
    if (n == 3)
    {
        if (input[3] % 3)
        {
            if (input[1] * 3 < input[3]) return flag = false;
            for (int i = 1; i <= 3; i++) ans[i] = input[i];
            ans[4] = ans[1] * 3;
            if (4 * ans[1] != ans[2] + ans[3]) return flag = false;
            puts("YES");
            printf("%d\n", ans[4]);
        }
        else
        {
            if (input[3] / 3 > input[1]) return flag = false;
            if (input[3] / 3 == input[1])
            {
                puts("YES");
                printf("%d\n", input[1] * 4 - input[2]);
                return true;
            }
            ans[1] = input[3] / 3, ans[4] = input[3], ans[2] = input[1], ans[3] = input[2];
            if (4 * ans[1] != ans[2] + ans[3]) return flag = false;
            puts("YES");
            printf("%d\n", ans[1]);
        }
    }
    if (n == 4)
    {
        for (int i = 1; i <= 4; i++) ans[i] = input[i];
        if (4 * ans[1] == ans[2] + ans[3]) puts("YES");
        else flag = false;
    }
}
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &input[i]);
    sort(input + 1, input + n + 1);
    Solve(n);
    if (!flag)
    {
        puts("NO");
        return 0;
    }
    return 0;
}