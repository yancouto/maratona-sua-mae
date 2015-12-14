#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20, MAXV = (1<<16);

int t, n, k, fo[MAXV], res[MAXV], degr;

struct arv{
	int p, g, fg;
} tree[MAXV*4];

inline int abs(int v){
	if(v<0)return -v;
	return v;
}

arv cmp(arv a, arv b){
	arv ans;
	if(a.fg>=b.fg){
		ans.g=a.g;
		ans.p=b.g;
	}
	else{
		ans.g=b.g;
		ans.p=a.g;
	}
	ans.fg=min(fo[ans.g],k+abs(a.fg-b.fg));
	return ans;
}
	
	
void pres(int idx,int i,int f){
	if(i==f) return;
	res[degr++]=tree[idx].p;
	int g = tree[idx].g;
	int m = (i+f)/2;
	if(g<=m)
		pres(idx*2,i,m);
	else
		pres(idx*2+1,m+1,f);
}	

void build(int idx,int i,int f){
	if(i==f){
		tree[idx].g=i;
		tree[idx].fg=fo[i];
		return ;
	}
	int m =(i+f)/2;
	build(idx*2,i, m);
	build(idx*2+1,m+1,f);
	tree[idx]=cmp(tree[idx*2],tree[idx*2+1]);
	//printf("%d %d %d %d %d %d\n", idx, i, f, tree[idx].g, tree[idx].p, tree[idx].fg);
}

	


int main (){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		degr=0;
		scanf("%d%d", &n, &k);
		for(int a=1;a<=(1<<n);a++){
			scanf("%d", &fo[a]);
		}
		build(1,1,(1<<n));
		printf("%d\n", tree[1].g);
		pres(1,1,(1<<n));
		for(int a=degr-1;a>=0;a--){
			if(a==0)
				printf("%d\n", res[a]);
			else
				printf("%d ", res[a]);
		}
	}
	return 0;		
}


