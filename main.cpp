//
// Created by Kylian Lee on 2021/06/22.
//

#include <iostream>

using namespace std;

int solution(int len, int dist, string s);

int main() {
  int caseNum;
  cin >> caseNum;
  for (int i = 0; i < caseNum; ++i) {
    int len, dist;
    string s;
    cin >> len >> dist >> s;
    cout << solution(len, dist, s) << endl;
  }
  return 0;
}

int solution(int len, int dist, string s){
  int answer = 0;
  for (int i = 0; i < len; ++i) {
    if(s[i] == '*') {
      s[i] = 'x';
      answer++;
      break;
    }
  }
  int j;
  for (j = len - 1; j >= 0 ; --j) {
    if(s[j] == '*') {
      s[j] = 'x';
      answer++;
      break;
    }
  }
  if(j == -1)
    return 1;
  int count = 0;
  int cand = -1;
  for (int i = 0; i < len; ++i) {
    if(i == j)
      break;
    count++;
    if(s[i] == 'x') {
      count = 0;
      continue;
    }
    if(s[i] == '*')
      cand = i;
    if((count == dist) && (cand != -1)) {
      s[cand] = 'x';
      answer++;
      i = cand;
      cand = -1;
      count = 0;
    }
  }
  return answer;
}