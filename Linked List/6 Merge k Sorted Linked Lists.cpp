// Merge k Sorted Linked Lists

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
		return (b);
	else if(b == NULL)
		return (a);

	if(a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}

	return result;
}

Node* mergeKLists(Node* arr[], int N)
{
    int last=N-1;
    
	// repeat until only one list is left
	while (last != 0)
	{
		int i = 0, j = last;
    
		while (i < j)
		{
			// merge List i with List j and store
			// merged list in List i
			arr[i] = SortedMerge(arr[i], arr[j]);

			// consider next pair
			i++, j--;

			// If all pairs are merged, update last
			if (i >= j)
				last = j;
		}
	}

	return arr[0];
}


