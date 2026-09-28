#pragma once
#include "token.hpp"
#include "tokenType.hpp"
#include <array>
#include <map>
#include <string>
#include <vector>

class Lexer {
private:
  enum class State { READ_CHAR, NUMBER, NUMBER_FLOAT, RESERVED_WORD };

  inline static const std::array ws = {' ', '\n', '\t', '\r'};
  inline static const std::map<char, TokenType> symbols = {
    {'+', TokenType::PLUS},        {'-', TokenType::MINUS},
    {'.', TokenType::DOT},         {'*', TokenType::STAR},
    {'^', TokenType::CARET},       {'!', TokenType::BANG},
    {'{', TokenType::LEFT_BRACE},  {'}', TokenType::RIGHT_BRACE},
    {'(', TokenType::LEFT_PARENT}, {')', TokenType::RIGHT_PARENT},
  };
  inline static const std::map<std::string, TokenType> reserved = {
    {"\\frac", TokenType::FRAC}, {"\\sqrt", TokenType::SQRT},
    {"\\sin", TokenType::SIN},   {"\\cos", TokenType::COS},
    {"\\tan", TokenType::TAN},   {"\\ln", TokenType::LN},
    {"\\log", TokenType::LOG},   {"\\pi", TokenType::PI},
    {"e", TokenType::E}
  };

  std::vector<Token> tokens;
  State state = State::READ_CHAR;
  std::string lexeme = "";
  char c;

public:
  Lexer() = default;
  void tokenize(const char c);
  void nextState(State next);
  void addToken(TokenType tt);
  void end();
};