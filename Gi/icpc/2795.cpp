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

vector<int> v[40000];
int memo[110][40000];
int a[15], n;

int count(int x) { return __builtin_popcount(x); }

bool ok(int a, int b) { return a % b == 0; }
void generate(int i, int mm, int mask) {
	if(i == n) { 
		if(mm != mask && mm != 0 && v[mask].size() <= ((1<<n)/2 - 1)) 
			v[mask].pb(mm); 
		return ; 
	}
	if(mask & (1 << (n-i-1)))
		generate(i + 1, mm | (1 << (n-i-1)), mask);
	generate(i + 1, mm, mask);
}

int countsum(int mask) {
	int ret = 0;
	for(int i = 0; i < n; i++)
		if(mask&(1<<i)) ret += a[n-i-1];
	return ret;
}

bool solve(int w, int mask, int sm) {
	if(count(mask) == 1) return true;
	int &me = memo[w][mask];
	if(me != -1) return me;
	if(v[mask].empty()) generate(0, 0, mask);
	int h = sm / w;
	for(int mm : v[mask]) {
		int smb = countsum(mm);
		if(ok(smb, h) && solve(smb/h, mm, smb) && solve(w - smb/h, mask^mm, sm-smb)) return me = true;
		if(ok(smb, w) && solve(smb/w, mm, smb) && solve(w, mask^mm, sm-smb)) return me = true;
	}
	return me = false;
}

int main() {
	int i, sm, x, y, c = 0;
	while(42) {
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		if(!n) return 0;
		scanf("%d %d", &x, &y);
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sm = accumulate(a, a+n, 0);
		printf("Case %d: ", ++c);
		if(x*y != sm) { puts("No"); continue; }
		if(solve(x, (1<<n) - 1, sm)) puts("Yes");
		else puts("No");
	}
	return 0;
}
