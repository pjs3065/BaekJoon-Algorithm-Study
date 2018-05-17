#include <string>
#include <iostream>

using namespace std;

int main()
{
   int T, len_pattern, len_value;
   string pattern, value;

   cin >> T;
   if (T < 0) return 0;

   for (int i = 1; i <= T; i++)
   {
      int pattern_counter = 0, value_counter = 0;
      
	  cin >> pattern;
      cin >> value;

      len_pattern = pattern.length();
      len_value = value.length();

      while (pattern_counter < len_pattern || value_counter < len_value)
      {
         char temp = pattern[pattern_counter];
         if ('a' <= temp && temp <= 'z') {
            if (value[value_counter] == temp)
               value_counter++;
            else {
               cout << "X" << endl;
               break;
            }
         }
         else if (temp == '?') {
            if (value_counter + 1 < len_value)
               value_counter++;
            else {
               cout << "X" << endl;
               break;
            }
         }
         else if (temp == '*') {
            pattern_counter += 1;
            if (pattern_counter >= len_pattern) { // * �ڿ��� �׻� ���ڰ� �־�� �Ѵ�(������)
               cout << "X" << endl;
               break;
            }
            char next_pattern = pattern[pattern_counter];

            if (next_pattern == '*') {  // **�� ���, **�� *�� �����Ƿ� ���� *�� �׳� �Ѿ��.
               pattern_counter += 1;
               continue;
            }
            else if ('a' <= next_pattern && next_pattern <= 'z') {   // *a �� ���, aaaa�� ���̻� �ȳ��Ë����� ���˻�
               while (value_counter < len_value && value[value_counter] == next_pattern)
                  value_counter += 1;
            }
            else if (next_pattern == '?') {         // *???abc �� ���, pattern���� ������ ����('a ~ 'z')�� ���� ������ ���ϰ˻�. �߰� ���ϸ� ��� ��� �� �����Ѱ� ���̵�. �߰� �ϸ� �߰��� value���� value_counter �Ѱ� �ֱ�.
               while (pattern_counter < len_pattern && !(pattern[pattern_counter] >= 'a' && pattern[pattern_counter] <= 'z'))
                  pattern_counter += 1;
               if (pattern_counter == len_pattern) {
                  cout << "O" << endl;
                  break;
               }
               else {
                  char end_value = pattern[pattern_counter];
                  while (value_counter < len_value && value[value_counter] != end_value)
                     value_counter += 1;
                  continue;  // �Ѿ�� a == a�� �ǵ���.
               }
            }
         }
         pattern_counter += 1;
      }
      if (pattern_counter == len_pattern && value_counter == len_value)
         cout << "O" << endl;
   }
    return 0;
}