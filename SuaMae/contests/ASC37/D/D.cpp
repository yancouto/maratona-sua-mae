
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

const int MAXN = 409;

int n, m[MAXN][MAXN], car[MAXN], mrk[MAXN], res[MAXN];

vector <int> adj[MAXN];

int go(int v){
	int ver = 0;
	mrk[v] = 1;
	for(int nxt : adj[v]){
		if(!mrk[nxt])
			ver = max(ver, go(nxt));
		else if(mrk[nxt] == 1)
			ver = 1;
	}
	mrk[v] = 2;
	return ver;
} 

int main (){
	freopen("bubble.in","r", stdin);
	freopen("bubble.out","w", stdout);
	scanf("%d", &n);
	for(int a=0;a<n-1;a++){
		car[a] = a;
		for(int b=0;b<=a;b++){
			scanf("%d", &m[a][b]);
		}
	}
	car[n-1] = n-1;
	for(int b=0;b<n-1;b++){
		for(int a=n-2;a>=b;a--){
			if(m[a][b] == 1){
				adj[car[a]].pb(car[a+1]);
	///			printf("liga %d %d\n", car[a], car[a+1]);
				swap(car[a], car[a+1]);
			}
			else{
				adj[car[a+1]].pb(car[a]);
		///		printf("liga %d %d\n", car[a+1], car[a]);
			}
		}
	}
	int ver = 0;
	for(int a=0;a<n;a++){
		if(mrk[a] == 0)
			ver = max(ver,go(a));
	}
	if(ver){
		puts("NO");
	}
	else{
		puts("YES");
		for(int a=0;a<n;a++){
			res[car[a]] = a+1;
		}
		for(int a=0;a<n;a++){
			printf("%d ", res[a]);
		}
		putchar('\n');
	}
	
	
}
