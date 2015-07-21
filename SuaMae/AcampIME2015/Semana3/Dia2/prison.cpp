#include <bits/stdc++.h>
#define fst first
#define snd second
const int N = 407;
const int M = 103;

using namespace std;

vector<int> adj[N];
pair<int, int> v[N];
bool pris[N];
int memo[N][M][M];
int t, n, m, qtd;


int seen[N], tempo;
void dfs(int u) {
	if(seen[u] == tempo) return;
	seen[u] = tempo;
	if(pris[u]) v[qtd].fst++;
	else v[qtd].snd++;
	for(int v : adj[u])
		dfs(v);
}

bool pd (int i, int la, int lb, int k) {
	//printf("pd(%d, %d, %d, %d)\n", i, la, lb, k);
	if (la > k || lb > k)
		return 0;
	if (la == k && lb == k)
		return 1;
	if (i >= qtd)
		return 0;
	int &m = memo[i][la][lb];

	if (m != -1) return m;
	//printf("%d, %d\n", v[i].fst, v[i].snd);

	if (pd(i+1, la, lb, k))
		m = true;
	else
		m = pd(i+1, la+v[i].first, lb+v[i].second, k);

	return m;
}

bool possivel (int k) {
	memset(memo, -1, sizeof(memo));
	return pd(0, 0, 0, k);
}
int main () {
	int a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);

		for (int i = 0; i < 2*n; i++) {
			adj[i].clear();
			pris[i] = (i<n);		
			v[i] = make_pair(0, 0);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			a--;
			b += n-1;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		qtd = 0;
		tempo++;
		for(int i = 0; i < 2*n; i++)
			if(seen[i] < tempo) {
				dfs(i);
				qtd++;
			}
		// YAn

		int lo, hi, mid;
		//lo = 0;
		//hi = n/2;
		//mid = (lo+hi+1)/2;
		//while (lo < hi) {
		//	if (possivel(mid)) {
		//		printf("%d pos\n", mid);
		//		lo = mid;
		//	}
		//	else {
		//		printf("%d not pos\n", mid);
		//		hi = mid-1;

		//	}
		//	mid = (lo+hi+1)/2;
		//}
		for(mid = n / 2; mid >= 0; mid--)
			if(possivel(mid))
				break;

		printf("%d\n", mid);
	}
}
