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

const int MAXN = 100010;

int n, k;
int s[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int i, j, res=-1;
	int nn = n;
	res = s[n-1];
	while(nn < k*2){
		k--;
		nn--;
	}
	i=0;
	j=nn-1;
	//printf("jota %d\n", j);
	while(i<j){
		res = max(res,s[i]+s[j]);
		i++;
		j--;
	}
	if(i==j){
		res = max(res,s[i]);

	}
	printf("%d\n", res);

}