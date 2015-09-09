#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1003;
int r[MAX], x[MAX], y[MAX], p[MAX], q[MAX], c[MAX];
int seen[MAX];

bool touch(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) == (r[i] + r[j]) * (r[i] + r[j]);
}
int n;
ll mdc(ll a, ll b) {
    if(b == 0) return a;
    return mdc(b, a % b);
}

void dfs(int i, ll pp, ll qq, bool cc) {
    seen[i] = true;
    ll x = mdc(pp, qq);
    pp /= x;
    qq /= x;
    p[i] = pp;
    q[i] = qq;
    c[i] = cc;
    for(int j = 0; j < n; j++)
        if(!seen[j] && touch(i, j))
            dfs(j, r[i] * pp, r[j] * qq, !cc);
}

int main() {
    int i, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%lld %lld %lld", &x[i], &y[i], &r[i]);
        memset(seen, 0, sizeof seen);
        memset(p, 0, sizeof p);
        memset(q, 0, sizeof q);
        memset(c, 0, sizeof c);
        dfs(0, 1, 1, true);
        for(i = 0; i < n; i++) {
            if(p[i] == 0) puts("not moving");
            else if(q[i] == 1) {
                printf("%lld ", p[i]);
                if(!c[i]) printf("counter");
                printf("clockwise\n");
            } else {
                printf("%lld/%lld ", p[i], q[i]);
                if(!c[i]) printf("counter");
                printf("clockwise\n");
            }
        }
    }
}
