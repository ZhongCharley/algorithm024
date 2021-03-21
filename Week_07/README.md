学习笔记

# 双向BFS

~~~cpp
```cpp
void BFS (set<T>& begin,set<T>& temp, set<T>& visited, set<T>& library) {
    
}
void Bi_BFS (T start, T end, vector<T>& bank) {
    unordered_set<T> begin, end_s, visited;
    unordered_set<T> library(bank.begin(), bank.end());
    int ans = 1;
    
    if (library.find(end) == library.end()) return -1;
    begin.insert(start);
    end_s.insert(end);
    visited.insert(end); //如果library有删除，可以不要
    library.erase(end);
    
    while(!begin.empty() && !end_s.empty()) {
        if (begin.size() > end_s.size()) {
            swap(begin, end_s);
        }
        unordered_set<T> temp;
        BFS(begin, temp, visited, library);
        ans ++;
        begin = temp;
    }
    return -1;   
}

```
~~~

