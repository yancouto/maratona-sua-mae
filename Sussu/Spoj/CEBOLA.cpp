#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;

int n, x[MAXN], y[MAXN], degp1=-1, degp2=-1, np, cnt, ind[MAXN];

struct node{
    int x,y;
} pil1[MAXN], pil2[MAXN];

inline bool cmp(int a,int b){
    if(x[a]!=x[b])
        return x[a]<x[b];
    return y[a]<y[b];
}

inline node sub(node a,node b){
    node res;
    res.x=a.x-b.x;
    res.y=a.y-b.y;
    return res;
}

int main (){
    while(1){
        //printf("1\n");
        scanf("%d", &n);
        if(n==0)break;
        np=n;
        cnt=0;
        degp1=degp2=-1;
        for(int a=0;a<n;a++){
            ind[a]=a;
            scanf("%d%d", &x[a], &y[a]);
        }
        cnt=0;
        sort(&ind[0],&ind[n],cmp);
        while(np>2){
            //printf("2\n");
            degp1=degp2=-1;
            for(int a=0;a<n;a++){
                    //printf("6\n");
                if(x[ind[a]]==MAXN && y[ind[a]]==MAXN)continue;
                pil1[++degp1].x=x[ind[a]];
                pil1[degp1].y=y[ind[a]];
                node v1,v2;
                int prod = -1;
                bool ver=0;
                degp1++;
                while(prod<0){
                    //printf("3\n");
                    if(ver==1)
                        swap(pil1[degp1],pil1[degp1-1]);
                    ver=1;
                    degp1--;
                    if(degp1>=2){  
                        int p1=degp1-2,p2=degp1-1,p3=degp1;
                        v1=sub(pil1[p1],pil1[p2]);
                        v2=sub(pil1[p3],pil1[p2]);
                    }
                    else
                        break;
                    prod = v1.x*v2.y - v1.y*v2.x;
                }
            }
            for(int a=n-1;a>=0;a--){
                    //printf("7\n");
                if(x[ind[a]]==MAXN && y[ind[a]]==MAXN)continue;
                pil2[++degp2].x=x[ind[a]];
                pil2[degp2].y=y[ind[a]];
                node v1,v2;
                int prod = -1;
                degp2++;
                bool ver=0;
                while(prod<0){
                    //printf("4\n");
                    if(ver==1){
                        swap(pil2[degp2],pil2[degp2-1]);
                    }
                    ver=1;
                    degp2--;
                    if(degp2>=2){
                        int p1=degp2-2,p2=degp2-1,p3=degp2;
                        v1=sub(pil2[p1],pil2[p2]);
                        v2=sub(pil2[p3],pil2[p2]);
                    }
                    else
                        break;
                    prod = v1.x*v2.y - v1.y*v2.x;
                }
            }   
            int b=0;
            for(int a=0;a<=degp1;a++){
                    //printf("9\n");
                for(;b<n;b++){
                   //printf("5\n");
                    if(pil1[a].x==x[ind[b]] && pil1[a].y==y[ind[b]]){
                        //printf("TIRA1 %d %d\n", x[ind[b]],y[ind[b]]); 
                        x[ind[b]]=y[ind[b]]=MAXN;
                        np--;
                        break;
                    }
                }
            }
            //printf("------------------------------\n");
            b=n-1;
            for(int a=1;a<degp2;a++){
                //printf("8\n");
                for(;b>=0;b--){
                    //printf("6\n");
                    if(pil2[a].x==x[ind[b]] && pil2[a].y==y[ind[b]]){
                        //printf("TIRA2 %d %d\n", x[ind[b]],y[ind[b]]);
                        x[ind[b]]=y[ind[b]]=MAXN; 
                        np--;
                        break;
                    }
                }
            }
            cnt++;
        }
        if(cnt%2==0)
            printf("Do not take this onion to the lab!\n");
        else
            printf("Take this onion to the lab!\n");
    }
    scanf("%*d");
    return 0;
}


