#include<iostream>
#include "tre.h"

using namespace std;

int main(){
	Treez s1;
	struct student *root = NULL;
    struct student *lala=NULL;
	int choice;
	int no,pos;
	int loop=0;
	while (loop==0) {
		cout<<"Choice tak"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Inorder"<<endl;	
		cout<<"3. Preorder"<<endl;	
		cout<<"4. Postorder"<<endl;
		cout<<"5. Search item in tree"<<endl;
		cout<<"6. Delete item in tree"<<endl;
		cout<<"9. DeleteTree"<<endl;
		cout<<"10. Display"<<endl;
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Number tak"<<endl;
				cin>>no;
				s1.insert(&root, no);
				break;
			case 2:
				s1.inorder(root);
				cout<<endl;
				break;
			case 3:
				s1.preorder(root);
				cout<<endl;
				break;
			case 4:
				s1.postorder(root);
				cout<<endl;
				break;
			case 5:
				cout<<"Kunta number shodhto aahe?"<<endl;
				cin>>no;
				lala=s1.search(root,no);
                //cout<<"Ka nahi hot aahe?"<<endl;
                if (lala == NULL){
                    cout<<"Number nahi aahe re"<<endl;
                }
                else {
                    cout<<"found - "<<no<<endl;
                }
				cout<<endl;
				break;
			case 6:
				cout<<"Kunala tapkavaycha aahe?"<<endl;
				cin>>no;
				s1.deleteNode(&root,no);
                //s1.deleteNode(root,no);
				cout<<endl;
				break;
			case 9:
				s1.deleteAll(root);
				cout<<endl;
				break;
			/*case 3:
				cout<<"Number tak"<<endl;
				cin>>no;
				cout<<"Position tak"<<endl;
				cin>>pos;
				if(s1.insertAtPos(no,pos))
				{}
				break;
			case 5:
				if(s1.deleteAtEnd())
				{
					cout<<"lala"<<endl;
				}
				break;
			case 4:
				if(s1.deleteAtBeg())
				{
					cout<<"lala"<<endl;
				}
				break;
			case 6:
				cout<<"Position tak"<<endl;
				cin>>pos;
				if(s1.deleteAtPos(pos))
				{}
				break;
			case 10:
				s1.display();
				break;*/
			default:
				cout<<"choice baghun tak re"<<endl;	
				loop=1;
		}
	}
	return 0;
}
