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
            if (pattern_counter >= len_pattern) { // * 뒤에는 항상 문자가 있어야 한다(조건임)
               cout << "X" << endl;
               break;
            }
            char next_pattern = pattern[pattern_counter];

            if (next_pattern == '*') {  // **인 경우, **랑 *는 같으므로 다음 *로 그냥 넘어간다.
               pattern_counter += 1;
               continue;
            }
            else if ('a' <= next_pattern && next_pattern <= 'z') {   // *a 인 경우, aaaa가 더이상 안나올떄까지 값검색
               while (value_counter < len_value && value[value_counter] == next_pattern)
                  value_counter += 1;
            }
            else if (next_pattern == '?') {         // *???abc 인 경우, pattern에서 순수한 문자('a ~ 'z')가 나올 떄까지 패턴검색. 발견 못하면 모든 경우 다 가능한거 개이득. 발견 하면 발견한 value까지 value_counter 넘겨 주기.
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
                  continue;  // 넘어가서 a == a가 되도록.
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