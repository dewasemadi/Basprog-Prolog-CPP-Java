program :- read(N), what(N, X), write(X), nl.

man(adam).
man(peter).
man(paul).
woman(marry).
woman(eve).
parent(adam, peter).    %adam is parent of peter
parent(eve, peter).
parent(adam, paul).
parent(marry, paul).

father(M,X) :- man(M), parent(M, X).
mother(F,X) :- woman(F), parent(F,X).

is_father(M) :- father(M,_).
is_mother(F) :- mother(F,_).

:- program.