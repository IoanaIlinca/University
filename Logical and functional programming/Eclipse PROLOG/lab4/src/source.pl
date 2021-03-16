/*
build(X, N1) = [0, 1, 0], if N1 = 3 and x = 0
		[0, -1, 0], if N1 = 3 and x = 0
		[-1, 1, 0], if N1 = 3 and x = -1
		[1, -1, 0], if N1 = 3 and x = 1
		X U build(-1, N1 - 1), if N1 != 3 and X != -1
		X U build(0, N1 - 1), if N1 != 3 and X != 0
		X U build(1, N1 - 1), if N1 != 3 and X != 1



build(X - integer,N1 - integer,[X|L] - list)
build(i, i, o)
*/

build(X, 3, [X|L]):-
	X == 1,
	L = [-1, 0].
	
build(X, 3, [X|L]):-
	X == -1,
	L = [1, 0].
	
build(X, 3, [X|L]):-
	X == 0,
	L = [-1, 0].
	
build(X, 3, [X|L]):-
	X == 0,
	L = [1, 0].

build(X,N1,[X|L]) :-  
	N1 > 0, N is N1 - 1,
	X \== 0,
	build(0,N,L).
	
build(X,N1,[X|L]) :-  
	N1 > 0, N is N1 - 1,
	X \== 1,
	build(1,N,L).
	
build(X,N1,[X|L]) :-  
	N1 > 0, N is N1 - 1,
	X \== -1,
	build(-1,N,L).



/*	
	
build(1,N1,[1|L]) :-  
	N1 > 0, N is N1 - 1,
	build(0,N,L).
	
	
build(1,N1,[1|L]) :-  
	N1 > 0, N is N1 - 1,   
	build(-1,N,L).
	
build(-1,N1,[-1|L]) :-  
	N1 > 0, N is N1 - 1,
	build(0,N,L).
	
build(-1,N1,[-1|L]) :- 
	N1 > 0, N is N1 - 1,   
	build(1,N,L).
	
build(0,N1,[0|L]) :- 
	N1 > 0, N is N1 - 1,   
	build(-1,N,L).
	
build(0,N1,[0|L]) :-  
	N1 > 0, N is N1 - 1,    
	build(1,N,L).
*/

/*
wrapperGenerator(n) = [0], if n = 0
			U(build(0, 2*n + 1), otherwise

wrapperGenerator(N - integer, R - list of lists)
wrapperGenerator(i, o)
*/

wrapperGenerator(0, L):-
	L = [0], !.

wrapperGenerator(N, R):-
	Length is 2 * N + 1,
	findall(L, build(0, Length, L), R). 