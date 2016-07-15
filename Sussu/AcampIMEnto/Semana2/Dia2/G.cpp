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

const int MAXN = (1<<14)+2;

int n, s[MAXN];
int st[MAXN], deg = 1, degs = 0, ns[MAXN];

int main (){
	scanf("%d", &n);
	int tam = (1<<n);
	for(int a=0;a<(1<<n);a++){
		scanf("%d", &s[a]);
	}
	st[0] = INT_MAX;
	int sqt, cnt, ate;
	for(int a=0;a<n;a++){
		degs = 0;
		deg = 1;
		sqt = (1<<n)/(1<<(a+1));
		ate = sqt;
		cnt = 0;
		for(int b=0;b<tam;b++){
			if(s[b] <= ate){
				cnt++;
				printf("%d %d ", s[b], s[b]);
				ns[degs++] = s[b];
				if(cnt == sqt){
					cnt = 0;
					ate += sqt;
				}
			}
			else{
				printf("%d ", s[b]);
				st[deg++] = s[b];
			}
			while(st[deg-1] <= ate){
				cnt++;
				printf("%d ", st[deg-1]);
				ns[degs++] = st[deg-1];
				deg--;
				if(cnt == sqt){
					cnt = 0;
					ate += sqt;
				}
			}
		}
		while(deg > 1){
			printf("%d ", st[deg-1]);
			ns[degs++] = st[deg-1];
			deg--;
		}
		for(int b=0;b<tam;b++){
			s[b] = ns[b];	
		}
	}
	printf("\n");
}
