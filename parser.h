#ifndef PARSER_H
#define PARSER_H
#include <iostream> 
#include <fstream>  
#include <cstdlib> 
#include "scanner.h" 
#include "testScanner.h"

using namespace std; 
/* 
 program_node, vars_node, varList_node, exp_node, M_node, N_node, R_node, stats_node, mStat_node, stat_node, block_node, in_node, out_node, if_node, loop_node, assign_node,RO_node,
*/

node *program(); 
node *vars(); 
node *varList(); 
node *exp(); 
node *M(); 
node *N(); 
node *R(); 
node *stats(); 
node *mStat(); 
node *stat();
node *block(); 
node *in(); 
node *out(); 
node *If(); 
node *loop(); 
node *assign(); 
node *RO(); 

#endif 

