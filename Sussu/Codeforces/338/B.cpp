#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100010;

int n, m, mrk[MAXN];

ll res, s[MAXN], dis[MAXN];

vector<int> adj[MAXN];



int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<m;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}
	for(int a = 1;a<=n;a++){
		s[a] = adj[a].size();
	}
	memset(dis,0,sizeof(dis));
	for(int a=1;a<=n;a++){
		dis[a] = max(dis[a],1ll);
		for(int i = 0;i<adj[a].size();i++){
			int nxt = adj[a][i];
			if(nxt > a)
				dis[nxt] = max(dis[a]+1,dis[nxt]);
		}
		res = max(dis[a]*s[a],res);
	}

	cout << res;
}