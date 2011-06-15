(use slib)
(require 'trace)


(define % remainder)

(define (even n) (= (% n 2) 0))

(define (pow x n)
  (if (> n 1)
      (* x (pow x (- n 1)))
    x))

(define (square x) (* x x))
(define (cube x) (* x x x))

;(define (sin angle)
;  (if (not (> (abs angle) 0.1))
;      angle
;    (p (sin (/ angle 3.0)))))

(define (exp x n)
  (cond ((= n 0) 1)
        ((even n) (square (exp x (/ n 2))))
        (else (* x (exp x (- n 1))))))

(define (sum term a next b)
   (if   (> a b)
         0
         (+ (term  a)
            (sum term (next a) next b))))

(define (positive x) (> x 0))
(define (negative x) (< x 0))

(define (average x y) (/ (+ x y) 2))

(define (close-enough x y)
   (< (abs (- x y)) 0.001))

;最大公約数
;(define (gcd a b)
;	(if (= b 0)
;		a
;		(gcd b (% a b))))

(define (length items)
	(if (null? items)
		0
		(+ 1 (length (cdr items)))))

(define (identity x) x)

(define (divides? a b)
	(= (remainder b a) 0))

(define (divisible? x y)
	(= (remainder x y) 0))

(define (find-divisor n test-divisor)
	(cond ((> (square test-divisor) n) n)
			((divides? test-divisor n) test-divisor)
			(else (find-divisor n (+ test-divisor 1)))))

(define (smallest-divisor n)
	(find-divisor n 2))

(define (prime? n)
	(= n (smallest-divisor n)))


;low から high までの数列
(define (enumerate-interval low high)
	(if (> low high)
		'()
		(cons low (enumerate-interval (+ low 1) high))))

(define (filter predicate sequence)
   (cond ((null? sequence) '())
         ((predicate (car sequence))
         (cons (car sequence)
               (filter predicate (cdr sequence))))
         (else (filter predicate (cdr sequence)))))

(define (enumerate-tree tree)
   (cond ((null? tree) '())
         ((not (pair? tree)) (list tree))
         (else (append (enumerate-tree (car tree))
                        (enumerate-tree (cdr tree))))))

