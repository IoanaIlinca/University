;7. Return the level of a node X in a tree of type (1). The level of the root element is 0


;l1l2..ln = tree - list
;E = element we looking for - atom
;M = number of childeren of the previous node(initialised with 0) - number
;LVL = maximum lvl - number
;crtLVL = crtlvl - number
	   			
;lvl(l1l2...ln, E ,lvl, crtLVL,  M )=	lvl, l1=elem
;					lvl(l3l4...ln, elem, LVL+1, crtLVL+1, l2), l2>0
;					lvl(l3l4...ln, elem, LVL+crtLVL, -1, l2), n>2 && l2=0 && M<2
;					lvl(l3l4...ln, elem, LVL, crtLVL, l2), n>2 && l2=0 && M=2          if last node had 2 sons we go to next one ,levels stay the same

;					nil, otherwise


(defun lvl(L E Level CurrLevel M)
  (cond
    ((eql (car L) E) Level)
    ((> (cadr L) 0) (lvl (cddr L) E (+ Level 1) (+ CurrLevel 1) (cadr L)))
    ((and (> (length L) 2) (and (= (cadr L) 0) (< M 2))) (lvl (cddr L) E (- Level CurrLevel) -1 (cadr L)))
    ((and (> (length L) 2) (and (= (cadr L) 0) (= M 2))) (lvl (cddr L) E Level CurrLevel (cadr L)))
    (t nil)
    )
)

;l1...ln - list
;E - atom

;level(l1...ln, E) = lvl(l1...ln, E, 0, -1, 0)

(defun level(L E)
  (lvl L E 0 -1 0)
  
  )
;      A
;   /  |  \
;  B       C 
; / \     / \
;G   F   D   E
(level '(A 2 B 2 G 0 F 0 C 2 D 0 E 0) 'B)