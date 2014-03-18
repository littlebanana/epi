#include <iostream>
#include <algorithm>

using namespace std;

class DutchFlag
{
	public:
		int partition(int A[], int pivot, int left, int right)
		{
			// re-arrange array so that
			// elements < A[pivot], followed by A[pivot], followed by elements > A[pivot]
			// pivot position will be changed!

			swap(A[pivot], A[right]);

			int smaller = left-1;				// A[left...smaller] are the elements < A[pivot]
			int larger = right;					// A[larger...(right-1)] are the elements > A[pivot]
			for (int i = left; i < larger; i++)
			{
				if (A[right] > A[i])
				{
					swap(A[i], A[++smaller]);
				}
				else if (A[right] < A[i])
				{
					swap(A[i--], A[--larger]);
				}
			}
			swap(A[right], A[larger]);

			return larger;	// return new pivot position
		}

		void sort(int A[], int left, int right)
		{
			if (left < right)
			{
				int mid = left + (right-left)/2;

				mid = partition(A, mid, left, right);

				sort(A, left, mid-1);
				sort(A, mid+1, right);
			}
		}

		void sort(int A[], int n)
		{
			sort(A, 0, n-1);
		}
};

void printArray(int A[], int n)
{
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n-1)
		{
			cout << " ";
		}
	}
	cout << "]" << endl;
}

int main()
{
	int A[] = {5, 3, 4, 7, 1, 2, 3, 3, 4, 7, 8, 7, 3, 5, 9};
	printArray(A, 15);

	DutchFlag dfs;
	dfs.partition(A, 2, 0, 14);
	printArray(A, 15);

	dfs.sort(A, 15);
	printArray(A, 15);

	return 0;
}
