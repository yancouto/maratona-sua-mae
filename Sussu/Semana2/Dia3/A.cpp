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


const int MAXN = 110;

int n, m;

char s[MAXN][MAXN], p[MAXN];

int v[30][MAXN];

int main (){
	memset(v, -1, sizeof(v));
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
	}
	int tam = strlen(s[0]);
	for(int i=0;i<n;i++){
		for(int a=0;a<tam;a++){
			v[s[i][a] - 'a'][a] = i;
		}
	}
	int fodeu = 0;
	scanf(" %s", p);
	int tp = strlen(p);
	for(int a=0;a<tp;a++){
		if(v[p[a] - 'a'][a] == -1)
			fodeu = 1;
	}
	if(fodeu){
		puts("-1");
		return 0;
	}
	int mx = -1, imx;
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int a=0;a<tam;a++){
			if(s[i][a] == p[a])
				cnt++;

		}
		if(cnt > mx){
			mx = cnt;
			imx = i;
		}
	}

	int res = 0;
	for(int a=0;a<tam;a++){
		if(s[imx][a] != p[a]){
			res++;
		}
	}
	printf("%d\n", res);
	for(int a=0;a<tam;a++){
		if(s[imx][a] != p[a]){
			printf("%d %d %d\n", imx+1, v[p[a] -'a'][a]+1, a+1);
		}
	}
}
