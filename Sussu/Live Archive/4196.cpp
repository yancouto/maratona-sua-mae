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

const int MAXN = 30;

double adj[300][300];

int deg[MAXN], n;

queue <int> q;

double para(double a, double b){
	if(a == 0) return b;
	if(b == 0) return a;
	return 1./(1./a + 1./b);
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		for(int a=0;a<n;a++){
			char i, j;
			double r;
			scanf(" %c %c %lf", &i, &j, &r);
			double val = r;
			if(adj[i][j] != 0){
				val = para(adj[i][j], r);
				deg[i]--;
				deg[j]--;
			}

			adj[i][j] = val; 
			adj[j][i] = val;
			deg[i]++;
			deg[j]++;
		}
		for(int a=0;a<n;a++){
			if(deg[a] == 2){
				q.push(a);	
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			int i=-1, j=-1;
			for(int a='A';a<='Z';a++){
				if(adj[u][a] != 0){
					if( i == -1 )
						i = a;
					else
						j = a;
				}
			}
			if(adj[i][j] != 0){
				deg[i]--;
				deg[j]--;
			}
			adj[i][j] = para(adj[i][j], adj[i][u] + adj[u][j]);
			adj[j][i] = adj[i][j];
			adj[i][u] = adj[u][j] = 0;
			adj[u][i] = adj[j][u] = 0;
			if(deg[i] == 2)
				q.push(i);
			if(deg[j] == 2)
				q.push(j);
		}
		int fodeu = 0;
		for(int a='A';a<='Z';a++){
			for(int b='A'+1;b<'Z';b++){
				if(adj[a][b] != 0.)
					fodeu = 1;
			}
		}
		if(fodeu)
			puts("-1.000");
		else
			printf("%.10f\n", adj['A']['Z']);
	}
}
