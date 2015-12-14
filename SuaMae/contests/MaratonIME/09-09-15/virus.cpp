#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int f[256];
struct hs {
    ll h;
    bool operator == (hs o) const { return h == o.h; }
} hr[100009], hl[100009];
ll pot[100009];
char str[100009];
void pre() {
    f['A'] = 1; f['T'] = 2; f['C'] = 3; f['G'] = 4;
    pot[0] = 1;
    for(int i = 1; i < 100009; i++)
	pot[i] = mod(pot[i-1] * 7ll);
}
int n;
int eqlr(int i, int sz, int le, int ri) {
    if(!(i - sz + 1 >= le && i + sz <= ri)) return false;
    hs l, r;
    r.h = mod(hr[i + sz].h - hr[i].h + modn);
    l.h = mod(hl[i - sz + 1].h - hl[i + 1].h + modn);
    if(i > n - i) l.h = mod(l.h * pot[i - (n - i)]);
    else r.h = mod(r.h * pot[n - i - i]);
    //printf("(%d, %d, %d, %d) -> %lld == %lld\n", i, sz, le, ri, l.h, r.h);
    return l == r;
}

int solve(int l, int r) {
    int mnl = r + 1, mxr = l - 1;
    int mn = r - l + 1;
    for(int i = l; i < r; i++) {
	if(str[i] != str[i + 1]) continue;
	int ql = 1, qr = n;
	while(ql < qr) {
	    int qm = (ql + qr + 1) / 2;
	    if(eqlr(i, qm, l, r)) ql = qm;
	    else qr = qm - 1;
	}
	if(i - ql + 1 >= mnl && i + ql <= mxr) continue;
	mnl = min(mnl, i - ql + 1); mxr = max(mxr, i + ql);
	mn = min(mn, r - l + 1 - 2 * ql + 1 + solve(i + 1, i + ql));
    }
    return mn;
}

int main() {
    pre();
    int t, i;
    scanf("%d", &t);
    while(t--) {
	scanf("%s", str + 1);
	n = strlen(str + 1); hl[n + 1].h = 0;
	for(i = 1; i <= n; i++)
	    hr[i].h = mod(hr[i - 1].h + pot[i - 1] * f[str[i]]);
	for(i = n; i > 0; i--)
	    hl[i].h = mod(hl[i + 1].h + pot[n - i] * f[str[i]]);
	//for(i = 1; i <= n; i++)
	    //printf("%lld -- %lld\n", hr[i].h, hl[i].h);
	printf("%d\n", solve(1, n));
    }
}

