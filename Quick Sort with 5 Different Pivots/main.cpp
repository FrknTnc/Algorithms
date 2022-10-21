#include <bits/stdc++.h>
#include <iostream>
#include <time.h>

using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int findRandom(int arr[], int l, int r){

    srand(time(NULL));
    int randomIndex = rand() % 10000;

    return arr[randomIndex];
}

int findMax(int arr[], int l, int r){

    int maxElement = arr[0];

    for(l=0; l<=r ; l++){
        if(arr[l] > maxElement){
            maxElement = arr[l];
        }
    }
    return maxElement;
}

int findMedian(int arr[], int l, int r) {
    int n = r-l+1;
    int pos = 0;
    if (n % 2 == 0) {
        pos = n/2 - 1 + l;
    } else {
        pos = n/2 + l;
    }
    int a = arr[l];
    int b = arr[pos];
    int c = arr[r];
    int maxNumber = max({a, b, c});
    int minNumber = min({a, b, c});
    if (a != maxNumber && a != minNumber)
        return l;
    else if (b != maxNumber && b != minNumber)
        return pos;
    else
    return r;
}

int partition(int arr[], int l, int r, int pi) {
    if (pi != 0){
        swap(arr, l, pi);
    }

    int pivot = arr[l];
    int i = l+1;
    for (int j = l+1; j <= r; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, l, i-1);
    return i-1;
}

int quickSort(int arr[], int l, int r) {
    if (r <= l) {
        return 0;
    }

    // pivot -> median
    // int position = partition(arr, l, r, findMedian(arr, l, r)); //138382

    // pivot -> last element
    // int position = partition(arr, l, r, r); //164123

    // pivot -> first element
    // int position = partition(arr, l, r, 0); //162085

    // pivot -> max element
    // int maxElement = findMax(arr, l, r);
    // int position = partition(arr, l, r, maxElement); //247244

    // pivot -> random element
    int randomElement = findRandom(arr, l, r);
    int position = partition(arr, l, r, randomElement); //216484 //230949


    int left = quickSort(arr, l, position-1);
    int right = quickSort(arr, position+1, r);

    return left+right+r-l;

}

int main() {
    int array_size = 10000;
    int arr[array_size];
    ifstream file("quicksort.txt");
    string str;
    int n = 0;
    while (getline(file, str)) {
        arr[n] = stoi(str);
        n++;
    }
    cout<< quickSort(arr, 0, array_size-1) <<endl;

}
