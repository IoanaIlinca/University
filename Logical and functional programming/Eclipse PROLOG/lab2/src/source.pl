%8.a) 
% even(l1l2...ln) = true, if n = 0
%                   not(even(l2...ln)), otherwise

% even(L - list)
% Flow model: (I)
	
even([]):-
	true.
	
even([_|T]):-
	not(even(T)).
	
	
%8.b)
% deleteMinimum(a1...an, b1...bn) = [], if n = 0
%                                   a2...an, if min_list(b1...bn, a1)
%                                   a1 U deleteMinimum(a2...an, b1...bn), if not(min_list(b1...bn, a1)

% delMinimum(l1...ln) = deleteMinimum(l1...ln, l1...ln)

% deleteMinimum(L1 - list, L2 - list, firstMin - boolean, LFin - final list)
% Flow model: (I, I, I, o)

% delMinimum(L - list, LFin - final list)
% flow model: (I, O)

delMinimum(L, LFin):-
	deleteMinimum(L, L, LFin).	      

deleteMinimum([], _, LFin):-
	LFin = [].
	
deleteMinimum([H1|T1], L, LFin):-
	min_list(L, H1),
	LFin = T1.

	
deleteMinimum([H1|T1], L, LFin):-
	not(min_list(L, H1)),
	deleteMinimum(T1, L, L1),
	LFin = [H1|L1].
	
	
	

	
	


