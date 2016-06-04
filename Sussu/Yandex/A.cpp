
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

const int MAXN = 1123, MAXC = 45;

int n;

char s[MAXN][MAXC];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
	}
	int tam = strlen(s[0]);
	for(int a=0;a<n;a++){
		int fodeu = 0;
		for(int b=0;b<n;b++){
			int err = 0;
			for(int c=0;c<tam;c++){
				if(s[a][c] != s[b][c])
					err++;
			}
			if(err > 1){
				fodeu = 1;
				break;
			}
		}
		if(!fodeu){
			printf("%s\n", s[a]);
			return 0;
		}
		/*if(!fodeu){
			for(int b=0;b<n;b++){
				int err = 0;
				for(int c=0;c<tam;c++){
					err += (s[a][c] != s[b][c]);
				}
				if(!err) printf("%s\n", s[b]);
			}
			return 0;
		}*/
	}
}
