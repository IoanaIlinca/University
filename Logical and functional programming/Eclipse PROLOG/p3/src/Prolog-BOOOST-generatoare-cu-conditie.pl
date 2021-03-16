%H =first elem
% T =tail
% LE=last addded elem
conditie(H,LE):-D is LE-H, D1 is abs(D), D1 =< 2.
%returneaza pe rand fiecare elem al listei L
elem([E|T], E, T).
elem([_|T], E, R):- elem(T, E,R).
%sterge elementul E din lsita (o singutra aparitie
stergeE([E|R], E, R):-!.
stergeE([H|T], E, [H|R]):- stergeE(T, E, R).
% genereaza toate {submultimile, permutarile, COombinarile, aranjamentele} ce satisfac conditia
submCond([], _, []).
submCond([H|T], LE, [H|R]):-conditie(H,LE), submCond(T,H, R).
submCond([_|T], LE,  R):- submCond(T,LE, R).

permCond([],_,[]).
permCond(L, LE,[E|R]):-elem(L,E,_), stergeE(L,E,T), conditie(E,LE), permCond(T,E, R).

combCond([], 0,_, []).
combCond([H|T],K,LE, [H|R]):- conditie(H,LE), K1 is K-1, combCond(T, K1, H, R).
combCond([_|T],K,LE, R):- combCond(T, K, LE,  R).

aranjCond(L, K,LE, RR):- combCond(L, K,LE, R), permCond(R, LE,RR).

generator(L,[E|R]):-elem(L,E,T), submCond(T,E,R).
gen(L, R):- findall(O, generator(L,O),R).

generator2(L,[E|R]):-elem(L,E,_), stergeE(L,E,T), permCond(T,E,R).
gen2(L, R):- findall(O, generator2(L,O),R).

generator3(L, K, [E|R]):-elem(L,E,T),K1 is K-1, combCond(T,K1, E,R).
gen3(L,K, R):- findall(O, generator3(L, K, O),R).

generator4(L, K, [E|R]):-elem(L,E,_), stergeE(L,E,T),K1 is K-1, aranjCond(T,K1, E,R).
gen4(L,K, R):- findall(O, generator4(L, K, O),R).