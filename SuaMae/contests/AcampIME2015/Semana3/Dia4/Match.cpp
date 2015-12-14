#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 110;

int n;
int c[10] = {6,2,5,5,4,5,6,3,7,6};

string dpmai[MAXN], dpmen[MAXN];

string cmp(string a,string b,char num){
	b+=num; //aumenta b.size em 1
	if(a.size()>b.size())
		return a;
	else if(b.size()>a.size())
		return b;
	else{
		if(a<b) //alfabeticamente
			return b;
		else
			return a;
	}
}

string cmp2(string a,string b,char num){
	b+=num; //aumenta b.size em 1
	if(a.size()>b.size())
		return b;
	else if(b.size()>a.size())
		return a;
	else{
		if(a<b) //alfabeticamente
			return a;
		else
			return b;
	}
}

string gomai(int v){
	if(dpmai[v]=="-1"){
		string aux = "";
		for(int a=0;a<10;a++){
			if(v-c[a]>=0 && v-c[a]!=1)
				aux=cmp(aux,gomai(v-c[a]),a+'0');
		}
		dpmai[v]=aux;
	}
	return dpmai[v];
}

string gomen(int v){
	if(dpmen[v]=="-1"){
		string aux = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
		for(int a=0;a<10;a++){
			if(a==0 && v==6) continue;
			if(v-c[a]>=0 && v-c[a]!=1)
				aux=cmp2(aux,gomen(v-c[a]),a+'0');
		}
		dpmen[v]=aux;
	}
	return dpmen[v];
}

int main (){
	for(int a=0;a<=MAXN-2;a++){
		dpmai[a]=dpmen[a]="-1";
	}
	dpmai[0]=dpmen[0]="";
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		gomai(n);gomen(n);
		cout << dpmen[n] << " " << dpmai[n] << "\n";
	}
	return 0;
}

