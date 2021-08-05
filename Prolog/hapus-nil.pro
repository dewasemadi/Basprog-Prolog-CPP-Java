program :- read(L),prefix(L,X),write(X),nl.

% kosong([[]]).
% exclude(kosong,L,X).
prefix(L,X) :- flatten(L,X).

:- program.