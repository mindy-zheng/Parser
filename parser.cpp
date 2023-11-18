#include <iostream> 
#include <string> 
#include <iomanip>
#include "testScanner.h"
#include "parser.h"
#include "scanner.h"
#include "token.h" 

using namespace std; 

ifstream file; 
Token token;
/*
 *  program_node, vars_node, varList_node, exp_node, M_node, N_node, R_node, stats_node, mStat_node, stat_node, block_node, in_node, out_node, if_node, loop_node, assign_node,RO_node,

node *program(); node *vars(); node *varList(); node *exp(); node *M(); node *N(); node *R(); node *stats(); node *mStat(); node *stat(); node *block(); node *in(); node *out(); node *If(); node *loop(); node *assign(); node *RO();  

XOPEN_TOKEN, XCLOSE_TOKEN, XLOOP_TOKEN, XDATA_TOKEN, XEXIT_TOKEN, XIN_TOKEN, XOUT_TOKEN, XCOND_TOKEN, XTHEN_TOKEN, XLET_TOKEN, XFUNC_TOKEN, EOF_TOKEN, IDENTIFIER_TOKEN, INTEGER_TOKEN, EQUAL_TOKEN, LESS_TOKEN,GREATER_TOKEN, TILDE_TOKEN, COLON_TOKEN, SEMICOLON_TOKEN, PLUS_TOKEN, SUBTRACT_TOKEN, MULTIPLY_TOKEN, DIVIDE_TOKEN, PERCENT_TOKEN, PERIOD_TOKEN, COMMA_TOKEN, LEFT_PARENTHESIS_TOKEN, RIGHT_PARENTHESIS_TOKEN, LEFT_BRACE_TOKEN, RIGHT_BRACE_TOKEN, LEFT_BRACKET_TOKEN, RIGHT_BRACKET_TOKEN, GREATERGREATER_TOKEN, LESSLESS_TOKEN, COMMENT_TOKEN,

 */ 

extern string token_types[]; 

node* parser(ifstream &input) { 
	file = input; 
	node *root; 

	lookahead_ch(file); 
	token = scanner(file); 
	root = program();

	if (token.tokenType != EOF) { 
		cout << "Parser error: extra token after EOF" << endl; 
	} 
	cout << "Parser success! " << endl; 
	return root; 
} 

// <program>  -> <vars> xopen <stats> xclose
node *program() { 
	node *n = createNode(program_node);
	
	n -> c2 = vars(); 
	if (token.tokenType == XOPEN_TOKEN) {
		token = scanner(file); 
		n -> c2 = stats();
		if (token.tokenType == XCLOSE_TOKEN) { 
			token = scanner(file); 
			return node; 
		} else { 
			cout << "Error: Expected 'xclose' terminal." << endl;  
			exit(1); 
		}
	} else { 
		cout << "Error: expected 'xopen' terminal" << endl; 
		exit(1);
	} 
} 
	
// <vars> -> empty | xdata <varList> 
node *vars() { 
	node *n = createNode(vars_node); 
	if (token.tokenType == XDATA_TOKEN) { 
		token = scanner(file); 
		n -> c1 = varList(); 
	} 
	return node; 
} 

// <varList> -> identifier : integer ; | identifier : integer <varList> 
node *varList() { 
	node *n = createNode(varList_node); 
	if (token.tokenType == IDENTIFIER_TOKEN) { 
		n-> token1 = token; 
		token = scanner(file); 

		if (token.tokenType == COLON_TOKEN) { 
			token = scanner(file); 
			
			if (token.tokenType == INTEGER_TOKEN) { 
				n-> token2 = token; 
				token = scanner(file); 

				if (token.tokenType == SEMICOLON_TOKEN) { 
					token = scanner(file); 
					n -> c1 = varList(); 
				}
			}
		}
	}
	
	return node; 
} 

// <exp> -> <M> / <exp> | <M> * <exp> | <M>
node *exp() { 
	node *n = createNode(exp_node);
	n -> c1 = M();  

	if (token.tokenType == DIVIDE_TOKEN) { 
		n -> token1 = token; 
		token = scanner(file); 
		n -> c2 = exp(); 
	} else if (token.tokenType == MULTIPLY_TOKEN) { 
		n -> token1 = token; 
		token = scanner(file); 
		n -> c2 = exp(); 
	} 
	return node; 
}

// <M> -> <N> + <M> | <N> 
node *M() { 
	node *n = createNode(M_node); 
	n -> c1 = N(); 

	if (token.tokenType == PLUS_TOKEN) { 
		n-> token1 = token; 
		token = scanner(file); 
		n-> c2 = M(); 
		return node; 
	} 
	
	return node; 
} 

// <N> -> <R> - <N> | ~ <N> | <R>
node *N() { 
	node *n = createNode(N_node); 

	if (token.tokenType == TILDE_TOKEN) { 
		n-> token1 = token; 
		token = scanner(file);
		n -> c1 = N();  
	} else { 
		n-> c1 = R(); 
	
		if (token.tokenType == MINUS_TOKEN) { 
			n-> token1 = token; 
			token = scanner(file); 
			n-> c2 = N(); 
		}
	}
	
	return node; 
} 


// <R> -> (<exp>) | identifier | integer
node *R() { 
	node *n = createNode(R_node); 
	if (token.tokenType == LEFT_PARENTHESIS_TOKEN) { 
		token = scanner(file); 
		n-> c1 = exp(); 

		if (token.tokenType == RIGHT_PARENTHESIS_TOKEN) { 
			token = scanner(file); 
		} else { 
			cout << "Error: Expected ')' token" << endl; 
			exit(1); 
		} 
	} else if (token.tokenType == IDENTIFIER_TOKEN || token.tokenType == INTEGER_TOKEN){ 
		n -> token1 = token; 
		token = scanner(file); 
	} else { 
		cout << "Error: expected identifier or integer constant" << endl; 
		exit(1); 
	}
	
	return node; 
} 


// <stats> -> <stat> <mStat> 
node *stats() { 
	node *n = createNode(stats_node); 
	n -> c1 = stat(); 
	n -> c2 = mStat(); 
	return node; 
} 

// <mStat> -> empty | <stat> <mStat> 
node *mStat() { 
	node *n = createNode(mStat_node); 
 
}
// <stat> -> <in>|<out>|<block>|<if>|<loop>|<assign>



// <block> -> { <vars> <stats> } 



// <in> -> xin >> identifier; 


// <out> -> xout << <exp>; 


// <if> -> xcond [ <exp> <RO>  <exp> ] <stat> 

// <loop> -> xloop [ <exp> <RO> <exp> ] <stat> 

// <assign> -> xlet identifier <exp>; 

// <RO> -> <<(one token) | >> (one token) | < | > | = | %

node *RO() { 


}
