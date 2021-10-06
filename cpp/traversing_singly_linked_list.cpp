class LinkedList
{
public:
    LinkedList()
    {
        head = nullprt;
        tail = nullptr;
    }

    void createNode(int value)
    {
        node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {   
            tail->next = temp;
            tail = temp;
        }
    }

    void printList() {
        Node * current = head;

        while (current != nullptr) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

private:
    Node *head;
    Node *tail;
};
