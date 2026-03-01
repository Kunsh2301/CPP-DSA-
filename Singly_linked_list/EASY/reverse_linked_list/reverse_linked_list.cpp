#include <bits/stdc++.h>
using namespace std ;
class Node {
 public:
    int data ;
    Node *next ;
    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
Node* reverse(Node *head) {
    Node *prev = NULL ;
    Node *curr = head ;
    Node *next = NULL ;
    while(curr != NULL) {
        next = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = next ;
    }
    return prev ;
}
int main() {
    Node *head = new Node(1) ;
    head->next = new Node(2) ;
    head->next->next = new Node(3) ;
    head->next->next->next = new Node(4) ;
    head->next->next->next->next = new Node(5) ;
    head = reverse(head) ;
    while(head != NULL) {
        cout << head->data << " " ;
        head = head->next ;
    }
    return 0 ;
}