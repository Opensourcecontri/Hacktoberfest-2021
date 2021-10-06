#include <bits/stdc++.h>
using namespace std;

class node
{
public:
     char data;
     node *next;

     node(char val)
     {
          data = val;
          next = NULL;
     }
};

void insertAtHead(node *&head, int val)
{
     node *n = new node(val);
     n->next = head;
     head = n;
}

void insertAtTail(node *&head, char val)
{
     node *n = new node(val);

     if (head == NULL)
     {
          head = n;
          return;
     }

     node *temp = head;
     while (temp->next != NULL)
     {
          temp = temp->next;
     }
     temp->next = n;
}

node *middle(node *head)
{
     node *slow = head;
     node *fast = head;

     while (fast != NULL && fast->next != NULL)
     {
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;
}

node *reverse(node *&head)
{
     node *prev = NULL;
     node *curr = head;
     node *nextptr;

     while (curr != NULL)
     {
          nextptr = curr->next;
          curr->next = prev;

          prev = curr;
          curr = nextptr;
     }
     return prev;
}

void display(node *head)
{
     node *temp = head;
     while (temp != NULL)
     {
          cout << temp->data << "->";
          temp = temp->next;
     }
     cout << "NULL" << endl;
}

bool palindrome(node *head)
{
     if (head == NULL)
          return true;

     node *mid = middle(head);
     node *last = reverse(mid);

     node *curr = head;

     while (last != NULL)
     {
          if (last->data != curr->data)
          {
               return false;
          }
          else
          {
               last = last->next;
               curr = curr->next;
          }
     }
     return true;
}

int main()
{

     node *head = NULL;
     insertAtTail(head, 'r');
     insertAtTail(head, 'a');
     insertAtTail(head, 'c');
     insertAtTail(head, 'e');
     insertAtTail(head, 'c');
     insertAtTail(head, 'a');
     insertAtTail(head, 'r');
     display(head);
     // insertAtHead(head, 69);
     // display(head);

     /* 
          Iterative
     */

     // node *newhead = reverse(head);
     // cout << "Reverse LL using Iterative: ";
     // display(newhead);

     /* 
          Recursive
     */

     int res = palindrome(head);
     if (res == 1)
     {
          cout << "Palindrome!";
     }
     else
     {
          cout << "not Palindrome!";
     }
     // display(head);
     return 0;
}
