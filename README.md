# CS4280 Programming Translation Project -- P2:
- Cloned all source files and fixed errors from P1 involving whitespace detection and incorrect token matching. 
- This program implements a parser for a given LL(1) grammar. This parser builds from the scanner module in P1 to tokenize all the input and constructs a parse tree based on the BNF grammar below. 

P2 BNF: 
<program>  ->     <vars> xopen <stats> xclose
<vars>     ->      empty | xdata <varList>
<varList>  ->      identifier : integer ; | identifier : integer <varList>
<exp>      ->      <M> / <exp> | <M> * <exp> | <M>
<M>        ->      <N> + <M> | <N>      
<N>        ->     <R> - <N> | ~ <N> |  <R>
<R>        ->      ( <exp> )  | identifier | integer
<stats>    ->      <stat>  <mStat>
<mStat>    ->      empty |  <stat>  <mStat>
<stat>     ->      <in>   | <out>   | <block> | <if>  | <loop>  | <assign>
<block>    ->      { <vars> <stats> }
<in>       ->      xin >> identifier ;
<out>      ->      xout << <exp> ;
<if>       ->      xcond [ <exp> <RO> <exp> ] <stat>
<loop>     ->      xloop [ <exp> <RO> <exp> ]  <stat>
<assign>   ->     xlet  identifier  <exp> ;
<RO>       ->      << (one token)  | >>  (one token)  | < | > | = | %                     
## Testing
For better organization, I kept my testing files in a separate folder. There will be 10 testing files for bad and good programs, so you'll have to include this when caling upon the program. Please note that some of the testing files are out of order (in the bad_test directory). Reach out if this should be fixed.  

## HOW TO RUN: 
1. Compile P2 with: make 
2. To test out the good inputs, please make sure to include the directory:
	- Option 1: ./P2 good_test/[testingfile.f23] 
	- Option 2: ./P2 good_test/[testingfile] 
3. To test out the bad inputs, do the same as above: 
	- Option 1: ./P2 bad_test/[testingfile.f23] 
	- Option 2: ./P2 bad_test/[testingfile]

