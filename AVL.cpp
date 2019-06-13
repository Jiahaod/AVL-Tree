#include <iostream>
#include <cstdlib>

using namespace std;
typedef int DataType;

struct AVL 
{
	DataType key;
	int Height;
	struct AVL * Left;
	struct AVL * Right;
	//struct AVL * Parent;
};

void Preorder(struct AVL * T);
void Inorder(struct AVL * T);
void Postorder(struct AVL * T);
//void LevelOrder(struct AVL * T);
int Max(int a, int b);
int Height(struct AVL *T);
struct AVL * SingleRotateWithLeft(struct AVL *T );
struct AVL * SingleRotateWithRight(struct AVL * T);
struct AVL * DoubleRotateWithLeft(struct AVL * T);
struct AVL * DoubleRotateWithRight(struct AVL * T);
struct AVL * Insert(struct AVL * T, DataType x);
struct AVL * s;
int main()
{
	s=Insert(s, 4);
	s=Insert(s, 3); 
	s=Insert(s, 1);
	s=Insert(s, 7);
	s=Insert(s, 6);
	s=Insert(s, 5);
	s=Insert(s, 16);
	cout << "It's the result of Preorder tree walk.\n";
	Preorder(s);
	cout << "It's the result of inorder tree walk.\n";
	Inorder(s);
	cout << "It's the result of Postorder tree walk.\n";
	Postorder(s);
	s=Insert(s, 15);
}

int Max(int a, int b)
{
	return a>b?a:b;
}

int Height(struct AVL * T)
{
	if(T==NULL)
	return  -1;
	else 
	return T->Height;
} 

struct AVL * Insert(struct AVL * T, DataType x)
{
	if(T==NULL)
	{
		T=(struct AVL *)malloc(sizeof(struct AVL *));
		T->key=x;
		T->Left=T->Right=NULL;
		T->Height=0;
		
	}
	else if(x<T->key)
	{
		T->Left=Insert(T->Left, x);
		if(Height(T->Left)-Height(T->Right)==2)
		{
			if(x<T->Left->key)
			T=SingleRotateWithRight(T);
			else 
			T=DoubleRotateWithLeft(T);
		}
	}
	else if(x>T->key)
	{
		T->Right = Insert(T->Right, x);
		if(Height(T->Right)-Height(T->Left)==2)
		{
			if(x>T->Right->key)
			{
				T=SingleRotateWithLeft(T);
			}
			else 
			{
				T=DoubleRotateWithRight(T);
			}
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right))+1;
	return T;
}
//ÓÒÐý 
struct AVL *SingleRotateWithRight(struct AVL * T)
{
	struct AVL * L = T->Left;
	T->Left = L->Right;
	L->Right = T;
	T->Height=Max(Height(T->Left), Height(T->Right))+1;
	L->Height=Max(Height(L->Left), Height(L->Right))+1;
	return L;
}
//Ë«Ðý×ª£¬ÏÈÓÒÐýÔÙ×óÐý 
struct AVL * DoubleRotateWithLeft(struct AVL * T)
{
	T->Left = SingleRotateWithLeft(T->Left);
	return SingleRotateWithRight(T);
}

//Ë«Ðý£¬ÏÈÓÒÐýºó×óÐý 
struct AVL * DoubleRotateWithRight(struct AVL * T)
{
	T->Right = SingleRotateWithRight(T->Right);
	return SingleRotateWithLeft(T);
}

//µ¥×óÐý 
struct AVL * SingleRotateWithLeft(struct AVL *T )
{
	struct AVL * R= T->Right;
	T->Right = R->Left;
	R->Left = T;
	T->Height=Max(Height(T->Left), Height(T->Right))+1;
	R->Height = Max(Height(R->Left),Height(R->Right))+1;
	return R; 
}

void Preorder(struct AVL * T)
{
	if(T)
	{
		cout << T->key << endl;
		Preorder(T->Left);
		Preorder(T->Right); 
	}
}

void Inorder(struct AVL * T)
{
	if(T)
	{
		Inorder(T->Left);
		cout << T->key << endl;
		Inorder(T->Right);
	}
}

void Postorder(struct AVL * T)
{
	if(T)
	{
		Postorder(T->Left);
		Postorder(T->Right);
		cout << T->key << endl;
	}
}




