
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

const int MAXN = 2010;

int n, m, mrk[MAXN][MAXN], loser[MAXN][MAXN];

int qx, qo, qp, res[MAXN][MAXN];
char M[MAXN][MAXN], win;

int vi[] = {0,0,1,-1};
int vj[] = {1,-1,0,0};

bool valid(int i,int j){
	return (i>=1 && j>=1 && j<=n && i<=n && res[i][j] == 1 && mrk[i][j] == 0);
}

void go(int i,int j){
	mrk[i][j] = 1;
	for(int a=0;a<4;a++){
		if(valid(i+vi[a],j+vj[a]))
			go(i+vi[a],j+vj[a]);
	}
}

int main (){
	win = ' ';
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'X')
				qx++;
			else if(M[a][b] == 'O')
				qo++;
			else
				qp++;
		}
	}
	if(qo != qx && qo != qx-1){
		puts("ERROR");
		return 0;
	
	}
	for(int a=1;a<=n;a++){
		char gan = M[a][1], ja = ' ';
		int cnt = 1;
		for(int b=2;b <= n+1;b++){
			if(gan == '.') cnt = -1;
			if(M[a][b] != gan){
				if(cnt >= m){
					if(cnt >= 2*m || (ja != ' ' && ja != gan)){
						puts("ERROR");
						return 0;
					}
					for(int c=b-cnt;c<=b;c++){
						res[a][c]++;
						int dx = c - (b-cnt);
						if(dx < cnt-m || dx >= m){
							loser[a][c] = 1;
						}
						if(res[a][c] > 1 && loser[a][c]){
							puts("ERROR");
							return 0;
						}
					}	
					ja = gan;
				}
				cnt = 0;
				gan = M[a][b];
			}
			cnt++;
		}
		if(cnt >= m){
			if(ja != ' ' && ja != gan){
				puts("ERROR");
				return 0;
			}
			ja = gan;
		}
		if(ja != ' ' && ja != '.'){
			if(win != ' ' && win != ja){
				puts("ERROR");
				return 0;
			}
			win = ja;
			//printf("%c WINS\n", gan);
			//return 0;
		}
	}
	for(int b = 1;b<=n;b++){
		char gan = M[1][b], ja = ' ';
		int cnt = 1;
		for(int a=2;a<=n+1;a++){
			if(gan == '.') cnt = -1;
			if(M[a][b] != gan){
				if(cnt >= m){
					if(cnt >= 2*m || (ja != ' ' && ja != gan)){
						puts("ERROR");
						return 0;
					}
					for(int c=a-cnt;c<=a;c++){
						res[c][b]++;
						int dx = c - (a-cnt);
						if(dx < cnt-m || dx >= m){
							loser[c][b] = 1;
						}
						if(res[c][b] > 1 && loser[c][b]){
							puts("ERROR");
							return 0;
						}
					}
					ja = gan;
				}
				cnt = 0;
				gan = M[a][b];
			}
			cnt++;
		}
		if(cnt >= m){
			if(ja != ' ' && ja != gan){
				puts("ERROR");
				return 0;
			}
			ja = gan;
		}
		if(ja != ' ' && ja != '.'){
			if(win != ' ' && win != ja){
				puts("ERROR");
				return 0;
			}
			win = ja;
			//printf("%c WINS\n", gan);
			//return 0;
		}
	}
	for(int d=1-n;d<=n-1;d++){
		char gan = ' ', ganm, ja = ' ';
		int cnt = 0;
		for(int j = 1; j <= n && d+j <= n; j++){
			int i = d+j;
			if(i <= 0) continue;
			if(gan == '.') cnt = -1;
			if(M[i][j] != gan){
				if(cnt >= m){
					if(cnt >= 2*m || (ja != ' ' && ja != gan)){
						puts("ERROR");
						return 0;
					}
					for(int c = j-cnt;c <= j;c++){
						int ii = d+c;
						res[ii][c]++;
						int dx = c - (j-cnt);
						if(dx < cnt-m || dx >= m){
							loser[ii][c] = 1;
						}
						if(res[ii][c] > 1 && loser[ii][c]){
							puts("ERROR");
							return 0;
						}	
					}
					ja = gan;
				}
				cnt = 0;
				gan = M[i][j];
			}
			cnt++;
		}
		if(cnt >= m){
			if(cnt >= 2*m || (ja != ' ' && ja != gan)){
				puts("ERROR");
				return 0;
			}
			ja = gan;
		}
		if(ja != ' ' && ja != '.'){
			if(win != ' ' && win != ja){
				puts("ERROR");
				return 0;
			}
			win = ja;
		}
	}
	for(int d = 2; d <= n+n;d++){
		char gan= ' ', ja = ' ';
		int cnt  = 0;
		for(int j = 1;j<=n;j++){
			int i = d - j;
			if(i <= 0 || i > n) continue;
			if(gan == '.') cnt = -1;
			if(M[i][j] != gan){
				if(cnt >= m){
					if(cnt >= 2*m || (ja != ' ' && ja != gan)){
						puts("ERROR");
						return 0;
					}
					for(int c = j-cnt;c <= j;c++){
						int ii = d - c;
						res[ii][c]++;
						int dx = c - (j-cnt);
						if(dx < cnt - m || dx >= m)
							loser[ii][c] = 1;
						if(res[ii][c] > 1 && loser[ii][c]){
							puts("ERROR");
							return 0;
						}	
					}

					ja = gan;
				}
				cnt = 0;
				gan = M[i][j];
			}
			cnt++;
		}
		if(cnt >= m){
			if(ja != ' ' && ja != gan){
				puts("ERROR");
				return 0;
			}
			ja = gan;
		}
		if(ja != ' ' && ja != '.'){
			if(win != ' ' && win != ja){
				puts("ERROR");
				return 0;
			}
			win = ja;
		}
	}
	int foi = 0;
	for(int a=1;a<=n;a++){
		for(int b= 1;b<=n;b++){
			if(res[a][b] && !mrk[a][b]){
				if(foi){
					puts("ERROR");
					return 0;
				}
				foi = 1;
				go(a,b);
			}
		}
	}
	if(win == 'X'){
		if(qx == qo+1)
			printf("X WINS\n");
		else{
			puts("ERROR");
			return 0;
		}
	}
	else if(win == 'O'){
		if(qo == qx)
			printf("O WINS\n");
		else{
			puts("ERROR");
			return 0;
		}
	}
	else if(qp == 0)
		puts("DRAW");
	else
		puts("IN PROGRESS");

}
