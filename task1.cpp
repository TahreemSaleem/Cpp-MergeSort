#include <iostream>
using namespace std;


int main()
{
	
	int size;
	void mergesort(int *a, int start, int end);
	cout << "enter the size of the array" << endl;
	cin >> size;
	int *arr = new int[size];
	cout << "input elements" << endl;;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	mergesort(arr, 0, size);
	cout << "merge sort" << endl;;
	for (int i = 1; i <= size; i++)
	{
		cout << arr[i] << endl;;
	}
}
//merge sout function which sorts the array
void mergesort(int *a, int start, int end)
{
	void merge(int *a, int start, int end, int mid); //defining merge function 
	int mid;
	if (end - start == 0)  //base case of our recursion function
		return;
	else
	{
		mid = (start + end) / 2;		//finding the mid point of two arrays
		mergesort(a, start, mid);		//recursively calling the mergesort function by passing half of the array
		mergesort(a, mid + 1, end);
		merge(a, start, end, mid); // in the end merging the two divided arrays
	}//else ends

}//end mergesort
//merge function
void merge(int *a, int start, int end, int mid){
	int i = start;
	int j = mid + 1;
	int k = start;
	int  c[50]; // making a temporary array to store the elements

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j]) //checking if the element in the left side is less than the elemnt in the right side of the array
			c[k++] = a[i++]; //storing that element in the temporary array//incrementing the temporary array index//incrementing the left side of the array index

		else
			//else store the right side element in the temporary array
			c[k++] = a[j++];//storing that element in the temporary array//incrementing the temporary array index//incrementing the right side of the array index
	}
	while (i <= mid) // if some elemnts are left in the right part array store them into the temporary array
		c[k++] = a[i++];

	while (j <= end) //if some elements are left in the left part array store them into temporary array
		c[k++] = a[j++];

	for (i = start; i < k; i++) //store the elemnts from the temporary array into array passed in the function
	{
		a[i] = c[i];
	}
}
