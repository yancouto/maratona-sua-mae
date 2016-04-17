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

const int MAXN = 2510;

int mrk[MAXN], n;

vector <int> res;

int main (){
	for_tests(t, tt){
		memset(mrk, 0, sizeof(mrk));
		scanf("%d", &n);
		for(int a=0;a<2*n-1;a++){
			for(int b=0;b<n;b++){
				int i;
				scanf("%d", &i);
				mrk[i]++;
			}
		}
		for(int a=0;a<2505;a++){
			if(mrk[a]&1){
				res.pb(a);
			}
		}
		sort(res.begin(), res.end());
		printf("Case #%d:", tt);
		for(int v:res){
			printf(" %d", v);
		}
		printf("\n");
		res.clear();
	}
}