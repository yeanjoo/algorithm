#include <iostream>
#define null 0
using namespace std;
template <typename T>
class Tree;
template <typename T>

class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
 //이부분
    friend ostream& operator<<(ostream& os, const TreeNode<T>& node) {
        os << "[data] " << node.data << endl;
        if (node.left != null) {
            os << "[left] " << node.left->data << endl;
        }
        if (node.right != null) {
            os << "[right] " << node.right->data << endl;
        }
        return os;
    } //-------------------
};

template <typename T>
class Tree {
	private:
		TreeNode <T> * root;//계속해서 저장할 노드 
	public:
		Tree(T data){
			root = new TreeNode<T>(data);	
		}
		void insert(T n){
			insertNode(new TreeNode<int>(n));
		}
		void insertNode(TreeNode<T> * child){
			//1. 맨 처음 루트 노드인지 확인한다
			//2. 중복이 있는지 확인한다. 
			//3. 임시 TreeNode로 자리를 잡는다 
			if(search(*root,child -> data)==null){
				TreeNode <T> * current=root;
				TreeNode <T> * parent = null;
				
				while(current=!null){
					parent = current;
					
					if(current->data > child->data){
						current = current -> left;
					}
					else current = current ->right;
				}
				
				if(parent->data> child->data){
					parent -> left = child; 
				}
				else{
					current -> right = child;
				}				
			}
			
		}
		
		/* 내가 쓴 와일 문 search 
		TreeNode <T> * search(TreeNode<T> * root,  T data){
			if(root == null) return null;
			while(root =!null){
				if(root -> data == node -> data) return * root;
				
				if(root->data < node->data){
					root=root -> right;
				}
				else root =root -> left;
			}
		}
		*/
		
		TreeNode<T>* search(TreeNode<T>* root, T data) {
	        if (root == null) return null;
	        if (data == root->data) {
	            return root;
	        }
	        else if (data < root->data) {
	            search(root->left, data);
	        }
	        else {
	            search(root->right, data);
	        }
		}
		void PreOrder(TreeNode<T> * node){
			if(node=!null){
				cout<<node->data;
				PreOrder(node->left);
				PreOrder(node->right);
		}
		}
		void InOrder(TreeNode<T> * node){
			if(node=!null){
				InOrder(node->left);
				cout<<node->data;
				InOrder(node->right);
			}
		}
		void PostOrder(TreeNode<T> * node){
			if(node=!null){
				PostOrder(node->left);
				PostOrder(node->right);
				cout<<node->data;
			}
		}
		
	
};

int main(void){
	int n;

	cout<<"넣을 숫자를 입력해 주세요";
	cin>>n;
	Tree <int> tree(n);//? 왜지? 일단 Tree <int> tree = new <int>Tree(n) 하니까 아닌가?///
	
	for(int i=0;i<10;i++){
		cin>>n;
		tree.insert(n);
	}
	
}