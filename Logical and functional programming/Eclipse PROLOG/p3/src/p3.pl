reverse([], []).
	
reverse([H|T], [H|R]):-
	atom(H),
	reverse(T, R).

reverse([H|T], New):-
	is_list(H),
	RR is [],
	reverse(H, RR),
	R is [],
	reverse(T, R),
	New is [RR|R].
	
subset(_, [], 0):- !.
%subset([], [], _):- !.

subset([H|T], [H|R], X):-
	X1 is X - 1,
	subset(T, R, X1).
	
subset([_|T], R, X):-
	subset(T, R, X).
	
listOfSubsets(L, N, RR):-
	findall(R, subset(L, R, N), RR).