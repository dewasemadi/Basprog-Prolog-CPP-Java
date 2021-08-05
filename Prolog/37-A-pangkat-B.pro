program :- read(A), read(B), pangkat(A,B,X), write(X), nl.

pangkat(A,B,X) :- B =:= 0, X is 1.
pangkat(A,B,Z) :- B > 0, T is B-1, pangkat(A,T,X), Z is A*X.

:- program.