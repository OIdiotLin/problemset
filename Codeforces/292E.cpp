#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck(x) cout<<"["<<x<<"]"
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;
typedef pair<int, int>PII;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int MX = 1e5 + 5;

int A[MX], B[MX];
struct Data {
    int x, y, k;
    Data() {}
    Data(int _x, int _y, int _k) {
        x = _x; y = _y; k = _k;
    }
} col[MX << 2];
void push_down(int rt) {
    if(col[rt].k) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        col[rt].k = 0;
    }
}
void build(int l, int r, int rt) {
    col[rt].k = 0;
    if(l == r) return;

    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
Data query(int x, int l, int r, int rt) {
    if(l == r) {
        return col[rt];
    }
    push_down(rt);
    int m = (l + r) >> 1;
    if(x <= m) return query(x, lson);
    else return query(x, rson);
}
void update(int L, int R, Data s, int l, int r, int rt) {
    if(L <= l && r <= R) {
        col[rt] = s;
        return;
    }

    push_down(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, s, lson);
    if(R > m) update(L, R, s, rson);
}

int main() {
    int n, m; //FIN;
	freopen("292E.in","r",stdin);
	freopen("292E.out","w",stdout);
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", &B[i]);
        }

        build(1, n, 1);
        for(int i = 1; i <= m; i++) {
            int op, x, y, k;
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d", &x, &y, &k);
                update(y, y + k - 1, Data(x, y, k), 1, n, 1);
            } else {
                scanf("%d", &k);
                Data s = query(k, 1, n, 1);
                if(!s.k) printf("%d\n", B[k]);
                else printf("%d\n", A[k - s.y + s.x]);
            }
        }
    }
    return 0;
}