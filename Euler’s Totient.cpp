#include <iostream>

using namespace std;

const long long MAX=1000*1000;

int fi(long long n){
	int result=n; 
       	for(int i=2;i*i<=n;i++){ 
        	if (n%i==0)
			result-=result/i; 
         	while(n%i==0) 
			n/=i; 
       	} 
       	if(n>1) 
		result-=result/n; 
       	return result; 
}
int main(){
	long long n;
	cin>>n;
	cout<<fi(n)<<endl;
}
