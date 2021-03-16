% 8. a)
% successor(l1...ln, carry) = [], if n = 0
%			      l1 + 1, if carry = false and n = 1
%			      0, if carry = true and n = 1
%                             l1 U successor(l2...ln, false), if carry = false and n != 1
%		              l1 + 1 U successor(l2...ln, false), if carry = false and n != 1 and l1 != 9
%		              0 U successor(l2...ln, true), if carry = true and n != 1 and l1 = 9


% successor(L - list, carry - boolean, LFin - final list)
% flow model(I, I/o, o)

successor([], _, LFin):-
	LFin = [].
	
	
successor([H], false, LFin):-
	%RezCarry = true,
	V is H + 1,
	Ten = 10,
	V \== Ten,
	LFin = [V], !.
	
successor([H], true, LFin):-
	V is H + 1,
	Ten = 10,
	V == Ten,
	Z = 0,
	LFin = [Z], !.
	
successor([H|T], Carry, LFin):-
	not(T == []),
	successor(T, Carry, L),
	not(Carry),
	LFin = [H|L].
	
	
successor([H|T], false, LFin):-
	not(T == []),
	successor(T, Carry, L),
	Carry,
	V is H + 1,
	Ten = 10,
	V \== Ten,
	LFin = [V|L].
	
successor([H|T], true, LFin):-
	not(T == []),
	successor(T, Carry, L),
	Carry,
	V is H + 1,
	Ten = 10,
	V == Ten,
	Z = 0,
	LFin = [Z|L].
	
% successorWrap(l1...ln) = successor(l1...ln, rez), if rez is false
%			   1 U successor(l1...ln, rez), if rez is true (all the digits are 9s)

% flow model: (I, o)
% successorSublist(L - list, LFin - final list)
	
	
successorWrap(L, LFin):-
	Rez = false,
	successor(L, Rez, L1),
	not(Rez),
	LFin = L1, !.


% all digits are 9s	
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

