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


//  ���еĽⷨ
#include <iostream>
#include <string>
using namespace std;

int main() {
      string s;
      cin >> s;
      int i = 0;
      while (i < s.length()) {
            if (s[i] == ']') {
                  int j = i;//j������ǰѰ����]��ƥ���[
                  int k = 0;//k������¼'|'����λ��
                  while (s[j] != '[') {
                        if (s[j] == '|')
                              k = j;
                        j--;
                  }
                  int len = stoi(s.substr(j + 1, k - j));
                  string s1 = s.substr(k + 1, i - k - 1);
                  string s2;
                  for (int si = 0; si < len; si++) {//��ʶ�𵽵��������ݽ��н���
                        s2 += s1;
                  }
                  s = s.replace(j, i - j + 1, s2);
                  i = j;//�滻��i��ָ������ݱ仯�����滻���ֵ�ͷ��ʼ��Ѱ��
            }
            i++;
      }
      cout << s << endl;
}
 
