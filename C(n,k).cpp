#include <iostream>

using namespace std;

const int MAX=1000;
int C[MAX];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n+1;i++){
		int temp1=1;
		for(int j=0;j<=k;j++){
			if(j==0){
				C[j]=1;
				continue;
			}
			if(j==i){
				C[j]=1;
				break;
			}
			int temp2=C[j];
			C[j]+=temp1;
			temp1=temp2;
		}
	}
	cout<<C[k]<<endl;
}
