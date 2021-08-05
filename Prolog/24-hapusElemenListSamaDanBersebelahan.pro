% program :- read(A), hapus(A,X), write(X), nl.

% list kosong
hapus([],[]).
% list tunggal, misal [1] ya ga bisa di hapus lg
hapus([H1|[]],[H1]).
% misal, [1,2,2,2], H1 = 1, H2 = [2|2,2], H1 != H2, maka simpen 1
hapus([H1|[H2|T]], [H1|X]) :- H1 =\= H2, hapus([H2|T],X).
% misal, [2,2,3,4,4,4,4,2,2], H1 = 2, H2 = 2, H3 = [3|4,4,4,4,2,2], maka hapus 3
hapus([H1|[H2|[H3|T]]], X) :- H1 =:= H2, H2 =\= H3, hapus([H3|T],X).
% misal, [2,2,2,2], H1 = 2, H2 = 2, H3 = [2|2], maka simpen 2
hapus([H1|[H2|[H3|T]]], X) :- H1 =:= H2, H2 =:= H3, hapus([H2|[H3|T]], X).

% :- program.