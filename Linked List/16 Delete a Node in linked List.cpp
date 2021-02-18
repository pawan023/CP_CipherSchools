// Delete a Node in linked List

void deleteNode(Node *a)
{
   Node *temp=a->next;
   swap(a->data,a->next->data);
   a->next=a->next->next;
   delete(temp);
}
