#include <stdio.h>
#include <stdlib.h>
/*** Binary Search Tree :  My Favorite Data-Structure ***/
struct  Node;
typedef long long int ll;
struct Node{
ll data;
struct Node *Left,*Right;
};
struct Node* Find(ll Value,struct Node *T)
{
    if(T==0)
        return 0;
    else if(Value<T->data)
        return Find(Value,T->Left);
    else if(Value>T->data)
        return Find(Value,T->Right);
    else return T ;
}
struct Node* MakeEmpty(struct Node *T)
{
	if(T!=0)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return 0;
}
struct Node* Insert(ll Value,struct Node *T)
{
	if(T==0)
	{
		T = (struct Node*)malloc(sizeof(struct Node));
		T->data = Value;
		T->Left = 0;
		T->Right = 0;
		printf("Insertion Done: %lld\n",T->data);
	}
	else if(Value< (T->data))
		T->Left = Insert(Value,T->Left);
	else if(Value> T->data) T->Right = Insert(Value,T->Right);
	else ;
	return T;
}
struct Node* FindMin(struct Node *T)
{
	if(T!=0)
	{
		while(T->Left !=0)T = T->Left;
	}
	return T;

}
struct Node* FindMax(struct Node *T)
{
	if(T!=0)
		while((T->Right)!=0)T = T->Right;
	return T;
}
struct Node* Delete(ll Value,struct Node *T)
{
	struct Node* temp;
	if(T==0);
	else if(Value<T->data)
		T->Left = Delete(Value,T->Left);
	else if(Value>T->data)
		T->Right = Delete(Value,T->Right);
	else if(T->Right!=0&&T->Left!=0)
	{
		temp = FindMin(T->Right);
		T->data = temp->data;
		T->Right = Delete(T->data,T->Right);
	}
	else
	{
		temp =T;
		if(T->Right==0)
			T = T->Left;
		else if(T->Left==0)
			T = T->Right;
		free(temp);
	}
	return T;
}
int main()
{
	struct Node *T;
	T = MakeEmpty(0);
	T = Insert(1,T);
	T = Insert(2,T);
	T = Insert(-3,T);

	printf("%lld %lld\n",(FindMin(T))->data,(FindMax(T))->data);
	T = Delete(1,T);
	T = Insert(4134,T);
	printf("%lld %lld\n",FindMin(T)->data,FindMax(T)->data);
}
