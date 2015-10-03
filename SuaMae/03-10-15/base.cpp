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

char line[105];

int val(char c) {
	if(c >= 'a' && c <= 'z') return c-'a'+10;
	return c-'1'+1;
}

bool check(ll x) { return x > ((1ll << 32) - 1); }

char get(int x) {
	if(x <= 9) return '0' + x ;
	return 'a' + x - 10;
}

char op;
bool isValid(int a, int b, int c) {
	if(op == '+') return a + b == c;
	if(op == '-') return a - b == c;
	if(op == '*') return a * b == c;
	if(op == '/') return (b)?((a % b) == 0 && a/b == c):false;
}

int main() {
	int n; 
	fgets(line, 100, stdin);
	sscanf(line, "%d", &n);
	while(n--) {
		char a[105], b[105], c[105];
		fgets(line, 105, stdin);
		sscanf(line, "%s %c %s = %s", a, &op, b, c);
		int na, nb, nc;
		na = strlen(a);
		nb = strlen(b);
		nc = strlen(c);
		int beg = 0, end = 40;
		for(int i = 0; i < na; i++) beg = max(beg, val(a[i])), end = min(end, val(a[i]));
		for(int i = 0; i < nb; i++) beg = max(beg, val(b[i])), end = min(end, val(b[i]));
		for(int i = 0; i < nc; i++) beg = max(beg, val(c[i])), end = min(end, val(c[i]));
		if(beg == 1 && end == 1) beg--; 
		bool um = false;
		for(int bas = beg + 1; bas <= 36; bas++) {
			ll va, vb, vc;
			va = vb = vc = 0;
			bool out = false;
			for(int i = 0; i < na; i++) {
				va *= bas, va += val(a[i]);
				if(check(va)) { out = true; break; }
			}
			if(out) continue;
			for(int i = 0; i < nb; i++) {
				vb *= bas, vb += val(b[i]);
				if(check(vb)) { out = true; break; }
			}
			if(out) continue;
			for(int i = 0; i < nc; i++) {
				vc *= bas, vc += val(c[i]);
				if(check(vc)) { out = true; break; }
			}
			if(out) continue;
			if(isValid(va, vb, vc)) { printf("%c", get(bas%36)); um = true; }
		}
		if(!um) printf("invalid");
		putchar('\n');
					
	}
	return 0;
}
