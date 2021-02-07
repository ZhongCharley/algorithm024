#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[],int start, int end){
    // 建立父节点>子节点的关系
    int dad = start;
    int son = dad*2+1;
    while(son<=end){
        if(son+1<=end&&arr[son]<arr[son+1]) // 先比较两个子节点大小，选择最大的
            son++;
        if(arr[dad]>arr[son])
            return;
        else {
            swap(arr[dad],arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}

void heap_sort(int arr[],int len){
    // 初始化，得到最大值，并放到堆顶
    for(int i=len/2-1;i >= 0; i--)
        max_heapify(arr,i,len-1);
    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整，直到排序完毕
    for(int i=len-1;i>0;i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i-1);
    }
}

int main(){
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}