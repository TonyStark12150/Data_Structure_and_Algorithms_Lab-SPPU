/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value 
*/
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

class BST
{
public:
    node* root;
    node*parent;

    BST()
    {
        root = NULL;
    }

    node* insert(node*& root, int ele)
    {
        if (root == NULL)
        {
            root = new node;
            root->data = ele;
            root->left = NULL;
            root->right = NULL;
        }
        else if (ele > root->data)
        {
            root->right = insert(root->right, ele);
        }
        else
        {
            root->left = insert(root->left, ele);
        }
        return root;
    }
    
    void delet(node*root,int ele)
    {
        while(root!=NULL)
        {
            if(ele>root->data)
            {
                parent=root;
                root=root->right;
            }
            else if(ele<root->data)
            {
                parent=root;
                root=root->left;
            }
            else if(ele==root->data)
            {
                if(root->left==NULL&&root->right==NULL)
                {
                    if(parent->left==root)
                    {
                        delete root;
                        parent->left=NULL;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        delete root;
                        parent->right=NULL;
                        return;
                    }
                }

                if(root->left==NULL)
                {
                    if(parent->left==root)
                    {
                        parent->left=root->right;
                        delete root;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        parent->right=root->right;
                        delete root;
                        return;
                    }
                }
                else if(root->right==NULL)
                {
                    if(parent->left==root)
                    {
                        parent->left=root->left;
                        delete root;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        parent->right=root->left;
                        delete root;
                        return;
                    }
                }
                else if(root->left!=NULL&&root->right!=NULL)
                {
                    node*n=min(root->right);
                    n->data=root->data;
                    delet(n,n->data);
                    return;
                }
            }
        }

    }
   node* min(node* root)
    {
        if (root->left != NULL)
        {
            return min(root->left);
        }
        return root;
    }


    int longest(node* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = longest(root->left);
        int rightHeight = longest(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void mirror(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        swap(root->left, root->right);
        mirror(root->left);
        cout<<root->data<<" ";
        mirror(root->right);
    }

    node* search(node* root, int ele)
    {
        if (root == NULL)
        {
            cout << "Element is not present." << endl;
            return NULL;
        }
        else if (root->data == ele)
        {
            cout << "Element is present." << endl;
            return root;
        }
        else if (ele > root->data)
        {
            return search(root->right, ele);
        }
        else
        {
            return search(root->left, ele);
        }
    }

    void display(node* root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
    }
};

int main()
{
    BST b;
    int ch,ele;

    do
    {
        cout<<"What do you want to do?"<<endl;
        cout<<"1.Insert node\n2.Delete node\n3.Display tree in ascending order\n4.Mirror tree\n5.Height of tree\n6.Least Value\n7.Search\n8.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter number to insert:"<<endl;
            cin>>ele;
            b.insert(b.root,ele);
            break;
        case 2:
            cout<<"Enter number to delete:"<<endl;
            cin>>ele;
            b.delet(b.root,ele);
            break;
        case 3:
            b.display(b.root);
            cout<<endl;
            break;
        case 4:
            b.mirror(b.root);
            cout<<endl;
            break;
        case 5:
            cout<<"Height of tree is : "<<b.longest(b.root)<<endl;
            break;
        case 6:
            node* min_val=b.min(b.root);
           if(min_val!=NULL)
           {
             cout<<"Minimum value in tree is: "<<min_val->data<<endl;
           }
           else{cout<<"Tree is empty"<<endl;}
            break;
        case 7:
            cout<<"Enter element to search:"<<endl;
            cin>>ele;
            b.search(b.root,ele);
            break;
        
        default:
            break;
        }
    } while (ch!=8);
    
    return 0;
}
