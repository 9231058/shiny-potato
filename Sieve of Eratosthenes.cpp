#include <iostream>

using namespace std;

const int MAX=1000;
bool prime[MAX];

void prime_gen(int n){
	for(int i=2;i<=n;i++)
		prime[i]=true;
	for(int i=2;i*i<=n;i++)
		if(prime[i])
			for(int j=2;i*j<=n;j++)
				prime[i*j]=false;
	for(int i=2;i<=n;i++)
		if(prime[i])
			cout<<i<<" ";
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	prime_gen(n);
}
