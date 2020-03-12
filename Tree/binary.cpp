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
 //�̺κ�
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
		TreeNode <T> * root;//����ؼ� ������ ��� 
	public:
		Tree(T data){
			root = new TreeNode<T>(data);	
		}
		void insert(T n){
			insertNode(new TreeNode<int>(n));
		}
		void insertNode(TreeNode<T> * child){
			//1. �� ó�� ��Ʈ ������� Ȯ���Ѵ�
			//2. �ߺ��� �ִ��� Ȯ���Ѵ�. 
			//3. �ӽ� TreeNode�� �ڸ��� ��´� 
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
		
		/* ���� �� ���� �� search 
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

	cout<<"���� ���ڸ� �Է��� �ּ���";
	cin>>n;
	Tree <int> tree(n);//? ����? �ϴ� Tree <int> tree = new <int>Tree(n) �ϴϱ� �ƴѰ�?///
	
	for(int i=0;i<10;i++){
		cin>>n;
		tree.insert(n);
	}
	
}