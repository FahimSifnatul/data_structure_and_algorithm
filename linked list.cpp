/*bismillahir rahmanir rahim*/
//linked list; inserting and traversing;
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
}*root=nullptr;

int main()
{
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(root==nullptr)
        {
            root=new node;
            root->roll=temp;
            root->next=nullptr;
        }
        else
        {
            node *current_node=root;
            while(current_node->next!=nullptr)
            {
                current_node=current_node->next;
            }
            node *newnode=new node;
            newnode->roll=temp;
            newnode->next=nullptr;
            current_node->next=newnode;
        }
    }
       node *current_node=root;
       while(current_node->next!=nullptr)
       {
        cout<<current_node->roll<<' ';
        current_node=current_node->next;
       }
    cout<<current_node->roll;
    return 0;
}








