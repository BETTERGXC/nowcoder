/*
小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，
于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，
例如字符串ABCABCABC将会被压缩为[3|ABC]，
现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？
*/ 
#include <iostream>
#include <string>
using namespace std;

int main() {
      string s;
      cin >> s;
      int i = 0;
      while (i < s.length()) {
            if (s[i] == ']') {
                  int j = i;//j用来向前寻找与]相匹配的[
                  int k = 0;//k用来记录'|'所在位置
                  while (s[j] != '[') {
                        if (s[j] == '|')
                              k = j;
                        j--;
                  }
                  int len = stoi(s.substr(j + 1, k - j));
                  string s1 = s.substr(k + 1, i - k - 1);
                  string s2;
                  for (int si = 0; si < len; si++) {//将识别到的括号内容进行解码
                        s2 += s1;
                  }
                  s = s.replace(j, i - j + 1, s2);
                  i = j;//替换后i所指向的内容变化，从替换部分的头开始再寻找
            }
            i++;
      }
      cout << s << endl;
}
 
