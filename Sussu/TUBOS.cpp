#include <cstdio>
#include <cstring>
#include <algorithm>

#include <vector>
using namespace std;

const int MAXN = 1010;

int n, m, low[MAXN], ind[MAXN], degi, res;

vector <int> adj[MAXN];

void go(int v,int pai){
	low[v]=ind[v]=degi++;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt==pai)continue;
		if(ind[nxt]==0){
			go(nxt,v);
			low[v]=min(low[v],low[nxt]);
			if(low[nxt]>ind[v]){
				res=1;
				return ;
			}
		}
		else{
			low[v]=min(low[v],ind[nxt]);
		}
	}
}

int main (){
	while(scanf("%d%d", &n, &m) && n+m!=0){
		res=degi=0;
		for(int a=0;a<=n;a++){
			adj[a].clear();
			ind[a]=low[a]=0;
		}
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d%d", &i, &j);
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		go(1,0);
		if(res==0)
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
	
}
