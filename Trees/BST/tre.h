#ifndef xx
#define xx

using namespace std;

struct student {
	int rollno;
	struct student *lchild;
	struct student *rchild;
};

class Treez{
	private:
		struct student *root;
	public:
		Treez();
		void insert(struct student **, int );
		void inorder(struct student *);
		void preorder(struct student *);
		void postorder(struct student *);
		struct student *search(struct student *, int );
		void deleteNode(struct student **, int);
        void deleteNode(struct student *, int);
		void deleteAll(struct student *);
        int maxdepth(struct student *);
		int size(struct student *);
};

#endif
