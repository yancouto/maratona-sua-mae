#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2509, MAXD = 110, MAXL = 50010;

int n, m, ind[MAXD][MAXD], degi, degl, pai[MAXN], h[MAXN], res, mrk[MAXN], degr=0, cone[MAXN][MAXN];

char M[MAXD][MAXD];

vector <int> adj[MAXN];

struct liga{
	int a, b, c;
} lis[MAXL];

bool cmp(liga i,liga j){
	return i.c<j.c;
}

int raiz(int v){
	if(pai[v]==v) return v;
	return pai[v] = raiz(pai[v]);
}

void join(int i,int j){
	if(h[i]<h[j])
		pai[i]=j;
	else if(h[i]>h[j])
		pai[j]=i;
	else{
		pai[j]=i;
		h[i]++;
	}
}

void dfs(int v){
	mrk[v]=1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]==0)
			dfs(nxt);
	}
}

int main (){
	while(1){
		scanf("%d%d",  &n, &m);
		if(n==0 && m==0) break;
		for(int a=0;a<=n+1;a++){
			for(int b=0;b<=m+1;b++){
				M[a][b]='.';
			}
		}
			
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				scanf(" %c", &M[a][b]);
			}
		}
		degl=0;
		degi=1;
		liga sup, inf;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				if(M[a][b]=='#'){
					ind[a][b]=degi++;
				}
				else 
					ind[a][b]=0;
			}
		}
		for(int a=0;a<=degi;a++){
			for(int b=0;b<=degi;b++){
				if(a==0 || b==0 || a==degi || b==degi)
					cone[a][b]=1;
				else
					cone[a][b]=0;
			}
		}
		for(int a=1;a<=n;a++){
			sup.a=sup.b=inf.a=inf.b=-1;
			for(int b=1;b<=m;b++){
				if(M[a-1][b]=='#'){
					if(sup.b!=-1 && cone[ind[sup.a][sup.b]][ind[a-1][b]]==0){
						cone[ind[sup.a][sup.b]][ind[a-1][b]]=1;
						lis[degl].a = ind[sup.a][sup.b];
						lis[degl].b = ind[a-1][b];
						lis[degl++].c = b-sup.b-1;
					}
					sup.a=a-1;
					sup.b=b;
				}
				if(M[a+1][b]=='#'){
					if(inf.b!=-1 && cone[ind[inf.a][inf.b]][ind[a+1][b]]==0){
						cone[ind[inf.a][inf.b]][ind[a+1][b]]=1;
						lis[degl].a = ind[inf.a][inf.b];
						lis[degl].b = ind[a+1][b];
						lis[degl++].c = b-inf.b-1;
					}
					inf.a=a+1;
					inf.b=b;
				}
				if(M[a][b]=='#'){
					if(sup.b!=-1 && cone[ind[sup.a][sup.b]][ind[a][b]]==0){
						cone[ind[sup.a][sup.b]][ind[a][b]]=1;
						lis[degl].a = ind[sup.a][sup.b];
						lis[degl].b = ind[a][b];
						lis[degl++].c = b-sup.b-1;
					}
					sup.a=a;
					sup.b=b;
					if(inf.b!=-1 && cone[ind[inf.a][inf.b]][ind[a][b]]==0){
						cone[ind[inf.a][inf.b]][ind[a][b]]=1;
						lis[degl].a = ind[inf.a][inf.b];
						lis[degl].b = ind[a][b];
						lis[degl++].c = b-inf.b-1;
					}
					inf.a=a;
					inf.b=b;
				}
			}
		}
	
		liga dir, esq;
		for(int b=1;b<=m;b++){	
			dir.a=dir.b=esq.a=esq.b=-1;
			for(int a=1;a<=n;a++){
				if(M[a][b-1]=='#'){
					if(esq.a!=-1 && cone[ind[esq.a][esq.b]][ind[a][b-1]]==0){
						cone[ind[esq.a][esq.b]][ind[a][b-1]]=1;
						lis[degl].a = ind[esq.a][esq.b];
						lis[degl].b = ind[a][b-1];
						lis[degl++].c = a-esq.a-1;
					}
					esq.a=a;
					esq.b=b-1;
				}
				if(M[a][b+1]=='#'){
					if(dir.a!=-1 && cone[ind[dir.a][dir.b]][ind[a][b+1]]==0){
						cone[ind[dir.a][dir.b]][ind[a][b+1]]=1;
						lis[degl].a = ind[dir.a][dir.b];
						lis[degl].b = ind[a][b+1];
						lis[degl++].c = a-dir.a-1;
					}
					dir.a=a;
					dir.b=b+1;
				}
				if(M[a][b]=='#'){
					if(esq.a!=-1 && cone[ind[esq.a][esq.b]][ind[a][b]]==0){
						cone[ind[esq.a][esq.b]][ind[a][b]]=1;
						lis[degl].a = ind[esq.a][esq.b];
						lis[degl].b = ind[a][b];
						lis[degl++].c = a-esq.a-1;
					}
					esq.a=a;
					esq.b=b;
					if(dir.a!=-1 && cone[ind[dir.a][dir.b]][ind[a][b]]==0){
						cone[ind[dir.a][dir.b]][ind[a][b]]=1;
						lis[degl].a = ind[dir.a][dir.b];
						lis[degl].b = ind[a][b];
						lis[degl++].c = a-dir.a-1;
					}
					dir.a=a;
					dir.b=b;
				}
			}
		}

		for(int a=0;a<=degi;a++){
			pai[a]=a;
			h[a]=0;
			mrk[a]=0;
			adj[a].clear();
		}
		//kruskal
		sort(&lis[0],&lis[degl],cmp);
		int nb=0;
		res=0;
		for(int a=0;a<degl;a++){
			int i = lis[a].a, j = lis[a].b, c = lis[a].c;
			raiz(i);raiz(j);
			if(pai[i]!=pai[j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
				join(pai[i],pai[j]);
				if(c!=0 && c!=-1) nb++; 
				res+=c;
				if(c==-1) res++; 
			}
		}
		int dis=0;
		for(int a=1;a<degi;a++){
			if(mrk[a]==0){
				dis++;
				dfs(a);
			}
		}
		printf("City %d\n", ++degr);
		if(nb==0 && dis==1)
			printf("No bridges are needed.\n");
		else if(nb==0 && dis>1){
			printf("No bridges are possible.\n");
			printf("%d disconnected groups\n", dis);
		}
		else{
			printf("%d bridges of total length %d\n", nb, res);
			if(dis>1)
				printf("%d disconnected groups\n", dis);
		}
		printf("\n");
	}
	return 0;
}


/*

*/
