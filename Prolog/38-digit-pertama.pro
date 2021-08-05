program :- read(N), digitPertama(N,X), write(X), nl.

digitPertama(N,N) :- N < 10.
digitPertama(N,X) :- N >= 10, T is round(N/10), digitPertama(T,X).

:- program.