// TOKEN HEADER
// Make sure to include in other files 
#ifndef TOKEN_H
#define TOKEN_H 

#include <iostream> 
#include <string> 

using namespace std; 

enum tokenID {
	//Keywords
	XOPEN_TOKEN, 
	XCLOSE_TOKEN, 
	XLOOP_TOKEN, 
	XDATA_TOKEN, 
	XEXIT_TOKEN, 
	XIN_TOKEN, 
	XOUT_TOKEN, 
	XCOND_TOKEN,
	XTHEN_TOKEN, 
	XLET_TOKEN,
	XFUNC_TOKEN,

	// ID, INT
	EOF_TOKEN,
	IDENTIFIER_TOKEN,
	INTEGER_TOKEN,
			
	EQUAL_TOKEN,
	LESS_TOKEN,
	GREATER_TOKEN,
	TILDE_TOKEN, 
	COLON_TOKEN,
        SEMICOLON_TOKEN,
	PLUS_TOKEN, 
	SUBTRACT_TOKEN, 
	MULTIPLY_TOKEN, 
	DIVIDE_TOKEN, 
	PERCENT_TOKEN, 
	
	PERIOD_TOKEN, 
	COMMA_TOKEN, 
	LEFT_PARENTHESIS_TOKEN,
	RIGHT_PARENTHESIS_TOKEN, 
	LEFT_BRACE_TOKEN, 
	RIGHT_BRACE_TOKEN, 
	LEFT_BRACKET_TOKEN,
	RIGHT_BRACKET_TOKEN,
	GREATERGREATER_TOKEN,
	LESSLESS_TOKEN,
	COMMENT_TOKEN,
	EMPTY_TOKEN,
};




typedef struct Token { 
	tokenID tokenType; 
	string tokenInstance; 
	int lineNumber; 
} Token; 

#endif

