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

const int MAXN = 310, INF = 0x3f3f3f3f;

int x, y, cnt[MAXN][MAXN], cor[MAXN][MAXN], mrkl[MAXN];
char m[MAXN][MAXN];

int main (){
	for_tests(t, tt){
		scanf("%d%d", &x, &y);
		for(int a=0;a<x;a++){
			for(int b=0;b<y;b++){
				scanf(" %c", &m[a][b]);
			}
		}
		memset(cor, 0, sizeof(cor));
		memset(cnt, 0, sizeof(cnt));
		for(int a=0;a<x;a++){
			for(int b=y-1;b>=0;b--){
				if(m[a][b] != 'A'){
					cor[a][b] = cor[a][b+1];
					cnt[a][b] = cnt[a][b+1] + (m[a][b] == 'H');
				}
				else{
					cor[a][b] = 1 + cor[a][b+1];
					cnt[a][b] = 0;
				}
			}
		}
		int res = 0;
		memset(mrkl, 0, sizeof(mrkl));
		for(int b=0;b<y;b++){
			int men = INF, imen;
			for(int a=0;a<x;a++){
				if(m[a][b] == 'H' && !mrkl[a]){
					if(cnt[a][b] < men && cnt[a][b] > 0){
						men = cnt[a][b];
						imen = a;
					}
				}
				if(m[a][b] == 'A')
					mrkl[a] = 0;
			}
			if(men != INF){
				mrkl[imen] = 1;
				res++;
			}
		}
		printf("%d\n", res);
	}
}