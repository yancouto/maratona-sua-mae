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

int s[20], n, j;


inline void sum(){
	int carr = 1;
	for(int a=0;;a++){
		if(s[a] == 1)
			s[a] = 0;
		else{
			s[a] = 1;
			break;
		}
	}
}

inline bool test(int b){
	int num = 0, p = 1;
	for(int a=0;a<n;a++){
		num += s[a]*p;
		p *= b;
	}
	for(int a=2;a<=sqrt(num);a++){
		if(num%a == 0){
			return true;
		}
	}
	return false;
}

inline int div(int b){
	int num = 0, p = 1;
	for(int a=0;a<n;a++){
		num += s[a]*p;
		p *= b;
	}
	for(int a=2;a<=sqrt(num);a++){
		if(num%a == 0){
			return a;
		}
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d %d", &n, &j);
		printf("Case #%d:\n", tt);
		memset(s, 0, sizeof(s));
		s[n-1] = 1;
		while(s[n] == 0 && j){
			int fodeu = 0;
			for(int b=2;b<11;b++){
				if(!test(b)){
					fodeu = 1;
					break;
				}
			}
			if(!fodeu){
				for(int a=n-1;a>=0;a--){
					printf("%d", s[a]);
				}
				for(int b=2;b<11;b++)
					printf(" %d", div(b));
				printf("\n");
				j--;
			}
			sum();
		}
	}
}