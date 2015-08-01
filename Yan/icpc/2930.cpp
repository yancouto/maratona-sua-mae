// ALMOST
#include <bits/stdc++.h>
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
char conv[64]; int fr[256];
void pre() {
	int sz = 0, i;
	for(i = 'A'; i <= 'Z'; i++)
		conv[sz++] = i;
	for(i = 'a'; i <= 'z'; i++)
		conv[sz++] = i;
	for(i = '0'; i <= '9'; i++)
		conv[sz++] = i;
	conv[sz++] = '+';
	conv[sz++] = '\\';
	for(i = 0; i < sz; i++)
		fr[conv[i]] = i;
}

struct fing {
	int a[1002], sz;
	void shift_left() {
		for(int i = 0; i < sz; i++)
			a[i] <<= 1;
		for(int i = 0; i < sz; i++)
			if(a[i] & (1 << 6)) {
				a[i] ^= (1 << 6);
				a[(i + sz - 1) % sz] |= 1;
			}
	}
	bool operator < (const fing &o) const {
		for(int i = 0; i < sz; i++)
			if(a[i] != o.a[i])
				return a[i] < o.a[i];
		return false;
	}
	bool operator == (const fing &o) const {
		for(int i = 0; i < sz; i++)
			if(a[i] != o.a[i])
				return false;
		return true;
	}
	void deb() {
		for(int i = 0; i < sz; i++)
			for(int j = 5; j >= 0; j--)
				printf("%d", !!(a[i] & (1 << j)));
		putchar('\n');
	}
	void from(char *str) {
		for(sz = 0; str[sz]; sz++)
			a[sz] = fr[str[sz]];
	}
} fs[1002];
int ps[1002];
bool cmp(int i, int j) {
	return fs[i] < fs[j];
}

bool cmp2(pii a, pii b) {
	if(a.fst == b.fst) return ps[a.snd] < ps[b.snd];
	return a.fst < b.fst;
}

char str[1002];
int main() {
	pre(); int t = 0, i, j, n;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 0; i < n; i++) {
			scanf(" %s", str);
			fs[i].from(str);
			fing aux(fs[i]);
			//printf("before "); fs[i].deb();
			for(j = 0; j < 6*(fs[i].sz + 1); j++) {
				fs[i].shift_left();
				if(fs[i] < aux) aux = fs[i];
			}
			if(aux < fs[i]) fs[i] = aux;
			printf("after  "); fs[i].deb();
			if(i > 0) printf("eq %d %d\n", fs[i] < fs[i-1], fs[i-1] < fs[i]);
			ps[i] = i;
		}
		puts("done");
		stable_sort(ps, ps + n, cmp);
		puts("done2");
		vector<pii> conj;
		for(i = 0; i < n;) {
			for(j = i + 1; j < n && fs[j] == fs[j - 1]; j++);
			conj.pb(pii(j - i, i));
			i = j;
		}
		sort(conj.begin(), conj.end(), cmp2);
		printf("Case %d:\n", ++t);
		for(i = 0; i < conj.size(); i++) {
			printf("%d", ps[conj[i].snd] + 1);
			for(j = 1; j < conj[i].fst; j++)
				printf(" %d", ps[conj[i].snd + j] + 1);
			putchar('\n');
		}
	}
}
