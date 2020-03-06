#include <bits/stdc++.h>
using namespace std;

//Sorting algorithms
//Given an array, sort the array

//Comparision vs non comparision based sorting algorithms

//O(n*n) sorting algorithms
//Inversions : i < j , A[i] > A[j]
//Max Inversions will be for desc array  = 1+2+3....n-1 = n(n-1)/2
//O(n*n) time complexity to correct all inversions

//Bubble Sort

void BubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < nums.size() - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

//Selection Sort
//Select the largest element and put it in the end
void SelectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int minIndex = i;
        for (int j = i; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIndex])
                minIndex = j;
        }
        swap(nums[minIndex], nums[i]);
    }
}

//Insertion Sort
void InsertionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 and nums[j + 1] < nums[j])
        {
            swap(nums[j], nums[j + 1]);
            j--;
        }
    }
}

//lower(nlogn) algorithms

//Merge Sort
//dividing array into two parts

void Merge(vector<int> &nums, int start, int mid, int end)
{
    //subarray 1 : start to mid
    //subarray 2 : mid+1 to end
    //Auxillary array is required
    vector<int> auxillary(end - start + 1);
    int p = start, q = mid + 1;
    for (int i = start; i <= end; i++)
    {
        //check if any subarray has ended
        if (p > mid)
            auxillary[i] = nums[q++];
        else if (q > end)
            auxillary[i] = nums[p++];
        else if (nums[p] < nums[q])
            auxillary[i] = nums[p++];
        else
            auxillary[i] = nums[q++];
    }

    for (int i = start; i <= end; i++)
        nums[i] = auxillary[i];
}

void MergeSort(vector<int> &nums, int start, int end)
{
    if (start < end)
    {
        int mid = (end - start) / 2 + start;
        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        Merge(nums, start, mid, end);
    }
}
//Quick Sort

int partition(vector<int> &nums, int start, int end, int pivotIdx)
{
    int new_pivotIdx = start;
    int pivotVal = nums[pivotIdx];
    swap(nums[pivotIdx], nums[end]);
    for (int i = start; i < end; i++)
    {
        if (nums[i] < pivotVal)
            swap(nums[new_pivotIdx++], nums[i]);
    }
    swap(nums[end], nums[new_pivotIdx]);
}

default_random_engine gen((random_device())());

void QuickSort(vector<int> &nums, int start, int end)
{
    //run partition for every element
    if (start <= end)
    {
        int pivotIdx = uniform_int_distribution<int>{start, end}(gen);
        int new_pivotIdx = partition(nums, start, end, pivotIdx);
        QuickSort(nums, start, pivotIdx - 1);
        QuickSort(nums, pivotIdx + 1, end);
    }
}

//Heap Sort

void HeapSort(vector<int> &nums)
{
    priority_queue<int> maxheap;
    for (auto i : nums)
        maxheap.push(i);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        nums[i] = maxheap.top();
        maxheap.pop();
    }
}

//lower(n) algorithms
//Not comaparision based, lower bound is O(nlogn) for comparision ones are proved using decision tree
//Counting Sort
//Drawback :  auxillary size needs to be equal to the max element in the array, negative numbers are also a problem
//Time ; O(n) Space : O(n+k) range of elements is 1 to k

vector<int> CountingSort(vector<int> &nums)
{
    vector<int> output(nums.size());
    const int range = 25;
    vector<int> count(range, 0);
    //get counts of elements in array
    for (int i = 0; i < nums.size(); i++)
        count[nums[i]]++;

    //add count array so as to get proper indexes
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    //get sorted values
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     output[count[nums[i]] - 1] = nums[i];
    //     count[nums[i]]--;
    // }

    //stable sort
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        output[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    return output;
}

//Radix Sort
//Uses counting sort as a subroutine
//counting sort from LSB to MSB
//do digit by digit counting sort
//deals with the drawback of counting sort as auxillary array is bounded

int getMax(vector<int> &arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(vector<int> &arr, int n, int exp)
{
    vector<int> output(n);
    vector<int> count(10, 0);

    //fill the count array
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    //add elements in count to get indexes
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    //fill the output array, stable
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //copy to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort(vector<int> &arr, int n)
{
    //Find max to get number of digits
    int m = getMax(arr, n);
    //Do counting sort for every digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void BucketSort()
{
}

int main()
{
    vector<int> nums({4, 3, 2, 1, 5});
    RadixSort(nums, 5);
    for (auto i : nums)
        cout << i << " ";
}