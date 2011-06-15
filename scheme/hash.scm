(define (fact n)
	(fact2 n 1))

(define (fact2 n m)
	(if (< n (+ m 1))
			1
			(* n (fact2 (- n 1) m))))

(define (pow x n)
	(if (> n 1)
		(* x (pow x (- n 1)))
		x))

(define (per num n)
	(- 1 (/ (fact num) (* (pow num n) (fact (- num n))))))


(define (per2 num n)
	(- 1 (/ (fact2 num n) (pow num n))))


(define num 365)
(define n 23)

;(display (exact->inexact (per num n)))
;(newline)

;(display (exact->inexact (per2 num n)))
;(newline)

