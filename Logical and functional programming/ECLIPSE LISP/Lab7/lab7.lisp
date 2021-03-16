; 12. Write a function that substitutes an element through another one at all levels of a given list

;x - atom
;n - atom
;m - atom

; sub (x n m) = m, if x = n
;               x, otherwise
(defun sub (x n m)
  (cond
    ((eq x n) m)
    (t x)
   )
  )

(sub 3 3 5)

;l1..ln - list
;x - atom
;y - atom

;subAllLevels(l, x, y) = U subAllLevels(li, x, y), if l= l1...ln
;                              sub(l, x, y), otherwise, l is an atom

(defun subAllLevels (L n m)
  (cond
    ((listp L) (apply #'list (MAPCAR #'(lambda (a) (subAllLevels a n m)) L) ))
    (t (sub L n m))
       
    )
  )
(subAllLevels (list 'A 'B) 'A 5)
(subAllLevels (list 'A 5 (list 'A 1 (list 'A 3 3)  2)) 'A 'B)



