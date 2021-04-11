# KMP算法

### 解决的问题

加速字符串匹配

### 原理

该算法主要有两个关键点：

* 构建前缀表（next数组）：

  按顺序构建模板串的最长前后缀和

  比如：模板串为： ”ABAABC“

  将模板串按金字塔的顺序排列：

  ​	A

  ​	A	B

  ​	A	B	A	

  ​	A	B	A	A

  ​	A	B	A	A	B
  
  ​	A	B	A	A	B	C


  计算最长前后缀和：

  0	A

  0	A	B

  1	A	B	A	

  1	A	B	A	A

  2	A	B	A	A	B

  0	A	B	A	A	B	C

  左侧数字为各个层级的最长公共前后缀。

  所以有前缀表为[0 0 1 1 2 0]；

  为了方便后续处理，将表向后移动一位，并且首位置为 - 1.

  因此前缀表为[-1 0 0 1 1 2]

如果失配，但是此时部分前缀和仍然存在对称性

![image-20210406225620949](C:\Users\zy\AppData\Roaming\Typora\typora-user-images\image-20210406225620949.png)



* kmp搜索
  
  根据暴力搜索，模板串应该对着搜索串挨个移位。
  
  但是有了前缀表，当遇到不一样的字符的时候，可以根据前缀表跳过重复区域。
  
  双指针，一个指针i指向搜索串，一个指针j指向模板串
  
  比如：
  模板串为 ”AAAB“, 对应前缀表为[-1 0 1 2]
  搜索串为"AAAAAB"
  
  | S:      | A    | A    | A    | A    | A    | B    |
  | ------- | ---- | ---- | ---- | ---- | ---- | ---- |
  | N:      | 0    | 1    | 2    | 3    |      |      |
  | P:      | A    | A    | A    | B    |      |      |
  | Prefix: | -1   | 0    | 1    | 2    |      |      |
  
  此时模板串第4个字符不匹配
  那么根据前缀表第二个字符对应的为2，所以将第2个字符移动到当前位进行比较
  
  | S:      | A    | A    | A    | A    | A    | B    |
  | ------- | ---- | ---- | ---- | ---- | ---- | ---- |
  | N:      |      | 0    | 1    | 2    |      |      |
  | P:      |      | A    | A    | A    |      |      |
  | Prefix: |      | -1   | 0    | 1    |      |      |
  
  此时匹配，两个指针同时向后再走一步
  
  | S:      | A    | A    | A    | A    | A    | B    |
  | ------- | ---- | ---- | ---- | ---- | ---- | ---- |
  | N:      |      | 0    | 1    | 2    | 3    |      |
  | P:      |      | A    | A    | A    | B    |      |
  | Prefix: |      | -1   | 0    | 1    | 2    |      |
  
  不匹配，根据前缀表，移动指针，最终找到匹配位置。



## 代码

```c++
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//得到最长公共前后缀表
void prefix_table(string& pattern, vector<int>& prefix, int n) {
	prefix.push_back(0);
	int len = 0; //前缀和
	int i = 1; //检测第i个字母 
	while(i < n) {
		//对应一样，为前缀和
		if ( pattern[i] == pattern[len] ) {
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			//不一样，回溯回退的位置始终是模式串的不适配字符的上一位字符前后缀相同的位置，虽然当前不一样，但是前面是一样的
			if (len > 0) {
				len = prefix[len - 1];
			}
			else {
				//为了不越界
				prefix[i] = len;
				i++;
			}
		}
	}
}

//预处理：第一个为-1，其他的往后退一格
void move_prefix_table(vector<int>& prefix, int n) {
	for (int i = n - 1; i > 0; i--) {
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}

void kmp_search(string& text, string& pattern) {
	int n = pattern.size();
	vector<int> prefix(n);
	prefix_table(pattern, prefix, n);
	move_prefix_table(prefix, n);

	//text[i] m
	//pattern[j] n
	int i = 0, j = 0, m = text.size();
	while (i < m) {
		//循环终止条件，找到子串
		if (j == n - 1 && text[i] == pattern[j]) {
			cout << "Found pattern at " << i - j << endl;
			j = prefix[j];
            if (j == -1) {
                i++;
                j++;
                continue;
            }
		}
		//处理当前逻辑，如果相同那么两个指针往后走
		if (text[i] == pattern[j]) {
			i++;
			j++;
		} 
		else {
			//如果不同，将子串的指针指向当前指针所对应的前缀表上
			j = prefix[j];
			//如果是前缀表第一个，那么重新开始
			if (j == -1) {
				i++;
				j++;
			}
		}
	}
}

int main() {
	string pattern = "ababcabaa";
	string text = "abababcabaaasfd";
	kmp_search(text, pattern);
	return 0;
} 
```

  

# 参考文献：

* https://www.bilibili.com/video/BV1hW411a7ys/?spm_id_from=333.788.videocard.0
* http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
* https://www.zhihu.com/question/21923021/answer/1032665486





