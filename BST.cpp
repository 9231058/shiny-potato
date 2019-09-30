#include <iostream>

using namespace std;

struct node{
	int key;
	node* left;
	node* right;
	node* parent;
};
class Tree{
	private:
		struct node* root;
		int num;
	public:
		Tree(){
			root=new struct node;
			root -> left=NULL;
			root -> right=NULL;
			num=0;
		}
		void insert(int k){			
			struct node* temp2=new struct node;
			temp2 -> key=k;
			temp2 -> left=NULL;
			temp2 -> right=NULL;
			temp2 -> parent=NULL;
			if(num==0){
				root=temp2;
				num++;
				return;
			}
			struct node* temp1=root;
			while(true){
				if(temp1 -> key<k){
					if(temp1 -> left){
						temp1=temp1 -> left;
					}
					else{
						temp1 -> left=temp2;
						temp2 -> parent=temp1;
						num++;
						return;
					}
				}
				else{
					if(temp1 -> right){
						temp1=temp1 -> right;
					}
					else{
						temp1 -> right=temp2;
						temp2 -> parent=temp1;
						num++;
						return;
					}
				}
			}
		}
		void preorder(struct node* start){
			cout<<start -> key<<endl;
			if(start -> left){
				cout<<"Left :";
				preorder(start -> left);
			}
			if(start -> right){
				cout<<"Right :";
				preorder(start -> right);
			}
		}
		void display(){
			preorder(root);
		}
		int size(){
			return num;
		}
		struct node* find(struct node* start,int k){
			if(start -> key==k)
				return start;
			struct node* tempL;
			if(start -> left)
				tempL=find(start -> left,k);
			else
				tempL=NULL;
			struct node* tempR;
			if(start -> right)
				tempR=find(start -> right,k);
			else
				tempR=NULL;
			return tempR==NULL?tempL:tempR;
		}
		struct node* find(int k){
			return find(root,k);
		}
		/*void remove(int k){
			struct node* temp1=find(k);
			if(temp1==root){
				root
			struct node* temp2=temp1 -> parent;
			if(temp1 -> key<temp2 -> key){
				temp2 -> left=temp1 -> left;
				(temp1 -> left) -> parent=temp2;
				(temp1 -> right) -> parent=temp1 -> left;
				num--;
			}
			else{
				temp2 -> right=temp1 -> right;
				(temp1 -> right) -> parent=temp2;
				(temp1 -> left) -> parent=temp1 -> right;
				num--;
			}
		}*/
};

int n;

int main(){
	cin>>n;
	Tree A;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		A.insert(x);
	}
	A.display();
	int y;
	cin>>y;
	cout<<A.find(y) -> key<<endl;
}
