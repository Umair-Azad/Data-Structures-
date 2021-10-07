#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

class linkedList
{
public:
    node* head;
    node* tail;
    int count;
    linkedList()
    {
        head=NULL;
        tail=NULL;
        count=0;
    }
    void createnode(int value)
    {
        node* temp=new node;
        temp->data=value;
        temp->next=NULL;
        count++;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void insertnode(int value)
    {
        node* temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
        count++;
    }
    void insertatpos(int pos,int value)
    {
        if((pos-1)>length())
        {
            cout<<"Node Cannot be added at this position  length is "<<length()<<endl;
        }
        else{

        if(pos==1)
        {
            insertnode(value);
        }
        else
        {
        node* pre=new node;
        node* post=new node;
        node* temp=new node;
        post=head;

        for(int  i = 1;i < pos ; i++)
        {
            pre = post;
            post = post->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = post;
        count++;
        }}
    }
 int pop()
    {
        int reteval=0;
        node* temp=new node;
        reteval=head->data;
        temp=head->next;
        delete head;
        head=temp;
        count--;
        return reteval;
    }

    int deletion(int pos)
    {
        if((pos)>length())
        {
            cout<<"Node Cannot be deleted at this position list length is "<<length()<<endl;
        }
        else{
        if(pos==1)
        {
            pop();
        }
        else
        {
         int reteval;
          node* temp=new node;
          node* current=new node;
          current = head;
          for(int i=1;i<=length();i++)
          {
              if(i==pos)
              {
                  reteval=current->data;
                  temp->next=current->next;
                  delete current;
                  count--;
                  return reteval;
              }
              temp=current;
              current=current->next;
          }
        }}
    }

    int searching(int x)
    {
        int counter=0;
        node* temp=new node;
        temp=head;
        for(int i=0;i<=length();i++)
        {
            if(temp->data==x)
            {
                counter++;
                return counter;
            }
            temp=temp->next;
            counter++;
        }
        if(temp->next==NULL)
        {
            return -1;
        }
    }
    int length()
    {
        if((head==NULL)&&(tail==NULL))
        {
            return 0;
        }
        return count;
    }
    
    int empty()
    {
        if((head==NULL)&&(tail==NULL))
        {
            return 0;
        }
        else
            return -1;
    }

         void printList() {
        node* current = head;
        int counter=1;
        if(head==NULL)
        {
            cout<<"List is Empty!!!"<<endl;
        }
        else
        {
        cout<<endl<<"Printing the List : "<<endl;
        while (current != NULL) {
            cout <<counter<<". "<<current->data <<endl;
            current = current->next;
            counter++;
        }
        cout<<endl;
    }
     }
};

int main()
{
    linkedList l;
        int choice,data1,pos;
        do{
        cout<<"1. insert Node at any position"<<endl;
        cout<<"2. Delete a Node from any Position"<<endl;
        cout<<"3. Search for a node in the L L"<<endl;
        cout<<"4. Find the Length of the L L"<<endl;
        cout<<"5. Check whether the List is Empty or Not"<<endl;
        cout<<"6. Print the Whole Linked List"<<endl;
        cout<<"7. To Exit the Program "<<endl;
        cin>>choice;
         if(choice==1)
        {
            cout<<"Enter any number you want to save in the node"<<endl;
            cin>>data1;
            cout<<"Now, enter the position where the number is to be stored"<<endl;
            cin>>pos;
            l.insertatpos(pos,data1);
        }
        if(choice==2)
        {
            cout<<"Enter the position from where the node is to be deleted"<<endl;
            cin>>pos;
            l.deletion(pos);
        }
         if(choice==3)
        {
            cout<<"Enter the Value you want to searched in the node"<<endl;
            cin>>data1;
            if(l.searching(data1)>=0)
            {
                cout<<"The data is found at "<<l.searching(data1)<<"th position"<<endl;
            }
            else
                cout<<"NO data"<<endl;
        }
         if(choice==4)
        {
            cout<<"The Length of the LL is "<<l.length()<<endl;
        }
         if(choice==5)
        {
            if(l.empty())
            {
                cout<<"The List is Not Empty"<<endl;
            }
            else
                cout<<"The List is Empty"<<endl;
        }
        if(choice==6)
        {
            l.printList();
        }
    }while(choice!=7);

    return 0;
}
