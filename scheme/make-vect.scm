(load "./inc/std.scm")


(define (x vect) (car vect))
(define (y vect) (cdr vect))
(define (make-vect x y) (cons x y))


(define (accum-vect proc v1 v2)
	(make-vect (proc (x v1) (x v2)) (proc (y v1) (y v2))))

(define (add-vect v1 v2)
	(accum-vect + v1 v2))

(define (sub-vect v1 v2)
	(accum-vect - v1 v2))

(define (filter-vect proc v)
		(make-vect (proc (x v)) (proc (y v))))

(define (scale-vect scale v)
		(filter-vect
			(lambda (con) (* con scale))
			v))

;ans section

(define v1 (make-vect 3 7))
(define v2 (make-vect 5 11))

(display (add-vect v1 v2))
(newline)

(display (sub-vect v1 v2))
(newline)

(display (scale-vect 2 v1))
(newline)

