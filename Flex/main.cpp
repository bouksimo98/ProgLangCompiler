#include "token.h"
#include <FlexLexer.h>
#include <iostream>
std::string *pStr = nullptr;

int main(int argc, char **argv) {
  FlexLexer *l = new yyFlexLexer(std::cin, std::cerr);
  // l->yylex();
  while (token::token_t tok = (token::token_t)(l->yylex())) {
    if (tok == token::TOK_EOF)
      break;
    switch (tok) {
    case token::IF:
      std::cout << "IF" << std::endl;
      break;
    case token::WHILE:
      std::cout << "WHILE" << std::endl;
      break;
    case token::PRINT:
      std::cout << "PRINT" << std::endl;
      break;
    case token::READ:
      std::cout << "READ" << std::endl;
      break;
    case token::IDENTIFIER:
      std::cout << "IDENTIFIER(" << *pStr << ")" << std::endl;
      delete pStr;
      pStr = nullptr;
      break;
    case token::NUMBER:
      std::cout << "NUMBER(" << *pStr << ")" << std::endl;
      delete pStr;
      pStr = nullptr;
      break;
    default:
      break;
    }
  }

  delete l;
  return 0;
}