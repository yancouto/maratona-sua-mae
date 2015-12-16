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

int x, y, xx, yy, ans[100010];
char s[100010];
set<pii> st;

int main() {
	int i, r = 0, n;
	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	scanf("%s", s+1);
	n = strlen(s+1);
	xx--; yy--;
	ans[0] = 1;
	st.insert(pii(xx, yy));
	for(i = 1; i < n; i++) {
		if(s[i] == 'U') xx -= (xx != 0);
		if(s[i] == 'D') xx += (xx != x-1);
		if(s[i] == 'R') yy += (yy != y-1);
		if(s[i] == 'L') yy -= (yy != 0);
		if(st.count(pii(xx, yy)))
			ans[i] = 0;	
		else { ans[i]++; st.insert(pii(xx, yy)); }
	}
	for(i = 0; i < n; i++) printf("%d ", ans[i]), r += ans[i];
	printf("%d\n", x * y - r);
	return 0;
}
