// Find median in a stream 

#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};

// Function to insert heap
void FindMedian::insertHeap(int &x) {
    if (max.empty())
		max.push(x);
	else if (x > max.top())
		min.push(x);
	else if(min.empty())
	{
		min.push(max.top());
		max.pop();
		max.push(x);
	}
	else
		max.push(x);
	balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps() {
    if (abs(max.size() - min.size()) > 1) //Heaps are not balanced
	{
		if (max.size() > min.size())
		{
			min.push(max.top());
			max.pop();
		}
		
		else
		{
			max.push(min.top());
			min.pop();
		}
	}
}

// Function to return getMedian
double FindMedian::getMedian() {
    if ((max.size() + min.size()) % 2 == 0)
	{
		median = (max.top() + min.top());
		median /= 2;
	}
	else
	{
		if (min.empty())
			median = max.top();
		else if (min.size() < max.size())
			median = max.top();
		else
			median = min.top();
	}
	
	return median;
}

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	FindMedian Ans;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		Ans.insertHeap(x);
    	    cout << floor(Ans.getMedian()) << endl;
    	}
    }
	return 0;
} 

