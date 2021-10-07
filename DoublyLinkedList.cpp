#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class DoublyLL
{
private:
     node *head,*curr,*temp;
     int size;
public:
    DoublyLL()
    {
        head=NULL;
        curr=NULL;
        temp=NULL;
        size=0;
    }
    void insertion(int val,int pos)
    {
        if(pos<1 || pos>(size+1))
        {
            cout<<"invalid position"<<endl;
            return;
        }
        node *n=new node(val);
        if(pos==1)
        {
           n->next=head;
           head->prev=n;
           head=n;
        }
        else
        {
         curr=head;
         for(int i=1; i< (pos-1); i++)
         {
             curr=curr->next;
         }
         n->next=curr->next;
         n->prev=curr;
         (curr->next)->prev=n;
         curr=n->next;
        }
        size++;
    }
    void deletion(int pos)
    {
        if(head==NULL)
        {
            cout<<"The linked list is Empty"<<endl;
            return;
        }
        if(pos==1)
        {
        curr=head;
        head=head->next;
        delete curr;
        head->prev=NULL;
        }
        else{
            curr=head;
            for(int i=0; i<(pos-1); i++)
            {curr=curr->next;}
            temp=curr->next;
            curr->next=temp->next;
            (temp->next)->prev=curr;
            delete temp;
        }
        size--;
    }
    void print(){
        if(head==NULL)
        {
            cout<<"The linked list is Empty"<<endl;
            return;
        }
        int pos=1;
        curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<endl;
            curr=curr->next;
          pos++;
        }
    }
    int Searching(int val)
    {
        if(head==NULL)
        {
            cout<<"The linked list is Empty"<<endl;
            return 0;
        }
        int pos=1;
        curr=head;
        while(curr!=NULL)
        {
            curr->data==val;
            return pos;
            curr=curr->next;
            pos++;
        }
    }
};
    int main()
{
    DoublyLL l;
    int val,pos,choice;
    do{
    cout<<"-------------------------Menu Of LL--------------------------------"<<endl;
    cout<<"1:press 1 for insertion in the LL of your choice"<<endl;
    cout<<"2:press 2 for deletion"<<endl;
    cout<<"3:press 3 to print the whole list"<<endl;
    cout<<"4:press 4 for searching"<<endl;
    cout<<"5:press 5 to exist the program"<<endl;
    cin>>choice;

    if(choice==1)
    {
    cout<<"Enter value you want to insert"<<endl;
    cin>>val;
    cout<<"Enter position where you want to insert value"<<endl;
    cin>>pos;
    l.insertion(val,pos);
    }
    else if(choice==2){
        cout<<"Enter position you want to delete in the LL"<<endl;
        cin>>pos;
          l.deletion(pos);
    }
    else if(choice==4)
    {
        cout<<"Enter value you want to search in the LL"<<endl;
        cin>>val;
        cout<<"The value is at "<<l.Searching(val)<< "th in the Linked List"<<endl;
        
    }
    else if (choice==3)
    {
        cout<<"---------------Linked list-------------------"<<endl;
        l.print();
    }
    }while(choice!=5);

}
