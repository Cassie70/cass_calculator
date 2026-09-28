#include "lexer.hpp"
#include "tokenType.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <print>
#include <string>

void Lexer::nextState(State next) {
  state = next;
  lexeme += c;
}

void Lexer::addToken(TokenType tt) {
  std::println("{} -> {}", TokenTypeToString(tt), lexeme);
  tokens.emplace_back(lexeme, tt);
  lexeme.clear();
  state = State::READ_CHAR;
}

void Lexer::tokenize(const char c) {
  this->c = c;
  switch (state) {
  case State::READ_CHAR: {

    if (std::ranges::contains(ws, c)) {
      return;
    }

    auto it = symbols.find(c);

    if (it != symbols.end()) {
      nextState(State::READ_CHAR);
      addToken(it->second);
      return;
    }

    if (isdigit(c)) {
      nextState(State::NUMBER);
    } else if (c == '\\') {
      nextState(State::RESERVED_WORD);
    } else if (c == 'e') {
      nextState(State::READ_CHAR);
      addToken(TokenType::E);
    }

    break;
  }

  case State::NUMBER: {
    if (isdigit(c)) {
      nextState(State::NUMBER);
    } else if (c == '.') {
      nextState(State::NUMBER_FLOAT);
    } else {
      addToken(TokenType::NUMBER);
      tokenize(c);
    }
    break;
  }

  case State::NUMBER_FLOAT: {

    if (isdigit(c)) {
      nextState(State::NUMBER_FLOAT);
    } else {
      addToken(TokenType::NUMBER);
      tokenize(c);
    }
    break;
  }

  case State::RESERVED_WORD: {
    if (isalpha(c)) {
      nextState(State::RESERVED_WORD);
    } else {
      auto it = reserved.find(lexeme);
      if (it != reserved.end()) {
        addToken(it->second);
      } else {
        std::cerr << "Invalid Reserved Word" << std::endl;
        nextState(State::READ_CHAR);
      }

      tokenize(c);
    }
    break;
  }
  }
}

void Lexer::end() {
  switch (state) {
  case State::NUMBER:
  case State::NUMBER_FLOAT:
    addToken(TokenType::NUMBER);
    break;

  case State::RESERVED_WORD: {
    auto it = reserved.find(lexeme);
    if (it != reserved.end()) {
      addToken(it->second);
    }
    break;
  }

  default:
    break;
  }
}