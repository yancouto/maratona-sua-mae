
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

const int MAXC = 1010, MAXN = 110;

int p[20];



inline void linha(){
	printf("+");
	for(int a=0;a<30;a++)
		printf("-");
	printf("+");
	for(int a=0;a<8;a++){
		printf("-");
	}
	printf("+");
	for(int a=0;a<13;a++)
		printf("-");
	printf("+\n");
}

inline void completa(int i,int j){
	for(;i<j;i++){
		printf(" ");
	}
}

int main(){
	linha();
	printf("|Contest name");
	for(int a=0;a<18;a++)
		printf(" ");
	printf("|Date    |ABCDEFGHIJKLM|\n");
	linha();
	for_tests(t,tt){
		char cont[MAXC], date[MAXC], ver[MAXC];
		scanf("\n");
		memset(p,-1,sizeof(p));
		fgets(cont, sizeof (cont), stdin);
		fgets(date, sizeof(date), stdin);
		//printf("%s e %s\n", cont, date);
		int tam = strlen(cont);
		cont[tam-1]='\0';
		tam = strlen(date);
		date[tam-1]='\0';
		int np, m;
		scanf("%d %d", &np, &m);
		for(int a=0;a<m;a++){
			char prob;
			scanf(" %c", &prob);
			scanf(" ");
			fgets(ver,sizeof(ver),stdin);
			if(strncmp(ver,"Accepted", 8)==0){
				p[prob-'A']=2;
			}
			else{
				if(p[prob-'A'] != 2)
					p[prob-'A']=1;
			}
		}
		printf("|%s", cont);
		tam = strlen(cont);
		completa(tam,30);
		printf("|%s|", date);
		for(int a=0;a<np;a++){
			if(p[a]==2)
				printf("o");
			else if(p[a]==1)
				printf("x");
			else
				printf(".");
		}
		completa(np,13);
		printf("|\n");
		linha();
	}
	return 0;
}
