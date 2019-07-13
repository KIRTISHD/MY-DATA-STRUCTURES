#include<iostream>
#include "tre.h"

using namespace std;

Treez::Treez(){
	root=NULL;
}
/*
void Treez::display(){
	
}

*/
void Treez::insert(struct student **node,int element) {
	if (*node==NULL) {
		//cout<<"AALA RE"<<endl;
		struct student *temp;
		temp= new student;
		temp->rollno=element;
		temp->lchild=NULL;
		temp->rchild=NULL;
		*node = temp;
		//cout<<"GELA RE"<<endl;
	}
	else{
		if ((*node)->rollno > element) {
			insert(&((*node)->lchild),element);
		}
		else {
		    insert(&((*node)->rchild),element);
		}
	}
}

void Treez::inorder(struct student *node){
	if (node!=NULL){
		inorder(node->lchild);
		cout<<node->rollno<<"->";
		inorder(node->rchild);
	}
}

void Treez::preorder(struct student *node){
	if (node!=NULL){
		cout<<node->rollno<<"->";
		preorder(node->lchild);
		preorder(node->rchild);
	}
}


void Treez::postorder(struct student *node){
	if (node!=NULL){
		postorder(node->lchild);
		postorder(node->rchild);
		cout<<node->rollno<<"->";
	}
}

void Treez::deleteAll(struct student *node){
	if (node!=NULL){
	    deleteAll(node->lchild);
	    deleteAll(node->rchild);
	    delete node;
	}
}


struct student *Treez::search(struct student *node, int s){
    if (node==NULL){    
        //cout<<"Not Found"<<endl; 
        return node;   
    }
  //  cout<<"Mai kaha"<<node->rollno<<endl;
    if (node->rollno == s) {
        //cout<<"found - "<<s<<endl;
        //cout<<"Tu kaha"<<node->rollno<<endl;
        return node;
    }
	if (node->rollno > s) {
		search((node->lchild),s);
	}
	else {
	    search((node->rchild),s);
	}
}
/*
void Treez::deleteNode(struct student **root , int d)
{

    if (*root == NULL){
        cout<<"Number nahi aahe re"<<endl;
        return;
    }
    struct student* father = *root;
    struct student* node = *root;
    cout<<"Process Chalu"<<endl;
    
    struct student* father = node;
        while (node->rollno != d)
        {
            if (node == NULL)
            {
                //cout<<"Number not found in list"<<endl;
                cout<<"Nahi aahe re tree madhe, dusra zhad shodh"<<endl;
                return;
            }
            father = node;
            if (node->rollno < d)
            {
                node = node->rchild;
            }
            else if (node->rollno > d)
            {
                node = node->lchild;
            }
        }
        cout<<"bhetla re, aata mara yala-"<<node->rollno<<endl;
        cout<<"tyacha baap kon?-"<<father->rollno<<endl;

        //case 1: if node has no children
	   if (node->lchild == NULL && node->rchild == NULL)
	   {
            if (father->rollno == node->rollno) {
                node = NULL;
		        free(node);
                return;
            }
			if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = NULL;
			}
		   else {
			   father->rchild = NULL;
		   }
		node = NULL;
		free(node);
	   }

       //case 2: if node has 1 child
        if (node-> lchild == NULL && node->rchild != NULL){
            if (father->lchild != NULL && father->lchild->rollno == d) {
				father->rchild = node->lchild;
			}
		   else {
			   father->rchild = node->rchild;
		   }
		    node = NULL;
		    free(node);
        }
        else if (node-> rchild == NULL && node->lchild != NULL){
            if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = node->lchild;
			}
		   else {
			   father->lchild = node->rchild;
		   }
		    node = NULL;
		    free(node);
        }

        //case 3: if node has 2 children
        

}
*/
struct student *findMin(struct student *node) {
	if (node->lchild == NULL || node->rchild == NULL){
		return node;
	}
	while(node->lchild->lchild != NULL){
		node = node->lchild;
	}
	return node;
}


void Treez::deleteNode(struct student **root , int d)
{

    if (*root == NULL){
        cout<<"Number nahi aahe re"<<endl;
        return;
    }
    struct student* father = *root;
    struct student* node = *root;
    cout<<"Process Chalu"<<endl;
        while (node->rollno != d)
        {
            if (node == NULL)
            {
                //cout<<"Number not found in list"<<endl;
                cout<<"Nahi aahe re tree madhe, dusra zhad shodh"<<endl;
                return;
            }
            father = node;
            if (node->rollno < d)
            {
                node = node->rchild;
            }
            else if (node->rollno > d)
            {
                node = node->lchild;
            }
        }
        cout<<"bhetla re, aata mara yala-"<<node->rollno<<endl;
        cout<<"tyacha baap kon?-"<<father->rollno<<endl;

        //case 1: if node has no children
	   if (node->lchild == NULL && node->rchild == NULL)
	   {
            if (father->rollno == node->rollno) {
            	*root = NULL;
                free(*root);
                return;
            }
			if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = NULL;
			}
		   else {
			   father->rchild = NULL;
		   }
		node = NULL;
		free(node);
		return;
	   }

       //case 2: if node has 1 child
        if (node-> lchild == NULL && node->rchild != NULL){

        	if (node->rollno == father->rollno){
        		father = *root;
        		*root = node->rchild;
        		father = NULL;
        		//cout<<"Mai aaya"<<endl;
        		free(father);
        		return;
        	}

            if (father->lchild != NULL && father->lchild->rollno == d) {
				father->rchild = node->lchild;
			}
		   else {
			   father->rchild = node->rchild;
		   }
            //cout<<"aaya..."<<endl;
		    node = NULL;
		    free(node);
		    //cout<<"aaja...."<<endl;
		    return;
        }
        else if (node-> rchild == NULL && node->lchild != NULL){

        	if (node->rollno == father->rollno){
				father = *root;
				*root = node->lchild;
				father = NULL;
				free(father);
				return;
			}

        	if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = node->lchild;
			}
		   else {
			   father->lchild = node->rchild;
		   }
		    node = NULL;
		    free(node);
		    return;
        }

        //case 3: if node has 2 children
        if (node->lchild != NULL && node->rchild != NULL)
        {
        	father = findMin(node);
        	//cout<<"ithe pohochalas, dil khus jhala"<<endl;
        	/*if (father->lchild == NULL && father->rchild == NULL){
        		node->rollno = father->rollno;
        		node->rchild = father->rchild;
        		father = NULL;
				free(father);
				return;
        	}
        	else if (node-> rchild == NULL && node->lchild != NULL) {

        	}*/
        	if (father->lchild == NULL){
        		node->rollno = father->rollno;
        		node->rchild = father->rchild;
        		father=NULL;
        		free(father);
        		return;
        	}
        	else{
        		if (father->lchild->rchild == NULL){
        			node->rollno = father->lchild->rollno;
        			struct student *temp = father->lchild;
        			father->lchild = NULL;
        			temp = NULL;
        			free(temp);
        			return;
        		}
        		else{
        			node->rollno = father->lchild->rollno;
        			struct student *temp = father->lchild;
        			father->lchild = temp->rchild;
        			temp = NULL;
        			free(temp);
        			return;
        		}
        	}
        }

// done dana dan............
}

/*
//Ha Nahi Chalat. Ha Dhavto
    void Treez::deleteNode(struct student *node, int d)
    {
        struct student* father = node;
        while (node->rollno != d)
        {
            if (node == NULL)
            {
                //cout<<"Number not found in list"<<endl;
                cout<<"Nahi aahe re tree madhe, dusra zhad shodh"<<endl;
                return;
            }
            father = node;
            if (node->rollno < d)
            {
                node = node->rchild;
            }
            else if (node->rollno > d)
            {
                node = node->lchild;
            }
        }
        cout<<"bhetla re, aata mara yala-"<<node->rollno<<endl;
        cout<<"tyacha baap kon?-"<<father->rollno<<endl;

        //case 1: if node has no children
	   if (node->lchild == NULL && node->rchild == NULL)
	   {
            if (father->rollno == node->rollno) {
                node = NULL;
		        free(node);
                return;
            }
			if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = NULL;
			}
		   else {
			   father->rchild = NULL;
		   }
		node = NULL;
		free(node);
	   }

       //case 2: if node has 1 child
        if (node-> lchild == NULL && node->rchild != NULL){
            if (father->lchild != NULL && father->lchild->rollno == d) {
				father->rchild = node->lchild;
			}
		   else {
			   father->rchild = node->rchild;
		   }
		    node = NULL;
		    free(node);
        }
        else if (node-> rchild == NULL && node->lchild != NULL){
            if (father->lchild != NULL && father->lchild->rollno == d) {
				father->lchild = node->lchild;
			}
		   else {
			   father->lchild = node->rchild;
		   }
		    node = NULL;
		    free(node);
        }

        //case 3: if node has 2 children

    }
*/

int Treez::maxdepth(struct student * node){
    if (node == NULL)
        return 0;
    else {
        int l = maxdepth(node->lchild);
        int r = maxdepth(node->rchild);

        if(l > r)
            return l+1;
        else 
            return r+1;
    }
}

int Treez::size(struct student * node){
    if (node==NULL){
        return 0;    
    }
    else{
        int l = size(node->lchild);
        int r = size(node->rchild);
        int tsize = l+1+r;
        return tsize;
    }
}
