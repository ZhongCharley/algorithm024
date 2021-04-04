学习笔记

# 十大排序算法

## 总览

|   排序方法   | 时间复杂度（平均） | 时间复杂度（最坏） | 时间复杂度（最好） |  空间复杂度  | 稳定性 |
| :----------: | :----------------: | :----------------: | :----------------: | :----------: | :----: |
|  比较类排序  |                    |                    |                    |              |        |
|   插入排序   |      $O(n^2)$      |      $O(n^2)$      |       $O(n)$       |    $O(1)$    |  稳定  |
|   希尔排序   |    $O(n^{1,3})$    |      $O(n^2)$      |       $O(n)$       |    $O(1)$    | 不稳定 |
|   选择排序   |      $O(n^2)$      |      $O(n^2)$      |      $O(n^2)$      |    $O(1)$    | 不稳定 |
|   冒泡排序   |      $O(n^2)$      |      $O(n^2)$      |       $O(n)$       |    $O(1)$    |  稳定  |
|    堆排序    |    $O(nlog_2n)$    |    $O(nlog_2n)$    |    $O(nlog_2n)$    |    $O(1)$    | 不稳定 |
|   快速排序   |    $O(nlog_2n)$    |      $O(n^2)$      |    $O(nlog_2n)$    | $O(nlog_2n)$ | 不稳定 |
|   归并排序   |    $O(nlog_2n)$    |    $O(nlog_2n)$    |    $O(nlog_2n)$    |    $O(n)$    |  稳定  |
| 非比较类排序 |                    |                    |                    |              |        |
|   计数排序   |      $O(n+k)$      |      $O(n+k)$      |      $O(n+k)$      |   $O(n+k)$   |  稳定  |
|    桶排序    |      $O(n+k)$      |      $O(n^2)$      |       $O(n)$       |   $O(n+k)$   |  稳定  |
|   基数排序   |      $O(n*k)$      |      $O(n*k)$      |      $O(n*k)$      |   $O(n+k)$   |  稳定  |

### 相关概念

* 比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破$O(nlogn)$，因此也称为非线性时间比较类排序。
* 非比骄傲类排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。
* 稳定：如果元素a在b前面，而$a = b$，排序之后a仍然在b的前面。
* 不稳定：如果元素a在b前面，而$a = b$，排序之后a可能在b的后面。



# 初级排序 - $O(N^2)$

## 冒泡排序（Bubble Sort）

* 原理：嵌套循环，每次查看相邻的元素如果逆序，则交换。(每一次操作都会将未排序序列的最大值往最后排)

```c++
void bubbleSort(vector<int>& arr) {
    int m = arr.size();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j],arr[j + 1]);
        }
    }
}
```

## 选择排序（Selection Sort）

* 原理：每次找最小值，然后放到待排序数组的起始位置

```c++
void selectionSort(vector<int>& arr) {
    int len = arr.size(), minIndex, temp;
    for (int i = 0; i < len - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < len; j++) {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

## 插入排序（Insert Sort）

* 原理：从前到后逐步构建有序序列；对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入

  ```c++
  void insertionSort(vector<int>& arr) {
      int len = arr.size(), preIndex, curValue;
      for (int i = 1; i < len; i++) {
          preIndex = i - 1;
          curValue = arr[i];
          while(preIndex >= 0 && arr[preIndex] > curValue) {
              arr[preIndex + 1] = arr[preIndex];
              preIndex--;
          }
          arr[preIndex + 1] = curValue;
      }
  }
  ```

#高级排序 - $O(N*log_2N)$

## 快速排序

* 原理：数组选取取标杆（pivot），将小元素放pivot左边，大元素放右边，然后依次对右边和右边的子数组继续快排，以达到整个序列有序。

```c++
int random_partition(vector<int>& nums, int l, int r) {
    int random_picot_index = rand() % (r - l + 1) + l; //随机选择pivot
    int pivot = nums[random_pivot_index];
    //先将pivot放在一边
    swap(nums[random_pivot_index], nums[r]);
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    int pivot_index = i + 1;
    swap(nums[pivot_index], nums[r]);
    return pivot_index;
}

void random_quicksort(vector<int>& nums, int l, int r) {
    if (l < r) {
        int pivot_index = random_partition(nums, l, r);
        //分治
        random_quicksort(nums, l, pivot_index - 1); 
        random_quicksort(nums, pivot_index + 1, r);
    }
}
```

### 分析

* 本质：分治法，将大规模的问题变为小规模的问题。但是问题是pivot如何选取，选取不好就可能会退化为$N^2$ 的时间复杂度。
* 解决方案：避免每次选取pivot都选取到靠边的元素，可以取最左边，最右边，和中间三个数中的数值在中间的数；含有大量重复数据的场景；选取两个基准数
* 时间复杂度分析：如果我们每次都恰好选择到中间大小的元素，那么就类似于二分查找，此时就是logN，每次递归比较都要比较N次，所以时间复杂度是NlogN.
* 适用场景：大数据量且不要求排序稳定的场景。

## 归并排序 （Merge Sort）

* 原理：采用分治的思想
  * 把长度为n的输入序列分成两个长度为$n/2$的子序列；
  * 对这两个子序列分别采用归并排序；
  * 将这个排序好的子序列合并成一个最终的排序序列。

```c++
void mergeSort(verctor<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l)/2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    
    merge(nums, left, mid, right);
}

void merge(vector<int>& nums, int l, int mid, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    
    while(i <= mid && j <= r) {
        tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while(i <= mid) tmp[k++] = nums[i++];
    while(j <= r) tmp[k++] = nums[j++];
    
    for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}
```

### 分析

* 归并排序也是采用分治法，将无序的数组变为有序。并且是高级排序里面唯一个稳定的算法。但是在同类算法中的空间复杂度为O（N）
* 适用场景：大数据量且期望要求排序稳定的场景。

## 堆排序（Heap Sort）

* 原理：
  * 数组元素依次建立大顶堆
  * 依次取堆顶元素，并删除
* 堆插入$O(logN)$，取最大/小值$O(1)$

```c++
//手写堆排
void heapify(vector<int>& array, int length,int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int largeset = i;
    
    if (left < length && array[left] > array[largest]) {
        largeset = left;
    }
    if (right < length && array[right] > array[largest]) {
        largeset = right;
    }
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(array, length, largest);
    }
    return;
}

void heapSort(vector<int>& array) {
    if (array.size() == 0) return;
    
    int length = array.size();
    for (int i = length / 2 - 1; i >= 0;)
        heapify(array, length, i);
   	for (int i = length - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
    return;
}
```

```c++
//使用库函数
void heap_sort(int& a[], int len) {
    priority_queue<int, vector<int>, greater<int> > q;
    
    for (int i = 0; i < len; i++) {
        q.push(a[i]);
    }
    
    for (int i = 0; i < len; i++) {
        a[i] = q.pop();
    }
}
```

### 分析

* 时间复杂度计算：本身是一个二叉树的结构，所以叶子结点和根结点比较，交换的复杂度时logN。并且我们需要访问每一个结点，所以总体的时间复杂度是NlogN。
* 在数据变动的情况下，堆的维护成本比较高

* 适用情况：从N个数中找最大/最小的k个元素；数据量大且流式输入的场景。
* 为什么快排比堆排块？
  * 堆排序它最后一个数会和堆顶元素对调，再让堆顶元素下沉到合适的位置，底部元素是比较小的下沉中会进行大量的近乎无效的比较，所以虽然堆排和快排都是NlogN，但是堆排的常系数更大。

# 非比较类排序

## 计数排序（Counting Sort）

* 原理：将输入的数据值转化为键存储在额外开辟的数组空间中；然后依次把计数大于1的填充原数组。
* 要求：输入的数据必须是有确定范围的整数。

```c++
void countingSort(vector<int>& arr, maxValue) {
    vector<int> temp(maxValue + 1, 0);
    int length = arr.size(), index = 0;
    
    for (int i = 0; i < length; i++) {
        temp[arr[i]]++;
    }
    
    for (int i = 0; i < temp.size(); i++) {
        while (temp[i] > 0) {
            arr[index++] = i;
            temp[i]--;
        }
    }
}
```

### 分析

* 适用范围比较窄。数列元素是整数，当数列最大值不是很大且比较集中时适用。
* 优化：
  * 数字不是从0开始，会存在空间浪费的问题：数列的最小值作为偏移量，以数列最大值-最小值+1作为统计数组的长度

## 桶排序（Bucket Sort）

* 原理：基于计数排序，假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序。
* 利用函数的映射关系，高效与否的关键在于这个映射函数的确定。

### 分析

* 性能远远好于比较算法。

* 适用范围：数据服从均匀分布的场景

## 基数排序（Radix Sort）

* 原理：按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。



参考文献：

[1] https://matpool.com/blog/5f35f028505b8f0011ae4875/

[2] https://www.cnblogs.com/onepixel/p/7674659.html











