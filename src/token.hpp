#pragma once
#include "tokenType.hpp"
#include <string>

struct Token {

  std::string lexeme;
  TokenType type;
};