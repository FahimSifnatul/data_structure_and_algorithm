#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *left,*right;
    node()
    {
        left=NULL;
        right=NULL;
    }
}*root=NULL;

void insert(int temp)
{
    if(root==NULL)
    {
        root=new node();
        root->roll=temp;
    }
    else
    {
        node *temp_node=root,*parent;
        while(temp_node!=NULL)
        {
            if(temp<temp_node->roll)
            {
                parent=temp_node;
             temp_node=temp_node->left;
            }
            else if(temp>temp_node->roll)
            {
                 parent=temp_node;
             temp_node=temp_node->right;
            }
            else
                break;
        }
        node *new_node=new node();
                new_node->roll=temp;
        if(new_node->roll<parent->roll)parent->left=new_node;
        else parent->right=new_node;
    }
}

int bst_print(node *current)
{
 if(current==NULL)return 0;
 cout<<current->roll<<endl;
 bst_print(current->left);
 bst_print(current->right);
}

int main()
{
  int n,temp;
  cout<<"total roll numbers: ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
      cin>>temp;
      insert(temp);
  }
  bst_print(root);
  return 0;
}











