# lang_exp
experimental programming language implement

## syntax
PROGRAM -> exp EoF
exp -> exp ADD term
exp -> term
term -> term MUL factor
term -> factor
factor -> ID
factor -> NUM
factor -> LPAR exp RPAR

