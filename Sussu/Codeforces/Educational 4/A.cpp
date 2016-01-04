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


int n, p, q;
int main (){
	scanf("%d%d%d", &n, &p, &q);
	int c1=0, c2=-1;
	if(n%p==0){
		c1 = n/p;
		c2 = 0;	
	} 
	else{
		while( c1*p < n ){
			if((n-c1*p)%q == 0){
				c2 = (n-c1*p)/q;
				break;
			}
			c1++;
		}
	}
	if(c2 == -1){
		scanf(" %*s");
		printf("-1\n");
	}
	else{
		printf("%d\n", c1 + c2);
		for(int a=0;a<c1;a++){
			for(int b=0;b<p;b++){
				char c;
				scanf(" %c", &c);
				printf("%c", c);
			}
			printf("\n");
		}
		for(int a=0;a<c2;a++){
			for(int b=0;b<q;b++){
				char c;
				scanf(" %c", &c);
				printf("%c", c);
			}
			printf("\n");
		}
		
	}
}