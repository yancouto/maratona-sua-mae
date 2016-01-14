#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2010;

ll d[MAXN][MAXN], res;

int n;

struct pti{
	ll i, j;
} p[MAXN];

int main (){
	for_tests(t,tt){
		res=0;
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			d[a][a] = -1;
			scanf("%lld %lld", &p[a].i, &p[a].j);
			for(int b=0;b<a;b++){
				d[b][a] = (p[a].i-p[b].i)*(p[a].i - p[b].i) + (p[a].j - p[b].j)*(p[a].j - p[b].j);
				d[a][b] = d[b][a]; 
			}
		}
		for(int a=0;a<n;a++){
			sort(d[a],d[a]+n);
			int cnt = 0;
			for(int b = 1;b<n;b++){
				if(d[a][b] != d[a][b-1]){
					res += (cnt*(cnt-1))/2;
					cnt=0;
				}
				cnt++;
			}
			res += (cnt*(cnt-1))/2;
			cnt=1;
		}
		printf("Case #%d: ", tt);
		printf("%lld\n", res);
	}
}