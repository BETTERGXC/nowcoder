/*
	M��С����Χ��һ��Ȧ���ȭ��Ϸ��ÿ��С����ֻ���ʯͷ���Ӳ�
	1����ǰ���С���ѻ��˳ʱ�뷽����һ��С���Ѳ�ȭ
	2�������ǰ���С����ʤ��������ս�����ڵ����С���ѻ��Ȧ��̭����ǰ���С���Ѽ���ִ�� 1
	3�������ǰ���С���ʧ�ܣ����С���ѳ�Ȧ��̭���ɱ���ս��С���ѳ�Ϊ�µ�С����
	4��ƽ��������̭����һ��С���ѿ�ʼ
	Rʯͷ S���� C�� 
*/ 

/*
	����������
	3
	5 5
	RRRRR
	3 2
	RSC
	3 1
	RRC 
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
      int T;
      cin >> T;
      while (T--) {
            int N, M;
            cin >> N >> M;
            string input;
            cin >> input;
            vector<int> count(input.size(), 1);
            for (int i = 1; i < input.size(); i++) {
                  if (input[i] == input[i - 1]) {
                        count[i] = count[i - 1] + 1;
                  }
            }
            int index = 0;
            for (int i = 1; i < count.size(); i++) {
                  if (count[i] > count[index]) {
                        index = i;
                  }
            }
            index = count[index] - index - 1;
            while (M--) {
                  int flag = 0;
                  if (index + 1 < input.size()) {
                        if ((input[index] == 'R' && input[index + 1] == 'S') || (input[index] == 'S' && input[index + 1] == 'C') ||
                              (input[index] == 'C' && input[index+1] == 'R')) {
                              input.erase(input.begin() + index);
                              flag = 1;
                        }
                  }
                  else {
                        if ((input[index] == 'R' && input[0] == 'S') || (input[index] == 'S' && input[0] == 'C') ||
                              (input[index] == 'C' && input[0] == 'R')) {
                              input.erase(input.begin());
                              flag = 1;
                        }
                  }
                  
                  if (flag == 0) {
                        if (index >= input.size()) {
                              index = 0;
                        }
                        else {
                              index++;
                        }
                  }
            }
            cout << input.size() << endl;
      }
}
