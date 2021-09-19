#include <iostream>
using namespace std;
// Structure to define node for dynamic mem allocation
struct node
{
    int data;
    node *prev,*next; // dll that's why two pointer.
};

// Structure for header node to store the metadata.
struct hnode
{
    int cnt;
    node *next; // next pointer to store the add of first node in list.
};

// define a  class  dll for various operations.
class dll
{
    hnode *head;    //data memebers.
    node *temp,*p;
public:
    dll()  //Default Constructor
    {
        head=NULL;
        temp=p=NULL;
    }
    //Member Functions...
    hnode *create(); //returns the head node address and create DLL.
    void show(hnode *); //To display DLL.
    hnode *merge_dll(hnode *,hnode *);//To merge both the List in Ascending order.

};//end of class dll


hnode * dll::create()
{
 int n;
 cout<<"\nHow many node u want to insert in DLL: ";
 cin>>n;
 if(n==0)
 {
  head=new hnode;
  head->next=NULL;
  head->cnt=0;
  return head;
 }
 while(n>0)
 {
     p= new node; //Allocation of memory for node
     cout<<"\nEnter Data of node: ";
     cin>>p->data;
     p->next=NULL;//initialization of node p
     p->prev=NULL;
     if(head==NULL) //Check for head node if null create header node.
     {
         head=new hnode; //Allocate dynamic mem for head node.
         head->next=p; //store the add of first node in head next.
         head->cnt=1; // increment the counter of header feild.
     }
     else
     {
         temp=head->next; //temp points the first node of list
         while(temp->next!=NULL)
         {
             temp=temp->next;  //go upto the next null.
         }
         temp->next=p; // at the end attache the node
         p->prev=temp;  // previous of p is temp
         head->cnt=head->cnt+1; // increment the counter.
     }
     n=n-1; // decrement the cnt of number of nodes.
 }
    return head; // The function returns the head node address.
}

void dll::show(hnode *h1)
{
    temp=h1->next; //temp points to the first node of list.
    cout<<"\n|cnt : "<<h1->cnt<<"|"<<h1->next<<"|-->";  //Display the containt of header node.
    while(temp!=NULL)
    {
        //the following cout display the prev pointer value, next pointer value and data value of node.
        cout<<"|"<<temp->prev<<"|Data is:"<<temp->data<<" |"<<temp->next<<"|<->"; //Display whole list information.
        temp=temp->next;// To traverse to the next node.
    }
        cout<<"\n";
}

//To merge this both the list in ascending order.

hnode * dll::merge_dll(hnode *h1,hnode *h2)
{
  node *p,*t1,*t2; //temporary pointer variables. t1 points to first list i:e h1 and t2 points to second list i:e h2.
  t1=h1->next;
  cout<<"\nt1 is...>"<<t1;
  t2=h2->next;
  cout<<"\nt2 is...>"<<t2;
  hnode *h3; //creating the third header node which stores the address of merge list i:e resultant list.
  h3=new hnode;    
  h3->cnt=0;  //init of header node 3
  h3->next=NULL;
  if(h1->next==NULL) //check if first list is empty
  {
   h3->next=h2->next; //assign address of second list to h3
   h3->cnt=h2->cnt; //store no of node in h2
   h2->next=NULL;  //make the second list i:e h2 null
   return h3;  //return h3 as final list
  }
  if(h2->next==NULL) //check if second list is empty
  {
   h3->next=h1->next; //assign address of first list i:e h1 to h3.
   h3->cnt=h1->cnt; //also store no of nodes in h1 to h3
   h1->next=NULL; //make the h1 i:e first list empty.
   return h3;  //return h3 as a final list.
  }
  if(t1->data<t2->data) //now if both are not null then check which list data is less if t1 nodes data is less than t2 node
  {
   h3->next=t1; //store t1 node as a first node of h3
   h3->cnt=1; //make the h3 cnt one.
   p=h3->next; //point temporary pointer variable p to first node of h3.
   t1=t1->next; //move to the next node
  }
  else  //if t2 node data is less than t1 node then
  {
   h3->next=t2; //store t2 node as a first node of h3
   h3->cnt=1; //make the h3 cnt one
   p=h3->next; //point temporary pointer variable p to first node of h3.
   t2=t2->next;//move to the next node
  }
  while(t1!=NULL&&t2!=NULL) //do the following till you are not getting the both lists end is null.(both condition must be true)
  {
   if(t1->data<t2->data)//check if t1 data is less than t2 data if yes do the following
   {
    p->next=t1; //connect t1 with the previous node i:e p (p stores the address of previous node)
    t1->prev=p; //connect t1 previous with p
    t1=t1->next; // go to the next node for checking.
    h3->cnt=h3->cnt+1; //increment the counter of h3 i:e metadata.
    p=p->next; //also move the temporary pointer p to the next node after sucessful connection to acts as prevoius node for the next node to connect 
   }
   else //check if t2 data is less than t1 data then do the following
   {
    p->next=t2; //connect t2 with the previous node i:e p (p stores the address of previous node)
    t2->prev=p; //connect t2 previous with p
    t2=t2->next; // go to the next node for checking.
    h3->cnt=h3->cnt+1; //increment the counter of h3 i:e metadata.
    p=p->next;//also move the temporary pointer p to the next node after sucessful connection to acts as prevoius node for the next node to connect.
   }
  }//end of while loop.
  if(t1!=NULL)//connect all the remaining nodes of t1 to h3 till t1 is not null
  {
   p->next=t1;
   t1->prev=p;
   h3->cnt=h3->cnt+1;
  }
  if(t2!=NULL)//connect all the remaining nodes of t2 to h3 till t2 is not null
  {
   p->next=t2;
   t2->prev=p;
   h3->cnt=h3->cnt+1;
  }
  h1->next=h2->next=NULL; //make the first list(h1) and second list(h2) next NULL bcaz all the node of both list get merged with third list h3.
 return h3; //return final list address h3.
}
//Program execution starts from main function.
int main()
{
    dll d1,d2,d3; //objects of class dll gets created.
    hnode *hd1,*hd2,*hd3; //pointer variables of hnode required to store address of lists.
    hd1=hd2=NULL; //initially they are null
    cout<<"\nFirst DLL :";
    hd1=d1.create(); //after calling of create function, address of first list gets stored into hd1.
    d1.show(hd1); //passing the address of first list hd1 to show function to display the whole list.
    cout<<"\n\nSecond DLL :";
    hd2=d2.create();//after calling of create function, address of second list gets stored into hd2.
    d2.show(hd2);//passing the address of second list hd2 to show function to display the whole list.
    cout<<"\n\nAfter Merge the DLL as Follows...\n";
    hd3=d3.merge_dll(hd1,hd2); //passing the addresses of both the list to merge function to merge both list in ascending order and store merge
                                    // address in hd3.
    d3.show(hd3); //passing the address of Merge list hd3 to show function to display the whole Merge list.

    return 0;
}