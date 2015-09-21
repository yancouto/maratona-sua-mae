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

vector<int> g[1005], ga[1005];
int mark[1005];

void dfs(int no, int op) {
	if(mark[no]) return;
	mark[no] = 1;
	if(op == 1) {
		for(int i = 0; i < g[no].size(); i++)
			dfs(g[no][i], op);
	}
	else {
		for(int i = 0; i < ga[no].size(); i++)
			dfs(ga[no][i], op);
	}
}

int main() {
	int n, a, b;
	char input[10];
	fgets(input, 10, stdin);
	sscanf(input, "%d", &n);
	while(42) {
		fgets(input, 10, stdin);
		input[strlen(input)-1] = '\0';
		if(!strcmp(input, "BLOOD")) break;
		sscanf(input, "%d %d", &a, &b);
		g[b].pb(a); ga[a].pb(b);
	}
	while(scanf("%d", &a) != EOF) {
		mark[a] = 0; dfs(a, 1);
		mark[a] = 0; dfs(a, 2);
	}
	bool some = false;
	for(int i = 1; i <= n; i++) {
		if(!mark[i]) {
			printf("%d ", i);		
			some = true;
		}
	}
	if(!some) printf("0");
	putchar('\n');
	return 0;
}
