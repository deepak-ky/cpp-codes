Node * temp = node->next;
node->data = temp->data;
node->next = temp->next;
delete temp;