# lang_exp
experimental programming language implement

## tokens
- ID : [a-z][a-z0-9]\*
- NUM : 0 | [1-9][0-9]\*
- ADD : +
- SUB : -
- MUL : \*
- DIV : /
- LPAR : (
- RPAR : )
- EQ : =
- EX : !
- QU : ?
- COMMA : ,
- SEMI : ;
- INT : int
- DELIM : \n | \t | \s
- COMMENT : /\* [a-z0-9]\* \*/
- EoF

## syntax
- program -> declStmts printStmts EoF
- declStmts -> declStmt SEMI
- declStmts -> declStmt SEMI declStmts
- declStmt -> INT varDefs
- varDefs -> ID EQ NUM
- varDefs -> varDefs COMMA ID EQ NUM
- printStmts -> empty
- printStmts -> printStmt SEMI printStmts
- printStmt -> EX varRefs
- varRefs -> ID
- varRefs -> varRefs COMMA ID

