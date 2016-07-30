
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

const int MAXN = 1123;

int n, m, l[MAXN], c[MAXN];

char M[MAXN][MAXN];

int tot;

int test(int i, int j){
	int t = 0;
	for(int a=0;a<n;a++){
		if(M[a][j] == '*')
			t++;
	}
	for(int b=0;b<m;b++){
		if(M[i][b] == '*')
			t++;
	}
	return ((t - (M[i][j] == '*')) == tot);
}

int main (){
	tot = 0;
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == '*')
				tot++;
		}
	}
	int res = 1;
	int lin = -1;
	for(int a=0;a<n;a++){
		int cnt = 0;
		for(int b=0;b<m;b++){
			if(M[a][b] == '*'){
				cnt++;
			}
		}
		l[a] = cnt;
		if(cnt > 1){
			if(lin == -1)
				lin = a;
			else
				res = 0;
		}
	}
	int col = -1;
	for(int b=0;b<m;b++){
		int cnt = 0;
		for(int a=0;a<n;a++){
			if(M[a][b] == '*'){
				cnt++;
			}
		}
		if(cnt > 1){
			if(col == -1)
				col = b;
			else
				res = 0;
		}
		c[b] = cnt;
	}
	if(lin == -1 && col == -1 && tot > 2){
		puts("NO");
		return 0;
	}
	else if(lin == -1 && col == -1 && tot == 2){
		int deg = 0;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(M[a][b] == '*'){
					if(deg)
						lin = a;
					else
						col = b;
				}
			}
		}
	}
	else if(lin == -1 && col == -1 && tot == 1){
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				if(M[a][b] == '*'){
					lin = a;
					col = b;
				}
			}
		}
	}
	if(tot == 0){
		puts("YES\n1 1");
		return 0;
	}
	if(lin == -1){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(b == col) continue;
				if(M[a][b] == '*')
					lin = a;
			}
		}
	}
	if(lin == -1)
		lin = 0;
	if(col == -1){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(a == lin) continue;
				if(M[a][b] == '*')
					col = b;
			}
		}
	}
	if(col == -1)
		col = 0;
	res = test(lin, col);
	lin++;
	col++;

	if(res)
		printf("YES\n%d %d\n", lin, col);
	else
		puts("NO");
}
