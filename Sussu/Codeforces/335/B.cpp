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

const int MAXN = 100010, MAXC = 100010, INF = 0x3f3f3f3f;

int n, m, x, y, res, mrk[510][510], tam;
char s[MAXC];

bool valid(int i,int j){
	return (i>0 && j>0 && i<=n && j<=m);
}

int carx(char c){
	if(c=='U')
		return -1;
	if(c=='D')
		return 1;
	return 0;
}

int cary(char c){
	if(c=='L')
		return -1;
	if(c=='R')
		return 1;
	return 0;
}

int ult= 0;

void go(int x, int y, int i){
	while(i<tam-1){
		//printf("\n%d %d\n", x, y);
		if(mrk[x][y]==0){
			mrk[x][y]=1;
			res++;
			ult = 1;
			printf("1 ");
		}
		else{
			ult = 0;
			printf("0 ");
		}
		i++;
		if(valid(x+carx(s[i]),y+cary(s[i]))){
			x = x+carx(s[i]);
			y = y+cary(s[i]);
		}
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &x, &y);
	scanf(" %s", s);
	tam = strlen(s);
	go(x,y,-1);
	printf("%d\n", n*m-res);
	return 0;
}