
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n, m, k, a, mv;
int mvs[200005];
set<int> st;

int main(){
	int i;
	scanf("%d %d %d %d", &n, &k, &a, &m);
	int tot = (n+1)/(a+1);
	st.insert(0);
	st.insert(n+1);	
	for(i = 0; i < m; i++){
		scanf("%d", &mv);
		set<int>::iterator it;
		it = st.lower_bound(mv);
		int end = *it; --it;
		int beg = *it;
		tot -= (end-beg)/(a+1);
		tot += (mv-beg)/(a+1) + (end-mv)/(a+1);
		if(tot < k) break;
		st.insert(mv);
	}
	if(i == m)
		printf("-1\n");
	else
		printf("%d\n", i+1);
	return 0;
}
