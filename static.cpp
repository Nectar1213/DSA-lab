#include<iostream>
#define SIZE 10

using namespace std;

class ArrayList
{
int cur_pos;
int *arr;
public:
ArrayList(){
cur_pos=-1;
arr = new int[SIZE];
}
void insert_at_pos(int pos,int item){
int temp;
if(cur_pos==-1){
cur_pos=0;
}
if((cur_pos==SIZE-1) || (pos>=cur_pos+1)){
cout<<"invalid insert"<<endl;
exit(0);
}
else{
if(pos==cur_pos){
arr[cur_pos++] = item;
}
else{
temp = cur_pos;
while(temp!=pos){
arr[temp] = arr[temp-1];
temp--;
}

arr[temp] = item;
cur_pos++;
}
}
}
void delete_from_pos(int pos){
int temp;
if((cur_pos==-1)|| (pos>=cur_pos+1)){
cout<<"invalid delete"<<endl;
exit(0);
}
else{
if(pos==cur_pos-1){
cout<<"Element deleted is:"<<arr[pos]<<endl;

cur_pos--;
}
else{
temp=pos;
cout<<"Element deleted is:"<<arr[pos]<<endl;

while(temp!=cur_pos-1){
arr[temp] = arr[temp+1];
temp++;
}
cur_pos--;
}
}
}
void display(){
int i;
for(i=0;i<=cur_pos-1;i++){

cout<<arr[i]<<" ";
}
cout<<endl;
}
};
int main(){
ArrayList l;
l.insert_at_pos(0,10);
l.insert_at_pos(1,20);
l.insert_at_pos(2,30);
l.insert_at_pos(3,40);
l.display();
l.insert_at_pos(2,100);
l.display();
l.delete_from_pos(2);
l.display();
return 0;
}