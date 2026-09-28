#pragma once

#include <string>

enum class TokenType {
  PLUS,
  MINUS,
  DOT,
  NUMBER,
  STAR,
  CARET,
  BANG,
  LEFT_BRACE,
  RIGHT_BRACE,
  LEFT_PARENT,
  RIGHT_PARENT,
  FRAC,
  SQRT,
  SIN,
  COS,
  TAN,
  LN,
  LOG,
  PI,
  E
};

inline std::string TokenTypeToString(TokenType tt) {
  switch (tt) {
  case TokenType::PLUS:
    return "PLUS";
  case TokenType::MINUS:
    return "MINUS";
  case TokenType::DOT:
    return "DOT";
  case TokenType::NUMBER:
    return "NUMBER";
  case TokenType::STAR:
    return "STAR";
  case TokenType::CARET:
    return "CARET";
  case TokenType::BANG:
    return "BANG";
  case TokenType::LEFT_BRACE:
    return "LEFT_BRACE";
  case TokenType::RIGHT_BRACE:
    return "RIGHT_BRACE";
  case TokenType::LEFT_PARENT:
    return "LEFT_PARENT";
  case TokenType::RIGHT_PARENT:
    return "RIGHT_PARENT";
  case TokenType::FRAC:
    return "FRAC";
  case TokenType::SQRT:
    return "SQRT";
  case TokenType::SIN:
    return "SIN";
  case TokenType::COS:
    return "COS";
  case TokenType::TAN:
    return "TAN";
  case TokenType::LN:
    return "LN";
  case TokenType::LOG:
    return "LOG";
  case TokenType::PI:
    return "PI";
  case TokenType::E:
    return "E";
  }

  return "UNKNOWN";
}