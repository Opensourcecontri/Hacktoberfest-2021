void insertNodeAtPosition(int pos, int value)
{
      Node *pre = new Node;
      Node *current = new Node;
      Node *temp = new Node;
      cur = head;

      for(int i = 1; i < pos; i++)
      {
          pre = current;
          current = current->next;
      }
      temp->data = value;
      pre->next = temp; 
      temp->next = current;
}

int removeByIndex(int n) {
    int i = 0;
    int retval = -1;
    Node * current = head;
    Node * temp_node = nullptr;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == nullptr) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->value;
    current->next = temp_node->next;
    delete temp_node;

    return retval;

}
