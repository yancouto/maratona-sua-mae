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

const int MAXC=210;

int n, mrk[MAXC][MAXC][4];

int vi[]={0,0,1,-1};
int vj[]={-1,1,0,0};

char s[MAXC*MAXC*MAXC], M[MAXC][MAXC];

int let(char t){
	if(t == '>')
		return 1;
	if(t=='<')
		return 0;
	if(t=='^')
		return 3;
	return 2;
}

bool valid(int i,int j){
	return (i>=0 && j>=0 && i<n && j<n && M[i][j] != '#');
}


int main (){
	scanf("%d", &n);
	scanf(" %s", s);
	int tam = strlen(s);
	int cnt = 1, ult = tam;
	while(cnt<=n*n+1){
		for(int a=0;a<tam;a++){
			s[ult] = s[a];
			ult++;
		}
		cnt++;
	}
	tam *= n*n +1;
	//for(int a=0;a<tam;a++){
	//	printf("%c ", s[a]);
	//}
	//printf("\n");
	int inii, inij;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b]=='R'){
				inii = a;
				inij = b;
				M[a][b]='.';
			}
		}
	}
	int i = inii, j = inij, a=0;
	//printf("comeca %d %d\n", i, j);
	while(a<tam){
		if(valid(i+vi[let(s[a])],j+vj[let(s[a])])){
			//printf("conta %d %d -> %d %d mov %c %d\n", i, j, i+vi[let(s[a])], j+vj[let(s[a])], s[a], let(s[a]));
			i += vi[let(s[a])];
			j += vj[let(s[a])];
		}
		a++;
	}
	a=0;
	int res =  0;
	//printf("comeca %d %d\n", i, j);
	while(a<tam){
		if(valid(i+vi[let(s[a])],j+vj[let(s[a])]) && mrk[i+vi[let(s[a])]][j+vj[let(s[a])]][let(s[a])] == 0){
			//printf("conta %d %d -> %d %d mov %c %d\n", i, j, i+vi[let(s[a])], j+vj[let(s[a])], s[a], let(s[a]));
			mrk[i+vi[let(s[a])]][j+vj[let(s[a])]][let(s[a])] = 1;
			res++;
			i += vi[let(s[a])];
			j += vj[let(s[a])];
		}
		else if(mrk[i+vi[let(s[a])]][j+vj[let(s[a])]][let(s[a])] == 1)
			break;
		a++;
	}

	printf("%d\n", res + (res==0));
}