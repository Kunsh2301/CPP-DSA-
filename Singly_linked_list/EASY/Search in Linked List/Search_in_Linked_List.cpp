/*Given a linked list with the head node and a key, 
the task is to check if the key is present in the linked list or not. 
Return true if key is present, else return false.*/
#include<iostream>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
bool searchKey(Node* head, int key) {
    while(head!=NULL){
        if(head->data==key) return true;
        head=head->next;
    }
    return false;
}
int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    int key;
    cout<<"Enter the key to search: ";
    cin>>key;
    if(searchKey(head, key)) cout<<"Key is present in the linked list."<<endl;
    else cout<<"Key is not present in the linked list."<<endl;
    return 0;
}