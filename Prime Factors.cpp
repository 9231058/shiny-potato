#include <iostream>

using namespace std;

void prime_factors(int n){
	if(n<0){
		cout<<"-1 * ";
		n*=-1;
	}
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			cout<<i<<" * ";
			n/=i;
		}
	}
	if(n>1)
		cout<<n<<" ";
	cout<<endl;
}
int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<n<<" = ";
		prime_factors(n);
	}
}
