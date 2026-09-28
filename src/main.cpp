#include "lexer.hpp"
#include <print>
#include <string>

int main() {
  std::string input = R"(\sin(\pi*2))";
  std::println("hola cara de bola");
  Lexer lexer;
  for (const char c : input) {
    lexer.tokenize(c);
  }
  lexer.end();
  return 0;
}