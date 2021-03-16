; point a

; dotProduct(a1...an, b1...bm) = 0, n = 0
;                                0, m = 0
;                                a1 * b1 + dotProduct(a2...an, b2...bn), otherwise

(defun dotProduct(L K) 

  (cond

		((null L) 0) 
		
		((null K) 0) 
		
		(T (+(* (car L)(car K)) (dotProduct (cdr L) (cdr K)))) 

    ))

"Point a, dot product for [1, 1, 2] and [1, 2, 1]: "
(dotProduct (list '1 '1 '2) (list '1 '2 '1))

; point b

; maximum(l1...ln, max) = max, n = 0
;                         maximum(l2...ln, maximum(l1, max)), if l1 is a list
;						  maximum(l2...ln, max), if l1 is a non-numerical atom
;						  maximum(l2...ln, l1), if l1 is a number and max is -100000
;						  maximum(l2...ln, l1), if l1 > max and l1 is a number
;                         maximum(l2...ln, max), otherwise
;                         

(defun maximum(L max)
    (cond
        ((null L) max)
        
        ((and (listp (car L)) (maximum(cdr L)(maximum (car L) max))))
          
        
        ((not(numberp(car L))) (atom(car L)) (maximum(cdr L) max))
        
        ((= max -100000) (numberp (car L)) (maximum (cdr L)(car L)))
        
        ((and (numberp (car L)) (> (car L) max)) (maximum(cdr L)(car L)))
        
        (T (maximum(cdr L) max))
        
    ))

"Point b, maximum for 1 2 (7 6) 4 A 3: "
(maximum '(list 1 2 (7 6) 4 A 3) -100000)




; point c

; evaluate(l1...ln, st1...stm) = ln, if n = 1 and m = 0
;                                evaluate(l2...ln, l1 U st1...stn), if l1 = '+
;						         evaluate(l2...ln, l1 U st1...stn), if l1 = '-
;						         evaluate(l2...ln, l1 U st1...stn), if l1 = '*
;						         evaluate(l2...ln, l1 U st1...stn), if l1 = '/
;                         		 evaluate((l1 + st1) U l2..ln, st3...stm), if l1 is a number and st1 is a number and st2 = '+
;                         		 evaluate((l1 - st1) U l2..ln, st3...stm), if l1 is a number and st1 is a number and st2 = '-
;                         		 evaluate((l1 * st1) U l2..ln, st3...stm), if l1 is a number and st1 is a number and st2 = '*
;                         		 evaluate((l1 / st1) U l2..ln, st3...stm), if l1 is a number and st1 is a number and st2 = '/
;								 evaluate(l2...ln, l1 U st1...stm), if l1 is a number
;  

(
  defun evaluate(L st)
  (cond
    ((and (null (cdr L)) (null st)) (car L))
    ; add signs to the stack
    ; or check if it is not an numeric atom
    ((equal (car L) '+) (evaluate (cdr L) (cons (car L) st)))
    ((equal (car L) '-) (evaluate (cdr L) (cons (car L) st)))
    ((equal (car L) '*) (evaluate (cdr L) (cons (car L) st)))
    ((equal (car L) '/) (evaluate (cdr L) (cons (car L) st)))
    ; if number already in the stack evaluate
    ;((and (numberp (car L)) (numberp (car st))) (evaluate (cons (eval (list (car (cdr st)) (car st) (car L))) (cdr L)) (cdr (cdr st))))
    ((and (numberp (car L)) (numberp (car st)) (equal (car (cdr st)) '+)) (evaluate (cons (+ (car st) (car L)) (cdr L)) (cddr st)))
    ((and (numberp (car L)) (numberp (car st)) (equal (car (cdr st)) '-)) (evaluate (cons (- (car st) (car L)) (cdr L)) (cddr st)))
    ((and (numberp (car L)) (numberp (car st)) (equal (car (cdr st)) '*)) (evaluate (cons (* (car st) (car L)) (cdr L)) (cddr st)))
    ((and (numberp (car L)) (numberp (car st)) (equal (car (cdr st)) '/)) (evaluate (cons (/ (car st) (car L)) (cdr L)) (cddr st)))
    ; add number to the stack
    ((numberp (car L)) (evaluate (cdr L) (cons (car L) st)))
  )
)

"For 1 + 3: " 
(evaluate (list '+ '1 '3) ())

"For ((2 * 4) + 3): " 
(evaluate (list '+ '* '2 '4 '3) ())

"For ((2 * 4) + (5 - (2 * 2)) " 
(evaluate (list '+ '* '2 '4 '- 5 '* '2 '2) ())


; rev(l1...ln) = (), n = 0
;                rev(l2...ln) U (l1), otherwise 


(defun rev (l)
    (cond
        ((null l) '())
        (T (append (rev (cdr l)) (list (car l)))))) 

(rev (list '+ '* 2 4 '- 5 '* 2 2))


;postorder(l1...ln, st1...stm) = st1, n = 0
;                                postorder(l2...ln, l1 U st1...stm), if l1 is a number
;                                postorder(l2...ln, (st1 + st2) U st3...stn), if l1 = '+
;                                postorder(l2...ln, (st1 * st2) U st3...stn), if l1 = '*
;                                postorder(l2...ln, (st1 - st2) U st3...stn), if l1 = '-
;                                postorder(l2...ln, (st1 / st2) U st3...stn), if l1 = '/

(defun postorder(List stack)
  (cond 
    ((null List) (car stack))
    (( numberp (car List)) (postorder (cdr List) (cons (car List) stack) ))
    ((equal (car List) '+) (postorder (cdr List) (cons (+ (car stack) (cadr stack)) (cddr stack) ) ))   
    ((equal (car List) '*) (postorder (cdr List) (cons (* (car stack) (cadr stack)) (cddr stack) ) ))  
    ((equal (car List) '-) (postorder (cdr List) (cons (- (car stack) (cadr stack)) (cddr stack) ) )) 
    ((equal (car List) '/) (postorder (cdr List) (cons (/ (car stack) (cadr stack)) (cddr stack) ) ))  
     
   ))

(postorder (rev (list '+ '* '2 '4 '- '5 '* '2 '2)) () )

; preorder(l1...ln) = postorder(rev(l1...ln), ()), every time (wrapper)

(defun preorder(List)
  (cond
    (t(postorder (rev List) () ))
    )
)
 
"For 1 + 3: " 
(preorder (list '+ '1 '3))

"For ((2 * 4) + 3): " 
(preorder (list '+ '* '2 '4 '3))

"For ((2 * 4) + (5 - (2 * 2)) " 
(preorder (list '+ '* '2 '4 '- 5 '* '2 '2))

; point d

; parityOfNumberOfElements(l1...ln) = true, if n = 0
;                                     not(parityOfNumberOfElements(l2...ln)), otherwise

(defun parityOfNumberOfElements(L) 

    (cond 
    
        ((null L) T)
        
        (T (not(parityOfNumberOfElements(cdr L))))
    
    )) 
    

"Point d, parity for number of elements (T for even, NIL for odd): "


"For list 1 2 3 4: "
(parityOfNumberOfElements (list 1 2 3 4))

"For list 1 2 3 4 5: " 
(parityOfNumberOfElements (list 1 2 3 4 5))








