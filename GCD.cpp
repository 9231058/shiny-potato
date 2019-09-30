#include <iostream>

using namespace std;

class triple{
	public:
		int d,x,y;
		triple(int d,int x,int y){
			this->d=d;
			this->x=x;
			this->y=y;
		}
		friend ostream &operator<<(ostream &output,triple T){
			output<<T.d<<" "<<T.x<<" "<<T.y;
			return output;
		}
};

triple gcd(int a,int b){
	if(b==0)
		return triple (a,1,0);
	else{
		triple temp1=gcd(b,a%b);
		triple temp2(temp1.d,temp1.y,temp1.x-(a/b)*temp1.y);
		return temp2;
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
}
