#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

char s[20]; int S, n;
int memo[20][83][2];

inline ll leq(int x) {
	sprintf(s, "%d", x);
	int n = strlen(s);
	for(int i = n; i >= 0; i--)
		for(int sum = 0; sum <= S; sum++)
			for(int pre = 0; pre <= 1; pre++) {
				int &r = memo[i][sum][pre];
				if(i == n) { r = (sum == S); continue; }
				r = 0;
				for(int d = 0; d <= 9; d++) {
					if(pre && d > s[i] - '0') break;
					r += memo[i + 1][sum + d][pre && d == s[i] - '0'];
				}
			}
	return memo[0][0][true];
}

char s2[20];
inline int num(int k, int SS) {
	S = SS;
	int l = 0, r = n - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(leq(m) > k) r = m - 1;
		else l = m;
	}
	return l;
}

int memo2[20][84][84][2];
int all(int i, int sum, int S, bool pre) {
	if(!s2[i]) return sum <= S;
	int &r = memo2[i][sum][S][pre];
	if(r != -1) return r;
	r = 0;
	for(int d = 0; d <= 9; d++) {
		if(pre && d > s2[i] - '0') break;
		r += all(i + 1, sum + d, S, pre && d == s2[i] - '0');
	}
	return r;
}

int main() {
	int i;
	scanf("%d", &n);
	sprintf(s2, "%d", n);
	memset(memo2, -1, sizeof memo2);
	int ans = 0;
	for(i = 1; i < 83; i++) {
		int k = all(0, 0, i - 1, true) - 1;
		int eq = all(0, 0, i, true) - all(0, 0, i - 1, true);
		if(eq == 0) break;
		int l = 1, r = eq;
		while(l < r) {
			int mid = (l + r) / 2;
			int nn = num(mid - 1, i) + 1;
			if(k + mid > nn) l = mid + 1;
			else r = mid;
		}
		int x = num(l - 1, i) + 1;
		if(x == k + l) ans++;
	}
	printf("%d\n", ans);
}
