#include <iostream>
#include <fstream>

int first_part(const std::string &str) {
  auto result = 0;
  for (auto &c : str) {
    if (c == '(')
      result++;
    if (c == ')')
      result--;
  }
  return result;
}

int second_part(const std::string &str) {
  auto count = 0;
  for (size_t i = 0, sz = str.size(); i != sz; ++i) {
    if (str[i] == '(')
      count++;
    if (str[i] == ')')
      count--;
    if (count == -1)
      return i + 1;
  }
  return 0;
}

int main() {
  std::string s;
  std::ifstream input_stream("test.txt");
  if (input_stream.is_open()) {
    std::getline(input_stream, s);
  }
  std::cout << first_part(s) << '\n';
  std::cout << second_part(s) << '\n';
}
