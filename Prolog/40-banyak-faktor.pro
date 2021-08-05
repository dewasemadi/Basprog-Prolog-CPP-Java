program :- read(N), faktor(N,X), write(X), nl.

faktor(N,X) :- f(N,1,0,X).
f(N,N,S,X)  :- X is S+1.
f(N,C,S,X)  :- C<N, N mod C =:= 0, T is S+1, C1 is C+1, f(N,C1,T,X).
f(N,C,S,X)  :- C<N, N mod C =\= 0, C1 is C+1, f(N,C1,S,X).

:- program.

% Menghitung banyaknya faktor dari bilangan bulat. 
% Contoh: faktor dari 6 adalah 4 yaitu 1,2,3, dan 6