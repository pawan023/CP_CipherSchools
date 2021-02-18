// Remove duplicates from an unsorted linked list

Node * removeDuplicates( Node *head) 
{
 // your code goes here
 unordered_map<int,int> umap;
 Node *curr = head, *temp;
 while(curr){
     //element first occc=urence , insert it in umap
    if( umap.find(curr->data)==umap.end() ){
        umap[curr->data] = 1;
        temp = curr;
        curr = curr->next;
    }
    //element alrdy occured
    else{
        temp->next = curr->next;
        free(curr);
        curr = curr->next;
    }
 }
    return head;
}
