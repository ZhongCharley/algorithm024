#include <string>
#include <iostream>
#include <vector>
using namespace std;

void prefix_table(string& pattern, vector<int>& prefix, int n) {
	prefix.push_back(0);
	int len = 0; //ǰ׺��
	int i = 1; //����i����ĸ 
	while(i < n) {
		//��Ӧһ����Ϊǰ׺��
		if ( pattern[i] == pattern[len] ) {
			len++;
			prefix[i] = len;
			i++;
		}
		else {
			//��һ�������ݻ��˵�λ��ʼ����ģʽ���Ĳ������ַ�����һλ�ַ�ǰ��׺��ͬ��λ�ã���Ȼ��ǰ��һ��������ǰ����һ����
			if (len > 0) {
				len = prefix[len - 1];
			}
			else {
				//Ϊ�˲�Խ��
				prefix[i] = len;
				i++;
			}
		}
	}
}
//��һ��Ϊ-1��������������һ��
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
		//ѭ����ֹ�������ҵ��Ӵ�
		if (j == n - 1 && text[i] == pattern[j]) {
			cout << "Found pattern at " << i - j << endl;
			j = prefix[j];
			if (j == -1) {
				i++;
				j++;
				continue;
			} 
		}
		//����ǰ�߼��������ͬ��ô����ָ��������
		if (text[i] == pattern[j]) {
			i++;
			j++;
		} 
		else {
			//�����ͬ�����Ӵ���ָ��ָ��ǰָ������Ӧ��ǰ׺����
			j = prefix[j];
			//�����ǰ׺���һ������ô���¿�ʼ
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
