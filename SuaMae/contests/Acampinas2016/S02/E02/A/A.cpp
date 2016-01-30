
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

int n;
char dia[110], s[110][110];

int M[5][5], ult[5][5], tam[5][5];

int num(){
	if(dia[1] == 'u')
		return 0;
	else if(dia[1] == 'h')
		return 1;
	return 2;
}

void comp(int t){
	if(t < 0) t = 0;
	while(t < 10){
		printf(" ");
		t++;
	}
}

int vaiate(int a,int b){
	int d = 10 + ult[a][b];
	if(d >= tam[a][b]) return tam[a][b];
	while(d){
		if(s[M[a][b]][d] == ' ' || s[M[a][b]][d] == '\n')
			break;
		d--;
	}
	return d;
}

void dez(){
	for(int a=0;a<10;a++){
		printf("-");
	}
}

void printl(){
	printf("+");
	dez();
	printf("+");
	dez();
	printf("+");
	dez();
	printf("+\n");
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf(" ");
		fgets(s[a], sizeof(s[a]), stdin);

		scanf(" %s %d", dia, &t);
		M[t-1][num()] = a;
		tam[t-1][num()] = strlen(s[a])-1;		
	}
	printl();
	for(int a=0;a<4;a++){
		printf("|");
		int foi = 1;
		for(int b=0;b<3;b++){
			if(s[M[a][b]][ult[a][b]] == ' ') ult[a][b]++;
			int ini = ult[a][b], vai = vaiate(a,b);
			//printf("ini %d tam %d*", ini, tam[a][b]);
			for(int c = ult[a][b]; c < min(vai, tam[a][b]);c++){
				ult[a][b] = c+1;
				printf("%c", s[M[a][b]][c]);
			}
			comp(min(vai,tam[a][b]) - ini);
			printf("|");
			if(min(vai,tam[a][b]) - ini != 0 && ult[a][b] < tam[a][b]){
				//printf("n foi pq %d %d\n", a, b); 
				foi = 0;
			}
		}
		if(!foi){
			a--;
			printf("\n");
		}
		else{
			printf("\n");
			printl();
		}
	}
}
