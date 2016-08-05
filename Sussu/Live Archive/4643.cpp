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

const int MAXN = 134;

int n, m;

int s[MAXN];

map <int, int> ind;

void printb(int a){
	int cnt = 12;
	while(cnt != -1){
		if(a & (1<<cnt))
			printf("1");
		else
			printf("0");
		cnt--;
	}
	printf("\n");
}

bool test(int bm){
	ind.clear();
	for(int a=0;a<n;a++){
		/*if(a == n-1){
				printf("test: ");
			printb(bm);
			printf("com   ");
			printb(s[a]);
			printf("dando ");
			printb(s[a]&bm);
			printf("\n");
		}*/
		if(ind[s[a]&bm] == 1)
			return false;
		ind[s[a]&bm] = 1;
	}
	printf("deu com ");
	printb(bm);
	return true;
}


int main (){
	while(scanf("%d %d", &m, &n)!= EOF && n+m){
		for(int a=0;a<n;a++){
			s[a] = 0;
			for(int b=0;b<m;b++){
				char i;
				scanf(" %c", &i);
				int ii = i - '0';
				s[a] += ii*(1<<b);
			}
		}
		int res = INT_MAX;
		for(int a=0;a<=(1<<(m+1));a++){
			if(__builtin_popcount(a) > 5) continue;
			if(test(a)){
				printb(a);
				printf("deu com a %d - %d\n", __builtin_popcount(a), (a >= (1<<m)));
				res = min(res, __builtin_popcount(a));
			}
		}
		printf("%d\n", res);
	}
}
