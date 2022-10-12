#include <iostream>

using namespace std;

void merge (int numbers1[], int numbers2[], int numbers3[], int size1, int size2){

    int a, b, c;
    a=0, b=0, c=0;

    while (a<size1 && b<size2)
    {
        if(numbers1[a] <= numbers2[b]){
            numbers3[c] = numbers1[a];
            a++;
        }

        else{
            numbers3[c] = numbers2[b];
            b++;
        }
        c++;
    }

    while (a<size1)
    {
        numbers3[c] = numbers1[a];
        a++;
        c++;
    }

    while(b<size2)
    {
        numbers3[c] = numbers2[b];
        b++;
        c++;
    }
}

int main()
{
    int numbers1[] = {1,4,5,8};
    int numbers2[] = {2,3,6,7};

    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);
    int size3 = size1 + size2;
    int numbers3[size3];

    merge(numbers1, numbers2, numbers3, size1, size2);

    for (int k=0; k<size3; k++){
        cout<<numbers3[k]<<"-";
    }
    return 0;
}
