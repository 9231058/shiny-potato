#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct edge{
	int weight;
	int start;
	int end;
};

const int MAX=1000*100;
edge E[MAX];
int color[MAX];

int edge_cmp(const void* a,const void* b){
	edge* A=(edge*)a;
	edge* B=(edge*)b;
	return A->weight-B->weight;
}
int find(int x){
	if(color[x]<0){
		return x;
	}
	return color[x]=find(color[x]);
}
bool merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		color[x]=color[x]+color[y];
		color[y]=x;
		return true;
	}
	return false;
}

int main(){
	int n;
	int m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		color[i]=-1;
	}
	for(int i=0;i<m;i++){
		int V1,V2,W;
		cin>>V1>>V2>>W;
		E[i].start=V1;
		E[i].end=V2;
		E[i].weight=W;
	}
	qsort(E,m,sizeof(edge),edge_cmp);
	int min_weight=0;
	for(int i=0;i<m;i++){
		if(merge(E[i].start,E[i].end)){
			
			min_weight+=E[i].weight;
		}
	}
	cout<<min_weight<<endl;
}
