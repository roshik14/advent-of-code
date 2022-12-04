#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int CalculateFirstPart(int length, int width, int height) {
  auto first_square = length * width;
  auto second_square = width * height;
  auto third_square = height * length;
  auto min = std::min({first_square, second_square, third_square});
  return 2 * first_square + 2 * second_square + 2 * third_square + min;
}

int CalculateSecondPart(int length, int width, int height) {
  auto firstPerimeter = 2 * (length + width);
  auto secondPerimeter = 2 * (width + height);
  auto thirdPerimeter = 2 * (height + length);
  auto volume = length * width * height;
  return std::min({firstPerimeter, secondPerimeter, thirdPerimeter})
    + volume;
}

int ReadNumber(const std::string &str, size_t *pos) {
  size_t offset = 0;
  auto result = std::stoi(str, &offset);
  *pos += offset + 1;
  return result;
}

void ParseNumbers(const std::string &str, int *length, int *width, int *height) {
  size_t pos = 0;
  *length = ReadNumber(str, &pos);
  *width = ReadNumber(str.substr(pos), &pos);
  *height = ReadNumber(str.substr(pos), &pos);
}

int Solution(const std::vector<std::string> &expressions, int(*Calc)(int,int,int)) {
  auto length = 0, width = 0, height = 0;
  auto result = 0;
  for (size_t i = 0, sz = expressions.size(); i != sz; ++i) {
    ParseNumbers(expressions[i], &length, &width, &height);
    result += Calc(length, width, height);
  }
  return result;
}

int main() {
  std::string s;
  std::vector<std::string> v;
  std::ifstream input_stream("test.txt");
  while (std::getline(input_stream, s)) {
    v.push_back(s);
  }
  std::cout << "First part result is = " << Solution(v, &CalculateFirstPart) << '\n';
  std::cout << "Second part result is = " << Solution(v, &CalculateSecondPart) << '\n';
}
