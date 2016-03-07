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
	int i=n-1, f=0, cus = -A;

	while(f < n){
		int nxtc = A + 1;
		if(s[f] == 'w')
			nxtc += B;
		if(cus + nxtc <= t){
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
	int cusv = f*A;
	while(f > 0){
		while(1){
			int nxtc = 1;
			if(s[i] == 'w')
				nxtc += B;
			if(cus + nxtc + cusv <= t){
				cus += nxtc;
				i--;
				res++;
				cusv += A;
				ans = max(res, ans);
				//printf("pega %d %d - res = %d cus %d cusv %d\n", f, i, res, cus, cusv);
			}
			else
				break;
		}
		//printf("pega %d %d - res = %d cus %d cusv %d\n", f, i, res, cus, cusv);
		cus -= A + 1;
		if(s[f-1] == 'w'){
			cus -= B;
		}
		cusv -= A;
		f--;
		res--;
	}

	printf("%d\n", ans);
}