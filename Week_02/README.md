学习笔记

# Hash

通过将数据（val）变成关键码值key，进而可以直接访问数据（val）的数据结构。散列函数。

这里的数据，不仅仅是数字。



> ## hash碰撞  
>
> hash碰撞：不同的val对应到相同的码值key。
>
> *解决方法：*
>
> * 拉链法
>
>   将相同key的val依次排列，即在一个key的后面，添加一个链表。
>
> * 线性探测法
>
>   在hash表中向下寻找空位，要求hash表的大小>数据的大小。

> ## map和set区别和实现（C++）
>
> * set 
>
>   不重复元素的集合
>
> |        集合        | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询复杂度 | 增删复杂度 |
> | :----------------: | :------: | :------: | :--------------: | :----------: | :--------: | :--------: |
> |      std::set      |  红黑树  |   有序   |        否        |      否      |  O(logn)   |  O(logn)   |
> |   std::multiset    |  红黑树  |   有序   |        是        |      否      |  O(logn)   |  O(logn)   |
> | std::unordered_set |  哈希表  |   无序   |        是        |      否      |    O(1)    |   O(1）    |
>
> * map
>
>   key-value对，key不重复
>
> |        映射        | 底层实现 | 是否有序 | 数值是否可以重复 | 能否更改数值 | 查询复杂度 | 增删复杂度 |
> | :----------------: | :------: | :------: | :--------------: | :----------: | :--------: | :--------: |
> |      std::map      |  红黑树  | key有序  |   key不可重复    | key不可修改  |  O(logn)   |  O(logn)   |
> |   std::multimap    |  红黑树  | keye有序 |    key可重复     | key不可修改  |  O(logn)   |  O(logn)   |
> | std::unordered_map |  哈希表  | key无序  |   key不可重复    | key不可修改  |    O(1)    |   O(1）    |
>
> 表格引用自：https://mp.weixin.qq.com/s/g8N6WmoQmsCUw3_BaWxHZA

> ### std::unordered_map和std::map的常见用法
>
> * unordered_map
>
>   | 成员函数  | 功能                                         | 备注                                                         |
>   | --------- | -------------------------------------------- | ------------------------------------------------------------ |
>   | at        | 返回指定value的key                           |                                                              |
>   | begin/end | 返回第一个/最后一个unordered_map容器         | 一般在迭代种用到覆盖整个map                                  |
>   | clear     | 清空                                         |                                                              |
>   | empty     | 空则返回true，其他返回false                  |                                                              |
>   | erase     | 删除某个元素或者一个范围                     | 可以通过key删除；可以通过begin（）即迭代器删除；也可以输入两个参数（const_iterator first, const_iterator last），删除first到last-1 |
>   | find      | 查找                                         |                                                              |
>   | count     | 判断是否有此key，有则返回1，无则返回0        |                                                              |
>   | insert    | 插入单个map或者某个map的某些maps或者一个list | myrecipe.insert (myshopping);                           // copy insertion   myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion   myrecipe.insert (mypantry.begin(), mypantry.end());                  //range insertion   myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );                                 // initializer list insertion |
>   | size      | 返回map大小                                  |                                                              |












