#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nu[100009]; char ty[100009];

ll mdc(ll a, ll b) {
    if(b == 0) return a;
    return mdc(b, a % b);
}

int main() {
    int tt, n, i;
    scanf("%d", &tt);
    while(tt--) {
	scanf("%d", &n);
	ll t[2] = {0, 0};
	for(i = 0; i < n; i++) {
	    scanf("%lld %c", &nu[i], &ty[i]);
	    t[ty[i] == 'W'] += nu[i];
	}
	if(!t[0] || !t[1]) { printf("%lld\n", t[1] + t[0]); continue; }
	ll m = mdc(t[0], t[1]);
	t[0] /= m;
	t[1] /= m;
	ll c[2] = {0, 0};
	int tot = 0;
	for(i = 0; i < n; i++) {
	    bool w = (ty[i] == 'W');
	    c[w] += nu[i];
	    if(c[!w] && (c[!w] % t[!w]) == 0 && c[w] >= (c[!w]/t[!w]) * t[w]) {
		c[w] -= (c[!w]/t[!w]) * t[w];
		c[!w] = 0;
		tot++;
	    }
	}
	printf("%d\n", tot);
    }
    return 0;
}
