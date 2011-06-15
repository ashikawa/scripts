(load "./inc/std.scm")


(define (count-pairs x)
	(if (not (pair? x))
		0
		(+ (count-pairs (car x))
			(count-pairs (cdr x))
			1)))


(define x1 (list 'a 'b 'c))

(display (count-pairs x1))
(newline)

(define x2 (cons (list 'a 'b) (list 'c)))

(display (count-pairs x2))
(newline)


