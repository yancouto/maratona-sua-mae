namespace sf {
const int NS = ;
const int N = ;

int cn, cd, ns, en = 1;
string S[NS];
struct edge {
	int a, b;
	int v, si;
	inline int len() { return b - a + 1; }
	inline char operator[](int i) { return S[si][a + i]; }
} ce;

int suf[N], p[N];
map<char, edge> tr[N];
int si = -1;

void sufftree(string s) {
	s += '$'; S[++si] = s;
	ns = cn = cd = 0; int i = 0, j, n = s.size();
	for(j = 0; j < n; j++)
		for(; i <= j; i++) {
			if(ns && !cd) suf[ns] = cn, ns = 0;
			if(cd? ce[cd] == s[j] : tr[cn].count(s[j])) {
				if(cd++ == 0) ce = tr[cn][s[j]];
				if(cd == ce.len()) cd = 0, cn = ce.v;
				break;
			} else if(cd) {
				if(ns) suf[ns] = en;
				tr[en][ce[cd]] = {ce.a + cd, ce.b, ce.v, ce.si};
				tr[en][s[j]] = {j, n - 1, en + 1, si};
				tr[cn][ce[0]] = {ce.a, ce.a + cd - 1, en, ce.si};
				p[en] = cn; p[en + 1] = p[ce.v] = en;
				ns = en;
				en += 2;
				int g = cn? j - cd : i + 1;
				cn = suf[cn];
				while(g < j && g + tr[cn][s[g]].len() <= j) {
					ce = tr[cn][s[g]];
					cn = ce.v;
					g += ce.len();
				}
				cd = j - g;
				if(cd) ce = tr[cn][s[g]];
			} else {
				p[en] = cn;
				tr[cn][s[j]] = {j, n - 1, en++, si};
				cn = suf[cn];
			}
		}
}

void clear_all() {
	for(int i = 0; i < en; i++)
		tr[i].clear();
	en = 1; si = -1;
}

// chame pra todas strings pra marcar os finais
void proc(string &s, int si) {
	cn = cd = 0;
	for(char c : s) {
		if(cd++ == 0) ce = tr[cn][c];
		if(cd == ce.len()) cd = 0, cn = ce.v;
	}
	// marque o fim de si no vert cn
	for(int i = 1; i < s.size(); i++) {
		cn = p[cn];
		int g = cn? s.size() - ce.len() : i;
		cn = suf[cn];
		while(g != s.size()) {
			ce = tr[cn][s[g]];
			g += ce.len();
			cn = ce.v;
		}
		// marque o fim de si no vert cn
	}
}
};
