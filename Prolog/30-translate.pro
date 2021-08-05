tran(satu, one).
tran(dua, two).
tran(tiga, three).
tran(empat, four).
tran(lima, five).
tran(enam, six).
tran(tujuh, seven).
tran(delapan, eight).
tran(sembilan, nine).

translate([],[]).
translate(X,Y) :- tran(X,Y).
translate([H|T],[H1|T1]) :- tran(H,H1), translate(T,T1).