#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 10010, INF = 10005;

vector<int> adj[MAXN];

int n, m, q, mrk[MAXN], low[MAXN], ind[MAXN], pont[MAXN], degi, h[MAXN], res, pai[MAXN];

void go(int v,int p){
	if(v == INF){
		low[v]=h[v]=INF;
		mrk[v]=1;
		return;
	}
	pai[v]=p;
	pont[v]=0;
	h[v]=h[p]+1;
	mrk[v]=1;
	low[v]=h[v];
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]==0){
			go(nxt,v);
			low[v] = min(low[v],low[nxt]);
		}
		else{
			if(nxt != p){
				low[v] = min(low[v],low[nxt]); //nao faz diferença botar low ou h ja que o low de nxt sera h pra um cara acima de tu 
				adj[v][a]=INF;
			}
		}
	}
	if(v != 1 && low[v] >= h[v])
		pont[v] = 1;
}

int volta(int i,int j){
	int ver = 0;
	while(h[i]>h[j]){
		if(pont[i]) i = pai[i];
		else return 0;
	}
	while(h[j]>h[i]){
		if(pont[j]) j = pai[j];
		else return 0;
	}
	while(i!=j){
		if(pont[i] && pont[j]) i=pai[i], j=pai[j];
		else return 0;
	}
	return 1;
}

int main (){
	while(scanf("%d%d%d", &n, &m, &q) && n+m+q!=0){
		for(int a=0;a<=n;a++){
			adj[a].clear();
			pont[a]=mrk[a]=0;
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		h[0]=pont[1]=0;
		h[INF]=INF;
		mrk[INF]=1;
		go(1,0);
		for(int a=0;a<q;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			if(!volta(i,j))
				printf("N\n");
			else
				printf("Y\n");
		}
		printf("-\n");
	}
	return 0;
}