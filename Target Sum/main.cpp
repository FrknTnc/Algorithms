#include <iostream>
#include <unordered_map>
using namespace std;

void findPair(int nums[], int arrSize, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < arrSize; i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            cout << "Pair found (" << nums[map[target - nums[i]]] << ", " << nums[i] << ")\n";
            return;
        }
        map[nums[i]] = i;
    }
    cout << "Pair not found";
}

int main()
{
    int arr[] = { 3, 1, 15, 8, 4, 12 };
    int target = 27;

    int arrSize = sizeof(arr)/sizeof(arr[0]);

    findPair(arr, arrSize, target);

    return 0;
}
