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

int n, mrk[MAXN], res[MAXN], p[MAXN];

int main (){
	scanf("%d", &n);
	if(n==1){
		printf("1");
		return 0;
	}
	else if(n%4==2 || n%4==3){
		printf("-1");
		return 0;
	}
	else{
		int i=1, f=n;
		while(i<=f){
			if(i==f){
				res[i] = i;
				i++;
			}
			else{
				res[f-1] = i;
				res[i+1] = f;
				res[i] = i+1;
				res[f] = f-1;
				i+=2;
				f-=2;
			}
		}
	}
	for(int a=1;a<=n;a++)
		printf("%d ", res[a]);
	return 0;
}