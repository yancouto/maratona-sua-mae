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

set<int> st;

void show() {
	set<int>::iterator it;
	for(it = st.begin(); it != st.end(); ++it)
		printf("%d ", *it);
	putchar('\n');
}

int main() {
	int n, b, l, r;
	set<int>::iterator it, it2, it3;
	while(42) {
		scanf("%d %d", &n, &b);
		if(!n && !b) break;
		for(int i = 1; i <= n; i++)
			st.insert(i);
		while(b--) {
			int ra = 0;
			scanf("%d %d", &l, &r);
			it = st.find(l);
			if(it != st.begin()) { it--; ra = *it; it++; }
			it2 = st.find(r); it2++;
			while(it != it2) {
				it3 = it; it3++;
				st.erase(it);
				it = it3;
			}
			if(!ra) printf("* ");
			else printf("%d ", ra);
			it = st.lower_bound(r+1);
			if(it == st.end()) printf("*\n");
			else printf("%d\n", *it);
		}
		puts("-");
	}
	return 0;
}
