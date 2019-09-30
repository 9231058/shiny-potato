#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vertex{
	int color;
	int parent;
	int distance;
};

const int MAX=1000*100;
vector <int> E[MAX];
queue <int> Q;
struct vertex V[MAX];

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
	int end;
	cin>>end;
	Q.push(start);
	while(Q.size()!=0){
		int temp;
		temp=Q.back();
		Q.pop();
		V[temp].color=1;
		for(int i=0;i<E[temp].size();i++){
			if(V[E[temp][i]].color==0){
				Q.push(E[temp][i]);
				V[E[temp][i]].parent=temp;
				V[E[temp][i]].distance=V[temp].distance+1;
			}
		}
		V[temp].color=2;
	}
	cout<<V[end].distance<<endl;
}



