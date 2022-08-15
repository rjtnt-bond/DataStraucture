# DataStraucture
#include<bits/stdc++.h>
using namespace std;
class Node
{
    void insertAtTail(Node* &head,int val);
    void insertAtHead(Node* &head,int val);
    void display(Node *n);
    int length_linklist(Node *&h);
    void inserAtSpecificpPosition(Node *&head,int pos,int val);
    int searchByeValueUnique(Node *&head,int val);
    void  searchByeValueDuplicate(Node *&head,int key);
//    Test searchByValueDuplicateReturn(Node *&head,int key);
    void InsertsearchByeValueUnique(Node *&head,int searchval,int value);
    void  InsertsearhByvalueDuplicate(Node *&head,int searchval,int key);
    void  DelationHead(Node *&head);
    void  DelationTail(Node *&head);
    void DelationAtSpecificPosition(Node *&head,int position);
    void deletionByValueUnique(Node *&head,int value);
    void deleteValueAtDuplicat(Node *&head,int value);



public:
    int value;
    Node *Next;
    //Constructer Creation
    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};
struct Test
{
    int position[1000];
};
void insertAtTail(Node* &head,int val)
{
    Node *newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;

}
void insertAtHead(Node* &head,int val)
{

//s1: NewNode creation
    Node *newNode=new Node(val);
//s2: Update of NewNode->next=head
    newNode->Next=head;
//s3: update head
    head=newNode;

}
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value<<" ";

        n= n->Next;
    }
    cout<<endl;
}

int length_linklist(Node *&h)
{
    Node *temp=h;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->Next;
        cnt++;
    }
    return cnt;
}

void inserAtSpecificpPosition(Node *&head,int pos,int val)
{
    Node *NewNode=new Node(val);
    int i=0;
    Node *temp=head;
    while(i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    NewNode->Next=temp->Next;
    temp->Next=NewNode;

}

int  searchByeValueUnique(Node *&head,int key)
{
    Node *temp=head;
    int cnt=1;
    //case-1 head null
    if(temp==NULL)
    {
        return -1;
    }

    while(temp->value!=key )         /*&& temp->Next!=NULL*/
    {
        //case -2 value not found
        if(temp->Next==NULL)
        {
            return -1;
        }
        temp=temp->Next;
        cnt++;
    }
    return cnt;
}

void  searchByeValueDuplicate(Node *&head,int key)
{
    Node *temp=head;
    int cnt=1,flag=0;
    int size=length_linklist(head);
    int position[size+1],k=1;
    while(temp!=NULL)
    {
        if(temp->value==key)
        {
//        cout<<cnt<<" ";
            position[k]=cnt;
            k++;
            flag=1;
        }
        temp=temp->Next;
        cnt++;
    }
    if(flag==0)
    {
        cout<<"The Searched Value is not yet in the list "<<endl;
    }

    else
    {
        position[0]=k;
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1) cout<<" , ";
        }
    }
    cout<<endl;
}
//return using arr by struct
Test searchByValueDuplicateReturn(Node *&head,int key)
{
    Node *temp=head;
    Test T;
    int cnt=1,k=1;
    while(temp!=NULL)
    {
        if(temp->value==key)
        {
            T.position[k]=cnt;
            k++;

        }
        temp=temp->Next;
        cnt++;
    }
    T.position[0]=k;
    return T;

}
void InsertsearchByeValueUnique(Node *&head,int searchval,int value)
{
    //step-1: Search the Position of the searchValue
    int position;
    position=searchByeValueUnique(head,searchval);
    //step-2: Insert the value at the positioninsert
    inserAtSpecificpPosition(head,position+1,value);


}

//add value duplicate position by searching value
void  InsertsearhByvalueDuplicate(Node *&head,int searchval,int value)
{
//step=1
    Test t;
    t=searchByValueDuplicateReturn(head,searchval);
    int size=t.position[0];
    for(int i=1; i<size; i++)
    {
        inserAtSpecificpPosition(head,t.position[i]+i,value);
    }
}

void  DelationHead(Node *&head)
{
    //step save
    Node *temp=head;
    //delete if possible
    if(temp!=NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else
    {
        cout<<"There is no value "<<endl;
    }

}


void  DelationTail(Node *&head)
{
    //step-1  save head
    Node *temp=head;
    //delete if possible
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
    }
    else
    {
        // Head is Null
        if(temp==NULL)
        {
            cout<<"There is no value "<<endl;
        }
        //Head At Tail Same
        else
        {
            DelationHead(head);
        }

    }
}

void DelationAtSpecificPosition(Node *&head,int position)
{
    Node *temp=head;

    if(position<=length_linklist(head))
    {
        if(position==1)
        {
            DelationHead(head);
        }
        else if(position==length_linklist(head))
        {
            DelationTail(head);
        }
        else
        {
            int i=1;
            while(i<position-1)
            {
                temp=temp->Next;
                i++;
            }
            Node *delNode=temp->Next;
            temp->Next=delNode->Next;
            delete delNode;
        }

    }
    else
    {
        // Position Out of Range
//        if(position>length_linklist(head))
//        {
            cout<<"Position Out of Bound"<<endl;
//        }
        //LL NULL
//        else
//        {
//            cout<<"There is no value "<<endl;
//        }

    }

}

void deletionByValueUnique(Node *&head,int val){
    //Find the position Of the Value
    int position;
    position=searchByeValueUnique(head,val);
    //DeletionAt Specific Position
    if(position==-1){
        cout<<"Value Not Found in the linked list "<<endl;
    }
    else{
        DelationAtSpecificPosition(head,position);
    }


}

//void delete value at duplication
void deleteValueAtDuplicat(Node *&head,int value){
    Node *temp=head;
    Test t;
    t=searchByValueDuplicateReturn(head,value);
    int size=t.position[0];
    if(size==1){
        cout<<"There is no dublicate value "<<endl;
    }
    else{
          for(int i=1;i<size;i++){
         DelationAtSpecificPosition(head,t.position[i]);
         for(int j=i+1;j<size;j++){
            t.position[j]--;
         }
    }
    }





}





int main()
{
    Node *head=NULL;
    int n,postion;
    //Choice 1: Insertion At head
    //Choice 2: Insertion at Tail
    cout<<"Choice 1: Insertion at Head "<<endl
        <<"Choice 2: Insertion at tail  "<<endl
        <<"Choice 3: Insertion At Specific Position "<<endl
        <<"Choice 4: Search  a value (unique List) "<<endl
        <<"Choice 5: Search  a value (Duplication enable In List ) "<<endl
        <<"Choice 6: Insertion after  a specific  value (Unique List ) "<<endl
        <<"Choice 7: Display Link list "<<endl
        <<"Choice 8: Insertion after a specific value(Duplicate list ) "<<endl
        <<"Choice 9: Deletion Head value "<<endl
        <<"Choice 10: Deletion Tail value "<<endl
        <<"Choice 11: Deletion At Specific Position  "<<endl
         <<"Choice 12: Deletion by Value(Unique List)  "<<endl
         <<"Choice 13: Deletion by Value(Duplicate List)  "<<endl
        <<"Choice 0: Exist "<<endl<<endl;
    cout<<"Enter Your Choice : ";
    int  choice;
    cin>>choice;
    while(choice !=0 )
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter the Value: ";
            cin>>n;
            insertAtHead(head,n);
            break;
        case 2:
            cout<<"Enter the Value: ";
            cin>>n;
            insertAtTail(head,n);
            break;
        case 3:
            cout<<"Enter the Desired Position : ";
            cin>>postion;
            cout<<"Enter the Value: ";
            cin>>n;
            inserAtSpecificpPosition(head,postion,n);
            break;
        case 4:
            cout<<"Enter the Value: ";
            cin>>n;
            postion=searchByeValueUnique(head,n);
            if(postion!=-1)
            {
                display(head);
                cout<<"The Position Of this  value is : "<<postion<<endl;
            }
            else
            {
                cout<<"Value Not found "<<endl;
            }
            break;
            
// this module we implement this case Module(18)
        case 5:
            cout<<"Enter the Value: ";
            cin>>n;
            Test T;
            T=searchByValueDuplicateReturn(head,n);
            if(T.position[0]==1)
            {
                cout<<"The Searched Value is note yet in the list "<<endl;
            }
            else
            {
                int size =T.position[0];
                cout<<"The value is found at position ";
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i]<<" ";
                    if(i<size-1) cout<<",";
                }
                cout<<endl;
            }

            break;
        case 6:
            cout<<"Enter the value to search: ";
            int searchValue;
            cin>>searchValue;
            cout<<"Enter the value to Insert: ";
            cin>>n;
           InsertsearchByeValueUnique(head,searchValue,n);
            break;
        case 7:
            cout<<endl<<"Link list Print "<<endl;
            display(head);
            cout<<endl;
            break;
        case 8:
            cout<<"Enter the value to search: ";
            cin>>searchValue;
            cout<<"Enter the value to Insert: ";
            cin>>n;
            InsertsearhByvalueDuplicate(head,searchValue,n);
            break;
        case 9:
            DelationHead(head);
            break;
        case 10:
            DelationTail(head);
            break;
        case 11:
            if(head==NULL){
                cout<<"There is No Value in the Linked list "<<endl;
                break;
            }
            cout<<"Enter the position ";
            cin>>postion;
            DelationAtSpecificPosition(head,postion);
            break;
        case 12:
            cout<<"Enter the value to delete: ";
            int delvalue;
            cin>>delvalue;
            deletionByValueUnique(head,delvalue);
            break;
        case 13:
            if(head==NULL){
                cout<<"There is No value "<<endl;
                break;
            }
            cout<<"Enter the value to delete: ";
            cin>>delvalue;
            deleteValueAtDuplicat(head,delvalue);
            break;




        default:
            break;

        }


        cout<<"Next Choice: ";
        cin>>choice;

    }
//    cout<<endl<<"Link list Print "<<endl;
//    display(head);
    cout<<"Link list length"<<endl;
    cout<<length_linklist(head);

}








