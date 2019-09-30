#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct vertex{
	int num;
	string name;
	int color;
};	

void DFS(int start);

const int MAX=1000+10;
vector <vertex> SV;
vertex V[MAX];
vector <int> E[MAX];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v1,v2;
		string s1,s2;
		cin>>v1>>v2;
		cin>>s1>>s2;
		V[v1].num=v1;
		V[v1].name=s1;
		V[v2].num=v2;
		V[v2].name=s2;
		E[v1].push_back(v2);
	}
	DFS(0);
	for(int i=1;i<SV.size();i++){
		cout<<SV[i].name<<" ";
	}
	cout<<endl;
}
void DFS(int start){
	V[start].color=1;
	for(int i=0;i<E[start].size();i++){
		if(V[E[start][i]].color==0){
			DFS(E[start][i]);
		}
	}
	V[start].color=2;
	SV.push_back(V[start]);
}
