#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class bigInt{
	private:
		vector <int> N;
	public:
		friend bool operator ==(bigInt A,bigInt B){
			if(A.size()!=B.size())
				return false;
			int i=0;
			while(A[i]==B[i]&&i<A.size())
				i++;
			if(i==A.size())
				return true;
			return false;
		}
		friend bigInt square(bigInt A){
			return A*A;
		}
		friend bigInt operator ^(bigInt A,int n){
			if(n==0)
				return bigInt(1);
			if(n%2==0)
				return square(A^(n/2));
			else
				return A*(A^(n-1));
		}
		friend bigInt operator *(bigInt A,int n){
			bigInt C;
			for(int i=0;i<n;i++)
				C+=A;
			return C;
		}
		friend bigInt operator *(bigInt A,bigInt B){
			bigInt C(0);
			for(int i=0;i<B.size();i++)
				C+=(A*B[i]).push_back(i,0);
			return C;
		}
		friend bigInt operator +(bigInt A,bigInt B){
			vector <int> C;
			if(A.size()==1&&A[0]==0){
				return B;
			}
			else if(B.size()==0&&B[0]==0){
				return A;
			}
			if(A.size()>=B.size()){
				int div=0;
				for(int i=0;i<B.size();i++){
					C.push_back((A[i]+B[i]+div)%10);
					div=((A[i]+B[i]+div)/10);
				}
				for(int i=B.size();i<A.size();i++){
					C.push_back((A[i]+div)%10);
					div=((A[i]+div)/10);
				}
				if(div!=0)
					C.push_back(div);
			}
			else{
				int div=0;
				for(int i=0;i<A.size();i++){
					C.push_back((A[i]+B[i]+div)%10);
					div=((A[i]+B[i]+div)/10);
				}
				for(int i=A.size();i<B.size();i++){
					C.push_back((B[i]+div)%10);
					div=((B[i]+div)/10);
				}
				if(div!=0)
					C.push_back(div);
			}
			return bigInt(C);
		}
		bigInt(string S){
			for(int i=S.size()-1;i>=0;i--){
				N.push_back((static_cast <int> (S[i]))-48);
			}
		}
		bigInt(vector <int> V){
			for(int i=0;i<V.size();i++){
				N.push_back(V[i]);
			}
		}
		bigInt(){
			N.push_back(0);
		}
		bigInt(int n){
			while(n!=0){
				N.push_back(n%10);
				n=n/10;
			}
		}
		void show(){
			for(int i=N.size()-1;i>=0;i--){
				cout<<N[i];
			}
			cout<<endl;
		}
	 	friend ostream &operator <<(ostream &output,bigInt T){
			for(int i=T.size()-1;i>=0;i--){
				output<<T[i];
			}
			return output;
		}
		int size(){
			return N.size();
		}
		bigInt push_back(int n,int m){
			if(N.size()==1&&N[0]==0)
				return *this;
			for(int i=0;i<n;i++){
				N.insert(N.begin(),m);
			}
			return *this;
		}
		int &operator [](int n){
			return N[n];
		}
		bigInt operator =(bigInt T){
			N.erase(N.begin(),N.end());
			for(int i=0;i<T.size();i++){
				N.push_back(T[i]);
			}
			return *this;
		}
		bigInt operator =(int n){
			bigInt temp(n);
			*this=temp;
			return temp;
		}
		bigInt operator +=(bigInt T){
			*this=*this+T;
			return *this;
		}
};

string a;
string b;

int main(){
	cin>>a>>b;
	bigInt A(a);
	bigInt B(b);
	bigInt C=A^2;
	C.show();
}
