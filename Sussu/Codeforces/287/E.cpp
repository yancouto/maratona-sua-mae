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

const int MAXN = 1000010;

int n, deg, seq[MAXN], p[MAXN], pp[MAXN], m, pil[MAXN];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &pp[a]);
	}
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int i;
		scanf("%d", &i);
		pp[i-1] *= -1;
	}
	for(int a=0;a<n;a++){
		p[n-a-1] = pp[a];
	}
	for(int a=0;a<n;a++){
		if(deg==0){
			if(p[a]>0)
				p[a]*=-1;
			pil[deg++] = p[a];
		}
		else{
			if(p[a]>0){
				if(pil[deg-1] == -p[a])
					deg--;
				else{
					p[a]*=-1;
					pil[deg++] = p[a];
				}
			}
			else
				pil[deg++] = p[a];
		}
	}
	if(deg==0){
		puts("YES");
		for(int a=n-1;a>=0;a--){
			printf("%d ", p[a]);
		}
	}
	else
		puts("NO");
}