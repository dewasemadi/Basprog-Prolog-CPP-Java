program :- read(N), faktorial(N, X), write(X), nl.

faktorial(0,1).
faktorial(N,X) :- N>0, N1 is N-1, faktorial(N1, X1), X is N*X1.

:- program.