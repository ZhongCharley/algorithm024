//使用数组实现双端队列，head==tail的时候，队列为空，tail+1=head的时候，队列full
class MyCircularDeque {
public:
    vector<int> data;
    int capacity;
    int head;//指向队列的首元素
    int tail;//指向队列最后一个元素的下一位
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k + 1;
        //需初始化k+1个值
        while (k-- > -1) data.emplace_back(0);
        head = 0;
        tail = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + capacity) % capacity;
        data[head] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[tail] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        tail = (tail - 1 + capacity) % capacity;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty() ? -1 : data[head];
    }

    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : data[(tail - 1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == tail;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (tail + 1) % capacity == head;
    }
};