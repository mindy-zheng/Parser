CS4280 Programming Translation Project -- P2:
- Cloned all source files and fixed errors from P1. 

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


HOW TO RUN: 
1. run and compile P2 with: make 

Option 1:  
Option 2: 


