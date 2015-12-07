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

const int MAXN = 2000010;

int n;

int s[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++)
		s[a] = a;


	for(int a=2;a<=n;a++){
		int ant = 0, b;
		for(b=a-1;b <= n+a-1;b+=a){
			//printf("swap s[%d]:%d , %d\n", b, s[b], ant);
			swap(s[b],ant);
		}
		b-=a;
		b++;
		if(b<=n+a-1){
			swap(ant,s[n+a-1]);
		}
	

	}
	for(int a=n;a<=2*n-1;a++){
		printf("%d ", s[a]);
	}
	printf("\n");
}