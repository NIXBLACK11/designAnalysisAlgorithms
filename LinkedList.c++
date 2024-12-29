#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    
    while(curr!=NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return head = prev;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for(int i=1;i<arr.size();i++) {
        ListNode *temp = new ListNode(arr[i]);
        curr->next = temp;
        curr = curr->next;
    }

    printList(head);

    head = reverse(head);

    printList(head);
}