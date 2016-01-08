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

const int MAXN  = 'z' + 10;

int n, mrk[MAXN][45], pod[MAXN][MAXN];

vector<int> adj[MAXN], res;

void go(int v,int ant,int d){
	if(mrk[v][d] != -1) return ;
	if(d >= 40) return;
	mrk[v][d] = ant;
	for(int a='a';a<='z';a++){
		if(pod[v][a]){
			go(a,v,d+1);
		}
	}
}

int main (){
	for_tests(t,tt){
		memset(mrk,-1,sizeof(mrk));
		scanf("%d", &n);
		for(int a = 'a';a <='z';a++){
			adj[a].clear();
			for(int b = 'a';b<='z';b++){
				pod[a][b] = 1;
			}
		}

		for(int a=0;a<n;a++){
			char c1, c2;
			scanf(" %c%c", &c1, &c2);
			pod[c1][c2] = 0;
		}
		for(int a='a';a<='z';a++){
			go(a,0,1);
		}
		res.clear();
		int flag = 1;
		for(int d=39;flag && d>=0;d--){
			for(int a = 'a';flag && a <= 'z';a++){
				if(mrk[a][d] != -1){
					flag = 1;
					while(a){
						res.pb(a);
						a = mrk[a][d];
						d--;
					}
				}
			}
		}
		int sz = res.size() - (res.size()%2 == 0);
		int tam = sz/2;
		for(int l = 0; l <= tam ; l++){
			for(int i = sz-1 - l; i >= (sz-1 - l - tam); i--){
				printf("%c", res[i]);
			}
			printf("\n");
		}
	}
}