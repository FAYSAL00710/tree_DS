#include <iostream>

using namespace std;

struct TreeNode
 {

	 int data;
	TreeNode *LeftNode;
	TreeNode *RightNode;
};

TreeNode *makeTreeNode(int value)
{
   	TreeNode *newNode = new TreeNode;

      		newNode->data = value;
      		newNode->LeftNode = NULL;
      		newNode->RightNode = NULL;

   return newNode;
}

TreeNode *insert(TreeNode *nodePtr, int item)
{
   	if (nodePtr == NULL)
   	{
     		nodePtr = makeTreeNode(item);
   	}
   	else if (item < nodePtr->data)
   	{
     		nodePtr->LeftNode = insert(nodePtr->LeftNode, item);
   	}
   	else if (item > nodePtr->data)
   	{
    		nodePtr->RightNode = insert(nodePtr->RightNode, item);
   	}
   return nodePtr;
}

TreeNode *search(TreeNode *nodePtr, int target)
{
  	if (nodePtr != NULL)
  	{
   		 if (target < nodePtr->data)
    		{
      			nodePtr = search(nodePtr->LeftNode, target);
    		}
    		else if (target > nodePtr->data)
    		{
     			 nodePtr = search(nodePtr->RightNode, target);
    		}
 	 }
  	return nodePtr;
}

void inorder(TreeNode *ptr)
{
    if (ptr!=NULL)
    {
        inorder(ptr->LeftNode);
        cout << ptr->data<<",";
        inorder(ptr->RightNode);
    }
}


void postorder(TreeNode *ptr)
{
    if (ptr!=NULL)
    {
        postorder(ptr->LeftNode);
        postorder(ptr->RightNode);
        cout << ptr->data<<",";
    }
}

void preorder(TreeNode *ptr)
{
    if (ptr!=NULL)
     {
        cout << ptr->data << ",";
        preorder(ptr->LeftNode);
        preorder(ptr->RightNode);
    }
}

 int MaxDepth(TreeNode *ptr)
{
  if(ptr == NULL)
  return 0;

 else
{
 int lchild = MaxDepth(ptr->LeftNode);
 int rchild = MaxDepth(ptr->RightNode);

 if(lchild <= rchild)
 return rchild+1;

 else
  return lchild+1;

 }
}


int main()
{
    struct TreeNode *rootPtr=NULL;

    int n, item, i,a;
	cout<<"Enter number of nodes ";
   	cin>>n;

   	for (i = 0; i < n; i++)
		{
      		cin>>item;
      		rootPtr = insert(rootPtr, item);
   		}

 while(1)
 {
     cout<<endl;
     cout<<endl;
        cout<<"1:FOR INORDER"<<endl;
   		cout<<"2:FOR PREORDER"<<endl;
   		cout<<"3:FOR POSTORDER"<<endl;
   		cout<<"4:FOR SEARCH IN THE TREE"<<endl;
   		cout<<"5:FOR FIND DEPT OF THE TREE"<<endl;
   		cin>>a;
     switch(a)
     {
 case 1:
 {
     inorder(rootPtr);
 }
 break;
 case 2:
 {
     preorder(rootPtr);
 }
 break;

 case 3:
 {
     postorder(rootPtr);
 }

 break;

 case 4:
 {
    //inorder(rootPtr);
	cout<<"Enter target: ";
   	cin>>item;
   	TreeNode *ItemPtr = search(rootPtr, item);
   	if (ItemPtr == NULL)
   	{
   	    cout<<"Item was not found";

    }
   	else
   	 {
   	     cout<<"Item found\n";
   	 }

 }

 break;
 case 5:
 {
   cout<<MaxDepth(rootPtr);
 }
 break;


 default:
 {
     cout<<"Enter Correct Choose (1-4)"<<endl;
 }
 break;
 }

}
return 0;
}



