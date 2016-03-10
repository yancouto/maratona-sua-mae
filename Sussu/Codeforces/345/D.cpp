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
	
const int MAXN = 500010;

int n, A, B, t;

char s[MAXN];

int main (){
	scanf("%d%d%d%d", &n, &A, &B, &t);

	for(int a=0;a<n;a++){
		scanf(" %c", &s[a]);
	}
	int ans = 0;

	int res = 0;
	int i=n-1, f=0, cus = 0;

	while(f < n){
		int nxtc = 1;
		if(s[f] == 'w')
			nxtc += B;
		if(f*A + cus + nxtc <= t){
			cus += nxtc;
			f++;
			res++;
			ans = max(res, ans);
			//printf("pega %d %d - res = %d cus %d\n", f, i, res, cus);
		}
		else
			break;
	}
	if(f == n){
		printf("%d\n", n);
		return 0;
	}
	while(f > 0){
		while(1){
			int nxtc = 1;
			if(s[i] == 'w')
				nxtc += B;
			//printf("ve se %d %d %d %d + %d <= %d ?\n", cus, nxtc, (f-1)*A,  (n-i)*A, min((f-1)*A, (n-i)*A), t);
			if(cus + nxtc + (f-1)*A + (n-i)*A + min((f-1)*A, (n-i)*A)  <= t){
				cus += nxtc;
				i--;
				res++;
				ans = max(res, ans);
				//printf("1 pega %d %d - res = %d cus %d\n", f, i, res, cus);
			}
			else
				break;
		}
		cus--;
		if(s[f-1] == 'w'){
			cus -= B;
		}
		f--;
		res--;
		//printf("2 pega %d %d - res = %d cus %d\n", f, i, res, cus);
	}

	printf("%d\n", ans);
}