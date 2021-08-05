program :- read(L), diagUtama(L,X), write(X), nl.

diagUtama(L, H1) :- length(L, X),
findall(B, (between(1,X,A), nth1(A, L, Row), nth1(A, Row, B)), H1).

:- program.