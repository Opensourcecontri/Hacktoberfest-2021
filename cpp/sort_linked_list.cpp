#include <iostream>
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
node *input()
{
     int data;
     cin >> data;
     node *head = NULL;
     node *tail = NULL;
     while (data != -1)
     {
          // creating node
          node *n = new node(data);
          // checking
          if (head == NULL)
          {
               head = n;
               tail = n;
          }
          else
          {
               tail->next = n;
               tail = n;
          }
          cin >> data;
     }
     return head;
}
void print(node *head_add)
{
     while (head_add != NULL)
     {
          cout << head_add->data << " ";
          head_add = head_add->next;
     }
}

node *meegetwolist(node *l1, node *l2)
{
     if (l1 == NULL)
          return l2;
     if (l2 == NULL)
          return l1;

     node *newhead;
     if (l1->data > l2->data)
     {
          newhead = l2;
          l2 = l2->next;
     }
     else
     {
          newhead = l1;
          l1 = l1->next;
     }
     node *newtail = newhead;
     while (l1 && l2)
     {
          if (l1->data < l2->data)
          {
               newtail->next = l1;
               l1 = l1->next;
          }
          else
          {
               newtail->next = l2;
               l2 = l2->next;
          }
          newtail = newtail->next;
     }
     if (l1)
          newtail->next = l1;
     else
          newtail->next = l2;
     return newhead;
}

node *sortthelist(node *head)
{
     if (head == NULL || head->next == NULL)
          return head;

     node *first = head;
     node *second = head->next;

     while (second && second->next)
     {
          first = first->next;
          second = second->next->next;
     }
     node *n = first->next;
     first->next = NULL;

     node *a = sortthelist(head);
     node *b = sortthelist(n);
     head = meegetwolist(a, b);
     return head;
}
int main()
{
     node *head;
     cout << "Enter the input (put -1 at end): ";
     head = input();
     head = sortthelist(head);
     print(head);
}