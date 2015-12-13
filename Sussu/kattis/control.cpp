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


const int MAXI = 500010, MAXN = 200010;

int n, mrk[MAXI], ing[MAXI], ni[MAXN], p[MAXN], cntp[MAXN], res;

int main (){
	scanf("%d", &n);
	memset(ing,-1,sizeof(ing));
	memset(p,-1,sizeof(p));
	memset(mrk,-1,sizeof(mrk));
	for(int a=0;a<n;a++){
		scanf("%d", &ni[a]);
		for(int b=0;b<ni[a];b++){
			scanf("%d", &ing[b]);
			if(mrk[ing[b]]==-1) continue;
			else{
				if(p[mrk[ing[b]]] != a){
					p[mrk[ing[b]]] = a;
					cntp[mrk[ing[b]]]=1;
				}
				else
					cntp[mrk[ing[b]]]++;
			}
		}
		int ver = 1;
		for(int b=0;b<ni[a];b++){
			//	printf("%d && (%d %d || %d %d)\n", mrk[ing[b]], cntp[mrk[ing[b]]],  ni[mrk[ing[b]]], p[mrk[ing[b]]], a);
			if(mrk[ing[b]] != -1 && (cntp[mrk[ing[b]]] != ni[mrk[ing[b]]] || p[mrk[ing[b]]] != a)){
				ver=0;
				break;
			}
		}
		if(ver){
			for(int b=0;b<ni[a];b++){
				mrk[ing[b]] = a;
			}
			res++;
		}
	}
	printf("%d\n", res);
}