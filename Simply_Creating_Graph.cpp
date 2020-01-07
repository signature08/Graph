#include <iostream>
using namespace std;
struct node
{
	char info;
	node *l1,*l2;
};
class Graph
{
	private:
		node *A,*B,*C,*D,*E,*AE1,*AE2,*AE3,*BE1,*DE1,*DE2,*EE1;
		node *temp,*ptr;
	public:
		Graph()
		{
			A=new node();
			B=new node();
			C=new node();
			D=new node();
			E=new node();
			AE1=new node();
			AE2=new node();
			AE3=new node();
			BE1=new node();
			DE1=new node();
			DE2=new node();
			EE1=new node();
			/*                        A ------------> D \             
			                          |               |   \ 
									  |	              |     \      									  |               |       
									  |               |      > E
									  |				  |	    /
									  /               /   /
 								      B ------------> C</              */
			A->l1=B;
			A->l2=AE1;
			A->info='A';
			AE1->l1=B;
			AE1->l2=AE2;
			AE2->l1=C;
			AE2->l2=AE3;
			AE3->l1=D;
			AE3->l2=NULL;
			B->info='B';
			B->l1=C;
			B->l2=BE1;
			BE1->l1=C;
			BE1->l2=NULL;
			C->info='C';
			C->l1=D;
			C->l2=NULL;
			D->info='D';
			D->l1=E;
			D->l2=DE1;
			DE1->l1=C;
			DE1->l2=DE2;
			DE2->l1=E;
			DE2->l2=NULL;
			E->info='E';
			E->l1=NULL;
			E->l2=EE1;
			EE1->l1=D;
			EE1->l2=NULL;
			temp=A;
		}
		void show()
		{
			while(temp!=NULL)
			{
				cout<<"Node name is : "<<temp->info<<endl;
				cout<<"Edges of "<<temp->info<<" Are: \n";
				ptr=temp->l2;
				if(temp->l2==NULL)
				{
					cout<<"NO Edges\n";
				}
				while(ptr!=NULL)
				{
					cout<<ptr->l1->info<<endl;
					ptr=ptr->l2;
				}
				temp=temp->l1;
			}
		}
};
int main()
{
	Graph G;
	G.show();
	return 0;
}
