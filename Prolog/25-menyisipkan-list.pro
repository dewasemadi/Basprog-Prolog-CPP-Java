program :- read(L1), read(L2), read(N), sisipList(L1,L2,N,X), write(X), nl.

% kalo N = 1, otomatis L1 jadi head
sisipList(L1, L2, 1, [L1|L2]).
% cari posisi
sisipList(L1, [H|T], N, [H|X]) :- N>1, !, N1 is N-1, sisipList(L1, T, N1, X).

:- program.