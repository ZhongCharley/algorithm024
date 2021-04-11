#include <string>
#include <iostream>
#include <vector>
using namespace std;

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
//第一个为-1，其他的往后退一格
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
	string pattern = "a";
	string text = "abababcabaaasfd";
	kmp_search(text, pattern);
	/*
	for ( int i = 0; i < n; i++) {
		cout << prefix[i] << endl;
	}
	*/
	return 0;
} 
