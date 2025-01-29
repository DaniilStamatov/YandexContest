#include <iostream>
#include <vector>
std::string lexicographical_compare(const std::string &first,
                                    const std::string &second);
int main() {
  int R, C;
  std::cin >> R >> C;
  std::vector<std::vector<char>> grid(R, std::vector<char>(C));
  std::string line = "";
  for (int i = 0; i < R; ++i) {
    std::cin >> line;
    for (int j = 0; j < C; ++j) {
      grid[i][j] = line[j];
    }
  }

  std::string min_word = "";
  for (int i = 0; i < R; ++i) {
    std::string temp_word = "";
    for (int j = 0; j < C; ++j) {
      if (grid[i][j] != '#') {
        temp_word += grid[i][j];
      } else {
        min_word = lexicographical_compare(min_word, temp_word);
        temp_word.clear();
      }
    }
    min_word = lexicographical_compare(min_word, temp_word);
  }

  for (int j = 0; j < C; ++j) {
    std::string temp_word = "";
    for (int i = 0; i < R; ++i) {
      if (grid[i][j] != '#') {
        temp_word += grid[i][j];
      } else {
        min_word = lexicographical_compare(min_word, temp_word);
        temp_word.clear();
      }
    }
    min_word = lexicographical_compare(min_word, temp_word);
  }

  std::cout << min_word << std::endl;
}

std::string lexicographical_compare(const std::string &first,
                                    const std::string &second) {
  if (first.length() < 2) {
    return second.length() >= 2 ? second : "";
  }
  if (second.length() < 2) {
    return first;
  }
  return first < second ? first : second;
}
