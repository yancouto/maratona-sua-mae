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
const int N = 400009, Q = 10009;
int tr[N][26], r[N], h[N], d[N], seen[N];
bool leaf[N];
struct cmp {
	bool operator()(int i, int j) {
		if(r[i] != r[j]) return r[i] > r[j];
		return d[i] < d[j];
	}
};
set<int, cmp> sug[N];
//string st[N];

int tempo;
void dfs(int u, int hh) {
	h[u] = hh; d[u] = tempo++;
	for(int i = 0; i < 26; i++)
		if(tr[u][i]) {
			dfs(tr[u][i], hh + 1);
			for(int k : sug[tr[u][i]]) sug[u].insert(k);
			if(leaf[tr[u][i]]) sug[u].insert(tr[u][i]);
		}
}

int tn;
int add(char *s) {
	int v = 0;
	for(int i = 0; s[i]; i++) {
		if(!tr[v][s[i] - 'a'])
			tr[v][s[i] - 'a'] = ++tn;
		//st[tr[v][s[i] - 'a']] = st[v] + s[i];
		v = tr[v][s[i] - 'a'];
	}
	leaf[v] = true;
	return v;
}


char s[20];
char qs[Q][20];
int main() {
	freopen("goondex.in", "r", stdin);
	freopen("goondex.out", "w", stdout);
	int i, j, n, q;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", s);
		scanf("%d", &r[add(s)]);
	}
	scanf("%d", &q);
	int tot = 0;
	for(i = 0; i < q; i++) {
		scanf("%s", qs[i]);
		add(qs[i]);
		tot += strlen(qs[i]);
	}
	dfs(0, 0);
	int mov = 0;
	for(j = 0; j < q; j++) {
		strcpy(s, qs[j]);
		int v = 0;
		for(i = 0; s[i]; i++) {
			v = tr[v][s[i] - 'a'];
			seen[v] = j + 1;
		}
		int last = v;
		v = 0;
		for(i = 0; s[i]; i++) {
			mov++;
			//printf("1.at %d = %s [%d]\n", v, st[v].c_str(), i);
			v = tr[v][s[i] - 'a'];
			//printf("2.at %d = %s\n", v, st[v].c_str());
			while(!(sug[v].empty() || seen[*sug[v].begin()] != j + 1 || r[*sug[v].begin()] == 0)) {
				//printf("moving %d->%d\n", v, *sug[v].begin());
				i += h[*sug[v].begin()] - h[v];
				v = *sug[v].begin();
				if(v != last) mov++;
			}
		}
		v = 0;
		for(i = 0; s[i + 1]; i++) {
			v = tr[v][s[i] - 'a'];
			sug[v].erase(last);
		}
		r[last]++; v = 0;
		for(i = 0; s[i + 1]; i++) {
			v = tr[v][s[i] - 'a'];
			sug[v].insert(last);
		}
	}
	printf("%d %d\n", mov + q, q + tot);
}
