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

int m[60][40][40];

int x[60], y[60];

int n;

void create(int x, int y, int c, int i){
	for(int a=y-14;a<y+14;a++){
		for(int b=x-14;b<x + 14;b++){
			if(dm(a, b, x, y) <= c+2 && (a != y && b != x)){
				m[i][a][b] = 1;
			}
		}
	}
}

void inter(int i, int j){
	for(int a=y[i] - 14;a<y[i]+14;a++){
		for(int b=x[i]-14;b<x[i]+14;b++){
			if(dm(a, b, x[i], y[i]) <= c[i] + 2 && (a != y[i] && b != x[i])){
				for(int d=y[j] - 14;d<y[j]+14;d++){
					for(int e=x[j]-14;e<x[j]+14;e++){
						if(a != d || b != e)
							continue;
						if(dm(d, e, x[j], y[j]) <= c[j] + 2 && (d != y[j] && e != x[j])){
							m[j][d][e] = 0;
						}
					}
				}
			}
			else if( dm(a, b, x[i], y[i]) == c[i]+3 && x[i] != b && y[i] != a){
				for(int d=y[j] - 14;d<y[j]+14;d++){
					for(int e=x[j]-14;e<x[j]+14;e++){
						if(dm(d, e, x[i], y[i]) == c[j]+3 && x[j] != e && y[j] != d){
							m[j][d][e] = 1;
						}
					}
				}
			}

		}
	}
}
}

int main (){
	scanf("%d", &n);

	for(int a=0;a<n;a++){
		scanf("%d%d%d", &x[a], &y[a], &c[a]);
		create(x[a], y[a], c[a], a);
	}

	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			inter(a, b);
		}
	}
}
