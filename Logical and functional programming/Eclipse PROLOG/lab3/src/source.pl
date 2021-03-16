% 8. a)
% successor(l1...ln, carry) = [], if n = 0
%                             l1 U successor(l2...ln, carry), if carry = false
%		              l1 + 1 U successor(l2...ln, rezCarry), if rezCarry = true and l1 != 9
%		              0 U successor(l2...ln, carry), if carry = true and l1 = 9


% successor(L - list, carry - boolean, LFin - final list)
% flow model(I, I/o, o)

successor([], Carry, LFin):-
	Carry = true,
	LFin = [].
	
successor([H|T], Carry, LFin):-
	successor(T, Carry, L),
	not(Carry),
	LFin = [H|L].
	
	
successor([H|T], false, LFin):-
	RezCarry = true,
	successor(T, RezCarry, L),
	RezCarry,
	V is H + 1,
	Ten = 10,
	V \== Ten,
	LFin = [V|L].
	
successor([H|T], Carry, LFin):-
	successor(T, Carry, L),
	Carry,
	V is H + 1,
	Ten = 10,
	V == Ten,
	Z = 0,
	LFin = [Z|L].
	
% successorWrap(l1...ln) = [], n = 0,
%			   successor(l1...ln, rez), if rez is false
%			   1 U successor(l1...ln, rez), if rez is true (all the digits are 9s)

% flow model: (I, o)
% successorSublist(L - list, LFin - final list)
	
successorWrap([], LFin):-
	LFin = [], !.
	
successorWrap(L, LFin):-
	Rez = false,
	successor(L, Rez, L1),
	not(Rez),
	LFin = L1, !.
	
successorWrap(L, LFin):-
	Rez = true,
	successor(L, Rez, L1),
	Rez,
	V = 1,
	LFin = [V|L1].
	
	
%8. b)
% successorSublist(l1...ln) = [], n = 0,
%			      l1 U  successorSublist(l2...ln), if l1 is not a list
%			      successorWrap(l1) U  successorSublist(l2...ln), if l1 is a list

% flow model: (I, o)
% successorSublist(L - list, LFin - final list)

successorSublist([], LFin):-
	LFin = [].
	
successorSublist([H|T], LFin):-
	not(is_list(H)),
	successorSublist(T, L),
	LFin = [H|L].

successorSublist([H|T], LFin):-
	is_list(H),
	successorSublist(T, L),
	successorWrap(H, NewLis),
	LFin = [NewLis|L].

