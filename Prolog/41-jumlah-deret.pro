program :- read(N), jumlahderet(N,X), write(X), nl.

jumlahderet(N,X) :- jum(N,1,0,X).
jum(N,N,S,X) :- X is S+N.
jum(N,C,S,X) :- C<N, T is S+C, C1 is C+1, jum(N,C1,T,X).

:- program.

% Hitung penjumlahan 1+2+ .... + N.