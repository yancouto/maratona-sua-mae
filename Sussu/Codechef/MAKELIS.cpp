

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

const int MAXN = 212345;

int nn;

int pot[20], prox[20], pre[20];

vector <int> fim, v[20];

int main (){
	for_tests(t, tt){
		for(int a=0;a<=16;a++){
			v[a].clear();
			fim.clear();
		}
		memset(pot, 0, sizeof(pot));
		scanf("%d", &nn);
		int n = nn;
		int tam = 0;
		int ult = -1;
		for(int e = 16;e >= 0;e--){
			prox[e] = e;
			pre[e] = 0;
			if((1 << e) <= n){
				if(ult != -1) prox[e] = ult;
				pre[ult] = e;
				ult = e;
				pot[e] = 1;
				n -= (1 << e);
				tam = max(tam, (1 << e));
			}
		}
		int val = 1;
		if(pot[0] == 1){ 
			fim.push_back(val);
			val++;
			for(int d = 2;d<=prox[0];d++){
				fim.push_back(val);
				val++;
			}
		}
		for(int a=1;a<=16;a++){
			if(!pot[a]) continue;
			for(int d=2*pre[a]+1;d<=2*a;d++){
				if(d&1)
					v[a].push_back(val+1);
				else
					v[a].push_back(val-1);
				val++;
			}
			for(int d = a+1;d <= prox[a];d++){
				fim.push_back(val);
				val++;
			}
		}
		printf("%d\n", val-1);
		for(int a=0;a<=16;a++){
			//printf("%d sz %d\n", a, v[a].size());
			//scanf("%*d");
			for(int num:v[a]){
				printf("%d ", num);
			}
		}
		for(int num: fim){
			printf("%d ", num);
		}
		putchar('\n');
	}
}
