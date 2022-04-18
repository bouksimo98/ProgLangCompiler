
%{
    #include <iostream>
    #include "token.h" 
    #define TOKEN(X) return token::X;
    extern std::string* pStr;
%}

%option c++
%option noyywrap

DIGIT [0-9]

%%

[ \n\r\t]+             { /* ignore whitespace */ }  

"if"                   { TOKEN(IF) }
"while"                { TOKEN(WHILE) }
"print"                { TOKEN(PRINT) }
"read"                 { TOKEN(READ) }

[a-zA-Z_][a-zA-Z0-9_]* { pStr = new std::string(yytext, yyleng); TOKEN(IDENTIFIER) }
{DIGIT}+                 { pStr = new std::string(yytext, yyleng); TOKEN(NUMBER) }


.                      { std::cout << "LEXICAL ERROR : unexpected character "; }
<<EOF>>                { std::cout << "EOF "; TOKEN(TOK_EOF); }

%%
