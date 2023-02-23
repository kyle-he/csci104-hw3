#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        smaller = head;
        larger = head;
        return;
    }
    
    llpivot(head->next, smaller, larger, pivot);

    Node* nextNode = head->next;
    if (head->val > pivot) {
        head->next = larger;
        larger = head;
    } else  {
        head->next = smaller;
        smaller = head;
    }
    head = nextNode;
}