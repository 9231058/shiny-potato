#include <iostream>

using namespace std;

const int MAX=100+10;
const int INF=1000*1000*1000;
int D[MAX][MAX];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		D[v1-1][v2-1]=w;
		D[v2-1][v1-1]=w;
	}
	for(int i=0;i<n;i++){
		D[i][i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(D[i][j]==0&&i!=j){
				D[i][j]=INF;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(D[i][j]!=INF)
				cout<<"distance "<<i+1<<" to "<<j+1<<" = "<<D[i][j]<<" ";
			else
				cout<<"distande "<<i+1<<" to "<<j+1<<" = "<<"INF"<<" ";
		}
		cout<<endl;
	}
}
