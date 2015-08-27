#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXC = 110;

int n, mrk[30], deg[30], imp, fil[MAXC], deg2[30];

char nom[MAXC][MAXC];

vector <int> adj[30];

inline void veri(int i,int j){
	int tam = strlen(nom[i]);
	int tam2 = strlen(nom[j]);
	for(int a=0;a<tam;a++){
		if(a==tam2){
			imp=1; //pal iguais só que a segunda é menor
			return;
		}
		if(nom[i][a]!=nom[j][a]){
			adj[nom[i][a]-'a'].push_back(nom[j][a]-'a');
			deg[nom[j][a]-'a']++;
			deg2[nom[j][a]-'a']++;
			return;
		}
	}
}

int main (){
	scanf("%d", &n);
	imp=0;
	for(int a=0;a<n;a++){
		scanf(" %s", nom[a]);
		veri(a-1,a);
	}
	int degf=0, degi=0;
	for(int a=0;a<26;a++){
		if(deg[a]==0)
			fil[degf++]=a;
	}
	
	while(degi!=degf){
		int v = fil[degi++];
		for(int a=0;a<adj[v].size();a++){
			int nxt = adj[v][a];
			deg[nxt]--;
			if(deg[nxt]==0){
				fil[degf++]=nxt;
			}
		}
	}
	
	for(int a=0;a<26;a++){
		if(deg[a]!=0){
			imp=1;
		}
	}
	
	if(imp==1)
		printf("Impossible\n");
	else{
		degf=degi=0;
		for(int a=0;a<26;a++){
			if(deg2[a]==0){
				fil[degf++]=a;
				printf("%c", a+'a');
			}
		}
		while(degi!=degf){
			int v = fil[degi++];
			for(int a=0;a<adj[v].size();a++){
				int nxt = adj[v][a];
				deg2[nxt]--;
				if(deg2[nxt]==0){
					fil[degf++]=nxt;
					printf("%c", nxt+'a');
				}
			}
		}
		printf("\n");
	}
	return 0;
}

/*
3
rivest
shamir
adleman

10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooo
subscriber
rowdark
tankengineer

10
petr
egor
endagorion
feferivan
ilovetanyaromanova
kostka
dmitriyh
maratsnowbear
bredorjaguarturnik
cgyforever

7
car
care
careful
carefully
becarefuldontforgetsomething
otherwiseyouwillbehacked
goodluck

3
ab
ac
cd

2
asc
as

26
aarhrhaahrhar
b
c
d
e
farehahearehhr
g
h
iewtawetgaaa
j
k
l
m
n
oahrrahararrh
pawhrehawr
q
r
s
t
ughstharehar
v
wasghhgfdsghdsrthyehaej
x
y
z

*/
