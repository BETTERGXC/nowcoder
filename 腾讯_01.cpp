/*
СQ����ĩ��ʱ�������С�����������й�֣�
һ�����н����кܶ��¥������n����¥�ų�һ�С�
СQ�ӵ�һ��һֱ�ߵ������һ����СQ������û�м�����ô���¥��
��������֪������ÿ��¥��λ�ô��ܿ������ٶ�¥�أ�
����ǰ���¥�ĸ߶ȴ��ڵ��ں����¥ʱ�������¥������ס�� 
*/

// ʾ�� 
/*
���� 
6
5 3 8 3 2 5

���
3 3 5 4 4 4 
*/

// �������н��  ����ʱ��ʱ�临�Ӷȹ��� 

#include <iostream>
#include <vector>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<int> input(n);
      vector<int> output(n);
      for (int i = 0; i < n; i++) {
            cin >> input[i];
      }
      for (int i = 0; i < n; i++) {
            int maxleft = -1;
            int sumleft = 0;
            int maxright = -1;
            int sumright = 0;
            for (int j = i; j < n-1; j++) {
                  if (maxright < input[j + 1]) {
                        sumright++;
                        maxright = input[j + 1];
                  }
            }
            for (int j = i; j > 0; j--) {
                  if (maxleft < input[j - 1]) {
                        sumleft++;
                        maxleft = input[j - 1];
                  }
            }
            output[i] = sumleft + sumright + 1;
      }
      for (int i = 0; i < n; i++) {
            cout << output[i] << " ";
      }
      cout << endl;
}
