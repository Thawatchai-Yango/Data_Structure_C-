#include<iostream>
#include<string>
using namespace std;

class Pinacle_node
{
    int prn;
    string name;
    Pinacle_node *next;
    
public:
    	Pinacle_node(int x,string nm)
	{
	
    	prn=x;
    	next=NULL;
    	name=nm;
    }
   
friend class Pinacle_list;    	
};

class Pinacle_list
{
	int no;
	int prev_no;
	string name;
	Pinacle_node *start;
public:
	Pinacle_list(){
		start=NULL;
	}

	void create();
	void display();
	void insertPresident();
	void insertSecretary();
	void insertAfterMember();
	void deletePresident();
	void deleteSecretary();
	void deleteMember();
	int computeTotal();
	void sortList();
	void concat(Pinacle_list &q1);
	void displayRev(Pinacle_node *t);
		bool reverseDisplay() 
         {
        	 if(start==NULL)
        		return false;
        	 Pinacle_node *temp=start;
        	 displayRev(temp);
        	 return true;
         }
};

void Pinacle_list::create()
{
 	if(start==NULL)
	{
		cout<<">>>\nEnter PRN.number of member::\n";
		cin>>no;
		cout<<">>>Enter the name of member::\n";
		cin>>name;
		cout<<name;
		start=new Pinacle_node(no,name);
		cout<<"\n============ List Created ==============";
		
	}
	else
	{
		cout<<"\n=======List is already created.========";
	}
}

void Pinacle_list::display()
{
	Pinacle_node *t;
	t=start;
	if(start==NULL)
		cout<<"\n======List is Empty========";
	else
	{   cout<<"\n========= List: ======+====\n";
		while(t!=NULL)
		{
			cout<<t->prn<<"  "<<t->name<<" \n";
					t=t->next;
		}
		
	}
}

void Pinacle_list::insertPresident()
{
	Pinacle_node *temp;
 	if(start==NULL)
 	{
	 create();
 	}
 	else
 	{
	 cout<<"\n>>>Enter PRN number of President::\n";
	 cin>>no;
	 cout<<">>>Enter the name of President::\n";
	 cin>>name;
	 temp=new Pinacle_node(no,name);
	 temp->next=start;
	 start=temp;;
	 cout<<"Inserted  "<<temp->name<<" as the President.";
 	}
}

void Pinacle_list::insertSecretary()
{
	Pinacle_node *t;
	if(start==NULL)
		create();
	else
	{
	 cout<<"\n>>>Enter PRN number of Secretary::\n";
	 cin>>no;
	 cout<<">>>Enter the name of Secretary::\n";
	 cin>>name;
	 t=start;
	 while(t->next!=NULL)
	 	t=t->next;
	 	
	 	Pinacle_node*p=new Pinacle_node(no,name);
	 	t->next=p;
	}
}

void Pinacle_list::insertAfterMember()
{
	
	cout<<"\n>>>Enter PRN No which you want insert after::\n";
	cin>>prev_no;
	Pinacle_node *t;
	t=start;
	int flag=0,no;
	while(t!=NULL)
	{
		if(t->prn==prev_no)
		{
			flag=1;break;
		}
		t=t->next;
	}
	if(flag==1)
	{
	Pinacle_node *p;
	cout<<"\n>>>Enter PRN. number of Member::\n" ;
	 cin>>no;
	 cout<<">>>Enter the name of Member::\n" ;
	 cin>>name;
	 p=new Pinacle_node(no,name);
	 p->next=t->next;
	 t->next=p;
	}
	else
	{
		cout<<"\n"<<prev_no<<" is not in list.";
	}
	
}
 void Pinacle_list::deletePresident()
 {
 	Pinacle_node *t;
	if(start==NULL)
		cout<<"\nClub is Empty..";
	else
	{
	t=start;
	start=start->next;
	t->next=NULL; //Not necessary
	delete t;
	cout<<"\nPresident deleted..";
	}
}

void Pinacle_list::deleteSecretary()
{
	Pinacle_node *t,*prev;
	t=start;
	if(start==NULL)
	cout<<"\nClub is Empty..";
	else
	{
	while(t->next!=NULL)
	{
		prev=t;
		t=t->next;
	}
	prev->next=NULL;
	delete t;
	cout<<"\nSecretary deleted.";
}
}

void Pinacle_list::deleteMember()
{
	int no,flag=0;
	Pinacle_node *t,*prev;
	if(start==NULL)
		cout<<"\nList/Club is empty;";
	else
	{
		cout<<"\n>>>Enter PRN no. of member to be deleted: ";
		cin>>no;
		t=start->next;
		while(t->next!=NULL)
		{
			if(t->prn==no){
				flag=1;
				break;
			}
			prev=t;
			t=t->next;
		}
		if(flag==1)
		{
			prev->next=t->next;
			t->next=NULL;
			delete t;
			cout<<"\nMember with PRN number: "<<no<<" is deleted.";
		}
		else
			cout<<"\nMember not found in List./president or secretary cannot be deleted.";
	}
}

int Pinacle_list::computeTotal()
{
	Pinacle_node *t;
	int count=0;
	t=start;
	if(start==NULL)
	{
	cout<<"\nList is empty.";
	return 0;
}
	while(t!=NULL)
{
	count++;
	t=t->next;
}
return count;
}

void Pinacle_list::sortList()
{
	Pinacle_node *i,*j,*last=NULL;
	int tprn;
	string tname;

	if(start==NULL)
	{
	cout<<"\nList is empty.";
	return ;
	}
	for(i=start;i->next!=NULL;i=i->next)
	{
	for(j=start;j->next!=last;j=j->next)
	{
		if((j->prn)>(j->next->prn))
		{
			tprn=j->prn;
			tname=j->name;
			j->prn=j->next->prn;
			j->name=j->next->name;

			j->next->prn=tprn;
			j->next->name=tname;

		}
	}
}
cout<<"\n List is sorted.";
display();
}

void Pinacle_list::concat(Pinacle_list &q1)

{
	Pinacle_node *t,*p;
	t=q1.start;
	if(t==NULL)
	{
		cout<<"\nList 2 is empty";
		return;
	}
	p=start; //first list
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=t;
	q1.start=NULL; //second list is set to  null
	cout<<"\nAfter concatenationlist";
	display();
	
}
 void Pinacle_list:: displayRev(Pinacle_node *t)
 {
	if(t==NULL)
		return;
	else
	{
		displayRev(t->next);
		cout<<"\nPRN NO:"<<t->prn<<" Name: "<<t->name;
	}
}


int main ()
{
	Pinacle_list *l;
	int choice,selectList;
	Pinacle_list l1,l2;
	l=&l1;
	X:cout<<"\nSelect Division of Computer Engineering\n  1.Division A\n  2.Division B\nEnter the  choice: ";
	cin>>selectList;

	if(selectList==1)
	{
		l=&l1;
		cout<<"\n **************************************";
		cout<<"\n       DATA MEMBERS IN DIVISION A";
	}
	else if(selectList==2)
	{
		l=&l2;
		cout<<"\n **************************************";
		cout<<"\n       DATA MEMBERS IN DIVISION B";
	}
	else
	{
		cout<<"\n***Wrong list Number***\n";
		goto X;
	}
	do
	{
		cout<<"\n\t 1.create\n\t 2.Display members\n\t 3.Insert President\n\t 4.insest Secretary\n\t 5.Insert member"
		<<"\n\t 6.Delete President\n\t 7.Delete Secretary\n\t 8.Delete Member\n\t 9.Total No. of members\n\t 10.Sort list\n\t 11.Reverse Display of Members"
		<<"\n\t 12.Combine two Divisions \n\t 13.Reselect List\n\t 0. Exit\n\n Enter your choice::";
		cin>>choice;

		switch(choice)
		{
			case 1: l->create();
				break;
			case 2:	l->display();
				break;
			case 3: l->insertPresident();
				break;
			case 4: l->insertSecretary();
				break;
			case 5: l->insertAfterMember();
				break;
			case 6: l->deletePresident();
				break;
			case 7: l->deleteSecretary();
				break;
			case 8: l->deleteMember();
				break;
			case 9:	cout<<"\nTotal members(including President & Secretary): "<<l->computeTotal();
				break;
			case 10: l->sortList();
				break;
			case 11: l->reverseDisplay();
				break;
			case 12: l1.concat(l2);
				break;
			case 13:goto X;	
				break;
			deafult:
				cout<<"Wrong choice";
		}
	}while(choice!=0);
cout<<"\nProgram closed\n";
 	return 0;
 }
