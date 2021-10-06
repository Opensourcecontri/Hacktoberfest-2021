#include <bits/stdc++.h>
using namespace std;

class node
{
public:
     int data;
     node *next;

     node(int val)
     {
          data = val;
          next = NULL;
     }
};

void makeCycle(node *&head, int pos)
{
     node *temp = head;
     node *startnode;

     int count = 1;
     while (temp->next != NULL)
     {

          if (count == pos)
          {
               startnode = temp;
          }

          temp = temp->next;
          count++;
     }
     temp->next = startnode; //here it reaches the last node and it will point at the startnode;
}

void insertAtTail(node *&head, int val)
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

node *detectCycle(node *&head)
{
     node *slow = head;
     node *fast = head;

     while (fast != NULL && fast->next != NULL)
     {
          slow = slow->next;
          fast = fast->next->next;

          if (slow == fast)
          {
               return slow;
          }
     }

     return NULL;
}

node *detectFirstNode(node *head)
{
     node *meet = detectCycle(head);
     if (meet == NULL)
          return NULL;
     node *start = head;

     while (start != meet)
     {
          start = start->next;
          meet = meet->next;
     }

     return start->next = NULL;
}

void display(node *head)
{
     node *temp = head;
     while (temp != NULL)
     {
          cout << temp->data << "->";
          temp = temp->next;
     }
}

int main()
{

     node *head = NULL;
     insertAtTail(head, 1);
     insertAtTail(head, 2);
     insertAtTail(head, 3);
     insertAtTail(head, 4);
     insertAtTail(head, 5);
     insertAtTail(head, 1);
     makeCycle(head, 3);
     // display(head);
     // head->next->next->next = head->next;
     // cout << detectCycle(head);
     if (detectCycle(head))
     {
          cout << "Cycle found" << endl;
          // cout << detectFirstNode(head) << endl;
     }
     else
          cout << "cycle not found" << endl;

     detectFirstNode(head);
     if (detectCycle(head))
     {
          cout << "Cycle found" << endl;
          // cout << detectFirstNode(head) << endl;
     }
     else
          cout << "cycle not found" << endl;
     return 0;
}
