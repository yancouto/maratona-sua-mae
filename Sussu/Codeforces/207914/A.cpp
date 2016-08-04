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

const int MAXN = 2123;

char s[MAXN];

int main (){
	scanf(" %s", s);
	int n = strlen(s);
	int i, j, cnt;
	i = n;
	j = -1;
	for(int a=0;a<n;a++){
		if(s[a] == '(')
			cnt++;
		else if(s[a] == ')')
			cnt--;
		else if(s[a] == '[')
			i = min(i, a);
		else
			j = max(j, a);
		if(cnt < 0 && i == n){
			puts("Impossible");
			return 0;
		}
	}
	cnt = 0;
	for(int a=n-1;a>j;a--){
		if(s[a] == '(')
			cnt--;
		else if(s[a] == ')')
			cnt++;
		if(cnt < 0){
			puts("Impossible");
			return 0;
		}
	}
	cnt = 0;
	for(int a=0;a<=n;a++){
		if(s[a] == '(')
			cnt++;
		else if(s[a] == ')')
			cnt--;
		cnt = max(0, cnt);
	}
	int rj = cnt;
	cnt = 0;
	for(int a=n-1;a>=0;a--){
		if(s[a] == ')')
			cnt++;
		else if(s[a] == '(')
			cnt--;
		cnt = max(0, cnt);
	}
	int ri = cnt;

	for(int a=0;a<n;a++){
		if(s[a] != ']' && s[a] != '[')
			printf("%c", s[a]);
		if(a == i){
			for(int b=0;b<ri;b++){
				printf("(");
			}
		}
		if(a == j){
			for(int b=0;b<rj;b++){
				printf(")");
			}
		}
	}
}
