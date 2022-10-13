#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int partition(int arr[], int l, int r, int k);

//O(n)
int findMedian(int arr[], int n)
{
	sort(arr, arr+n);
	return arr[n/2];
}

int kthElement(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1;

		int i, median[(n+4)/5];
		//O(n)
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
		if (i*5 < n)
		{
			median[i] = findMedian(arr+l+i*5, n%5);
			i++;
		}

		int medOfMed;
        //O(n/5)
        if (i != 1){
            medOfMed = kthElement(median, 0, i-1, i/2);
        }
        else
            medOfMed = median[i-1];

		int pos = partition(arr, l, r, medOfMed);

		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthElement(arr, l, pos-1, k);

		return kthElement(arr, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int l, int r, int x)
{

	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);
	i = l;
	//O(n)
	for (int m = l; m <= r - 1; m++)
	{
		if (arr[m] <= x)
		{
			swap(&arr[i], &arr[m]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

int main()
{
    int arr[] = {3,7,4,16,14,19,11,5,0};
    int sizeArr = sizeof(arr)/sizeof(arr[1]);
    int k=4;

    cout<<"K'th Smallest Element: " << kthElement(arr, 0, sizeArr-1, k);

    return 0;
}
