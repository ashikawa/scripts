(load "./inc/std.scm")

(define in (list 1 2 3 4))
;(define in (cons 1 (cons 2 (cons 3 (cons 4 '())))))

(display in)

(newline)

(define (append list1 list2)
	(if (null? list1)
		list2
		(cons (car list1) (append (cdr list1) list2))))

(define (rev in)
	(if (null? (cdr in))
		in
		(append (rev (cdr in)) (cons (car in) '()))))

(display (rev in))
(newline)

