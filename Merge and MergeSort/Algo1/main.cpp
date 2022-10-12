#include <iostream>

using namespace std;

void merge (int numbers[], int left, int medium, int right){

    int a, b, c;
    int num1 = medium-left+1;
    int num2 = right-medium;

    int Left[num1], Right[num2];

    for (a = 0; a < num1; a++)
        Left[a] = numbers[left + a];
    for (b = 0; b < num2; b++)
        Right[b] = numbers[medium + b+ 1];

    a=0, b=0;
    c = left;

    while (a<num1 && b<num2)
    {
        if(Left[a] <= Right[b]){
            numbers[c] = Left[a];
            a++;
        }

        else{
            numbers[c] = Right[b];
            b++;
        }
        c++;
    }

    while (a<num1)
    {
        numbers[c] = Left[a];
        a++;
        c++;
    }

    while(b<num2)
    {
        numbers[c] = Right[b];
        b++;
        c++;
    }
}

void mergesort(int numbers[], int left, int right){

    if(left<right)
    {
        int medium = (left+right-1)/2;

        mergesort(numbers, left, medium);
        mergesort(numbers, medium+1, right);
        merge(numbers, left,medium,right);

    }
}

int main()
{
    int numbers[] = {1,4,5,8,2,3,6,7};

    int size = sizeof(numbers) / sizeof(numbers[0]);
    mergesort(numbers, 0, size-1);

    for (int k=0; k<size; k++){
        cout<<numbers[k]<<" ";
    }
    return 0;
}
