#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node{
int data;
struct node *link;
};
void display(struct node *head)
{
    struct node *current;
    current=head;
    if(head==NULL)
        cout<<"list is empty\n"<<endl;
    else{
            while(current!=NULL)
    {
        cout<<current->data<<" ";
        current=current->link;
    }
    cout<<endl;
    }
}
void add_at_begin(struct node* head,int d)
{
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=d;
    current->link=NULL;
    head->link=current;
}
void add(struct node *head,int d)
{
     struct node *current=(struct node*)malloc(sizeof(struct node));
     current=head;
     while(current->link!=NULL){
         current=current->link;
     }
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=d;
     ptr->link=NULL;
     current->link=ptr;
}
 void add_at_pos(struct node *head,int d,int pos)
{
      struct node *current=(struct node*)malloc(sizeof(struct node));
      current=head;
      if(pos==1){

          current->data=d;
          head=current;
      }
      else{
      pos--;
      while(pos!=1)
      {
          current=current->link;
          pos--;
      }
      struct node *ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=d;
     ptr->link=current->link;
     current->link=ptr;
      }
}
   struct node *del(struct node  *head)
 {
     if(head==NULL){
            cout<<"List is empty"<<endl;
     }
     cout<<head->data<<" is deleted"<<endl;
     struct node *temp=head;
     head=head->link;
     free(temp);
     temp=NULL;
     return head;
 }
 void del_last(struct node*head)
 {
     struct node *current=head;
     while(current->link->link!=NULL)
     {
         current=current->link;
     }
     cout<<current->link->data<<"last is deleted\n"<<endl;
     free(current->link);
     current->link=NULL;
  }
  struct node*del_at_pos(struct node*head,int pos)
  {
      struct node *current=head;
      struct node *previous=head;
      cout<<"delete from "<<pos<<",";
      if(pos==1){
          head=head->link;
          cout<<current->data<<" is deleted\n"<<endl;
          free(current);
          current=NULL;
      }
      else {
            while(pos!=1){
          previous=current;
          current=current->link;
          pos--;
      }
      previous->link=current->link;
      cout<<current->data<<" is deleted\n"<<endl;
      free(current);
      current=NULL;
      }
      return head;
  }
  struct node * del_list(struct node *head)
  {
      struct node * current=head;
      while(current!=NULL)
      {
          current=current->link;
          free(head);
          head=current;
      }
      cout<<"list is cleared\n"<<endl;
      return head;
  }
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;
    display(head);
    add_at_begin(head,10);
    display(head);
    add(head,15);
    display(head);
    add_at_pos(head,50,4);
    add(head,30);
    add(head,35);
    display(head);
    head=del(head);
    display(head);
    del_last(head);
    display(head);
    del_last(head);
    display(head);
    head=del_at_pos(head,2);
    display(head);
    head=del_list(head);
    display(head);
    return 0;
}
