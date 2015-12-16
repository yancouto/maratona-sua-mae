#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb pusupply_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1000;

int val[N], nx[N], pr[N];

int supply[N], discard[N], tn, top[N];
int empty_n = 0, n;

void deb(int x) {
	printf("[%d]Supply: ", x);
	for(int u = nx[supply[x]]; u != supply[x]; u = nx[u])
		putchar('A' + val[u]);
	printf("\n[%d]Discard: ", x);
	for(int u = nx[discard[x]]; u != discard[x]; u = nx[u])
		putchar('A' + val[u]);
	printf("\n..............\n");
}

int mvs, a[N];
// a -> b
void conflict(int a, int b) {
	//printf("conflicting %d -> %d\n", a, b);
	// discardard a below supply b
	//nx[pr[discard[a]]] = nx[supply[b]];
	//pr[nx[discard[a]]] = supply[b];
	//pr[nx[supply[b]]] = pr[discard[a]];
	//nx[supply[b]] = nx[discard[a]];
	//nx[discard[a]] = pr[discard[a]] = discard[a];
	// discardard b inverted on supply b
	for(int u = pr[discard[b]]; u != discard[b]; ) {
		int v = pr[u];
		pr[u] = supply[b];
		nx[u] = nx[supply[b]];
		pr[nx[u]] = u;
		nx[pr[u]] = u;
		u = v;
	}
	for(int u = pr[discard[a]]; u != discard[a]; ) {
		int v = pr[u];
		pr[u] = supply[b];
		nx[u] = nx[supply[b]];
		pr[nx[u]] = u;
		nx[pr[u]] = u;
		u = v;
	}
	nx[discard[b]] = pr[discard[b]] = discard[b];
	nx[discard[a]] = pr[discard[a]] = discard[a];
	//puts("conflicting done");
}


void turn(int t) {
	if(false && t < 10) {
		printf("Turn %d:\n", t);
		for(int i = 0; i < n; i++)
			deb(i);
	}
	for(int i = 0; i < n; i++) {
		if(nx[supply[i]] == supply[i]) continue;
		mvs++;
		if(mvs >= 1000000) return;
		if(nx[discard[i]] != discard[i]) top[val[pr[discard[i]]]] = -1;
		int v = pr[supply[i]];
		// rem
		nx[pr[v]] = nx[v];
		pr[nx[v]] = pr[v];
		// add
		pr[v] = pr[discard[i]];
		nx[v] = discard[i];
		pr[nx[v]] = v;
		nx[pr[v]] = v;
		empty_n += (nx[supply[i]] == supply[i]);
		//printf("after move of %d [%c]\n", i, val[v] + 'A');
		//deb(i);
		if(top[val[v]] != -1) {
			int A = top[val[v]], B = i;
			if(a[B] < a[A]) swap(A, B);
			if(nx[supply[B]] == supply[B]) empty_n--;
			conflict(A, B);
			top[val[v]] = -1;
			if(nx[supply[A]] == supply[A]) { printf("Player %d wins after %d moves.\n", A + 1, mvs); exit(0); }
		}
		else {
			top[val[v]] = i;
			if(empty_n == n) { printf("Draw after %d moves.\n", mvs); exit(0); }
		}
	}
}

char s[1000];
int main() {
	freopen("jungle.in", "r", stdin);
	freopen("jungle.out", "w", stdout);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < 26; i++)
		top[i] = -1;
	for(i = 0; i < n; i++) {
		scanf("%s", s);
		supply[i] = tn++;
		pr[supply[i]] = nx[supply[i]] = supply[i];
		discard[i] = tn++;
		pr[discard[i]] = nx[discard[i]] = discard[i];
		for(j = 0; s[j]; j++) {
			int v = tn++;
			val[v] = s[j] - 'A';
			// nx[v] = supply[i]; pr[v] = pr[supply[i]];
			nx[v] = nx[supply[i]]; pr[v] = supply[i];
			nx[pr[v]] = v; pr[nx[v]] = v;

		}
	}
	for(i = 1; mvs <= 1000000; i++)
		turn(i);
	puts("Abandoned after 1000000 moves.");
}
