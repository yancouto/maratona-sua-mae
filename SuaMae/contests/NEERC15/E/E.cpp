
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

int n, k, cnt, deg[15], p[15], v[15][15], res;

int main(){
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int cntmax = 0;
	for(int a=0;a<n;a++){
		scanf("%d", &p[a]);
		cntmax += p[a];
		for(int b=0;b<p[a];b++){
			scanf("%d", &v[a][b]);
		}
	}
	int cntdeg = 0;
	int sum = 0;
	while(cnt < k && cntdeg < cntmax+n){
		for(int a=0;a<n && cnt<k;a++){
			if(deg[a] >= p[a]){
				//printf("pega 50 de %d\n", a); 
				sum += 50;
				cnt++;
				continue;
			}
			if(v[a][deg[a]] >= sum){
			//	printf("pega %d de %d\n", v[a][deg[a]], a);
				sum += v[a][deg[a]];
				cnt++;
				deg[a]++;
				cntdeg++;
			}
			else{
				deg[a]++;
				cntdeg++;
			}
		}
	}
	if(cnt < k){
	//	printf("add %d*50\n", k-cnt);
		sum+=50*(k-cnt);
	}
	printf("%d\n", sum);

}
