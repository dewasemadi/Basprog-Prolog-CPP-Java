program :- read(A), selisih(A,X), write(X), nl.

% kondisi jika list tunggal
selisih([],[]).
selisih([H1|[]], []).
% kondisi jika element list > 2
selisih([H1|[H2|T]],[B|X]) :- B is abs(H1-H2), selisih([H2|T], X).

:- program.