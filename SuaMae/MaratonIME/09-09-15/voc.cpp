#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000009;
inline ll mod(ll x) { return x % modn; }

ll memo[1000003][2][2];
ll solve(int i, bool pre1, bool pre2) {
    if(i == n) return !pre1 && !pre2;
    ll &r = memo[i][pre1][pre2];
    if(r != -1) return r;

}

int main() {
    scanf("%d", &t);
    while(t--) {
	scanf("%s %s %s", s1, s2, s3);
	n1 = strlen(s1); n2 = strlen(s2); n3 = strlen(s3);
	n = max(n1, max(n2, n3)); nm = min(n1, min(n2, n3));
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, true, true));
    }
}
