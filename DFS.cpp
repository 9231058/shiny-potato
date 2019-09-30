#include <iostream>
#include <vector>

using namespace std;

struct vertex{
	int color;
	int parent;
	int distance;
};

const int MAX=1000*100+10;
vector <int> E[MAX];
struct vertex V[MAX];

void DFS(int start);

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		E[v1].push_back(v2);
		E[v2].push_back(v1);
	}
	int start;
	cin>>start;
	V[start].distance=0;
	DFS(start);
	int end;
	cin>>end;
	cout<<V[end].distance<<endl;
}
void DFS(int start){
	V[start].color=1;
	for(int i=0;i<E[start].size();i++){
		if(V[E[start][i]].color==0){
			V[E[start][i]].parent=start;
			V[E[start][i]].distance=V[start].distance+1;
			DFS(E[start][i]);
		}
	}
	V[start].color=2;
}

