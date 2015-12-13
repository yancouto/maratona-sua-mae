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


const int MAXN = 110;

int n, res, ult;

struct mini{
	int i, j;
} m[MAXN];


bool cmp(mini a, mini b){
	return (a.j<b.j || (a.j==b.j && a.i<b.i));
}

int main (){
	scanf("%d", &n);
	ult = -1;
	res = 0;
	for(int a=0;a<n;a++){
		scanf("%d%d", &m[a].i, &m[a].j);
	}
	sort(m,m+n,cmp);
	for(int a=0;a<n;a++){
		if(m[a].i> ult){
			res++;
			ult = m[a].j;
		}
	}
	printf("%d\n", res);
	return 0;
}