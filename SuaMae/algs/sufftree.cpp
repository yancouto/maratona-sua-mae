namespace sf {
const int NS = 112345;
const int N = 212345;

int cn, cd, cc, li, ns, en = 1, es[N];
inline int r(int b, int si) { return b == N? es[si] : b; }
string s[NS];
struct edge {
	int a, b;
	int n, si;
	inline int len() { return r(b, si) - a + 1; }
	inline char operator[](int i) { return s[si][a + i]; }
};

int suf[N], p[N];
map<char, edge> tr[N];
int si = -1;

void add() {
	int &e = es[si];
	string &s = sf::s[si];
	e++;
	for(; li <= e; li++) {
		if(ns && cd == 0) suf[ns] = cn, ns = 0;
		if(cd? tr[cn][cc][cd] == s[e] : tr[cn].count(s[e])) {
			if(cd++ == 0) cc = s[e];
			if(cd == tr[cn][cc].len()) cd = 0, cn = tr[cn][cc].n;
			break;
		}
		tr[en].clear();
		if(cd) {
			if(ns) suf[ns] = en;
			tr[en + 1].clear();
			edge &ed = tr[cn][cc];
			char w = ed[cd];
			tr[en][w] = ed;
			tr[en][w].a += cd;
			tr[en][s[e]] = edge{e, N, en + 1, si};
			p[en] = cn;
			p[en + 1] = p[tr[cn][cc].n] = en;
			ns = en;
			ed.b = ed.a + cd - 1;
			ed.n = en++; en++;
			int g = cn? e - cd : li + 1;
			cn = suf[cn];
			while(tr[cn].count(cc = s[g]) && g + tr[cn][s[g]].len() <= e) {
				g += tr[cn][cc].len();
				cn = tr[cn][cc].n;
			}
			cd = e - g;
		} else {
			p[en] = cn;
			tr[cn][s[e]] = edge{e, N, en++, si};
			cn = suf[cn];
		}
	}
}

void reset() {
	tr[0].clear();
	en = 1; si = -1;
}

void sufftree(string ss) {
	si++;
	es[si] = -1;
	ss += '$';
	s[si] = ss;
	ns = cn = cd = cc = li = 0;
	for(int i = 0; i < ss.size(); i++) add();
}

// chame pra todas strings pra marcar os finais
void proc(string &s, int si) {
	cn = cc = cd = 0;
	for(char c : s) {
		if(cd++ == 0) cc = c;
		if(cd == tr[cn][cc].len()) cd = 0, cn = tr[cn][cc].n;
	}
	// marque o fim de si no vert cn
	for(int i = 1; i < s.size(); i++) {
		cn = p[cn];
		int g = cn? s.size() - tr[cn][cc].len() : i;
		cn = suf[cn];
		while(g != s.size()) {
			cc = s[g];
			g += tr[cn][cc].len();
			cn = tr[cn][cc].n;
		}
		// marque o fim de si no vert cn
	}
}
};
