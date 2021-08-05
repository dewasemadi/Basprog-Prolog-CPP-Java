program :- read(L1), read(L2), bagian(L1, L2, X), write(X), nl.

bagian(L1,L2,X) :- partOf(L1,L1,L2,X).
partOf(_,[],_,X) :- X is 1, !.
partOf(_,_,[],X) :- X is 0, !.
partOf(I,[N|J],[N|K],X) :- partOf(I,J,K,X).
partOf(I,[N|J],[_|K],X) :- partOf(I,I,K,X).

:- program.