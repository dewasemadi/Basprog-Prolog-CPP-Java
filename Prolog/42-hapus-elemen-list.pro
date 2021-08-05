program :- read(N), read(L), hapus(N,L,X), write(X), nl.

hapus(H,[H|T],X)     :- hapus(H,T,X).
hapus(S,[H|T],[H|R]) :- H\==S, hapus(S,T,R).

:- program. 

% Menghapus elemen dalam list
% ?- hapus(a,[2,3,a,b,a,4],X).
% X = [2,3,b,4].