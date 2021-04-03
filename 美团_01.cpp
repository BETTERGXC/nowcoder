/*
	优美字符串  比如 aabc  的优美字符串是
	' ' a a b c ab ac bc ab ac abc abc
	输入一个字符串  输出优美字符串的个数 
*/ 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> result;
vector<bool> visited(26, false);
string path;

void backTracking(string& input, int start) {
      result.push_back(path);
      if (start >= input.size()) {
            return;
      }
      for (int i = start; i < input.size(); i++) {
            if (!visited[input[i] - 'a']) {
                  visited[input[i] - 'a'] = true;
                  path += input[i];
                  backTracking(input, i+1);
                  path.pop_back();
                  visited[input[i] - 'a'] = false;
            }
            
      }
}

int main() {
      string input;
      cin >> input;
      backTracking(input, 0);
      cout << result.size();
}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> visited(26, false);


void backTracking(string& input, int start, int *count) {
      (*count)++;
      if (start >= input.size()) {
            return;
      }
      for (int i = start; i < input.size(); i++) {
            if (!visited[input[i] - 'a']) {
                  visited[input[i] - 'a'] = true;
                  backTracking(input, i + 1, count);
                  visited[input[i] - 'a'] = false;
            }

      }
}

int main() {
      string input;
      cin >> input;
      int count = 0;
      backTracking(input, 0, &count);
      count = count % 20210101;
      cout << count << endl;
}
