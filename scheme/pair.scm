(load "./inc/std.scm")

(define x (list (list 1 2) 3 4))

(define (count-leaves x)
	(cond ((null? x) 0)
	((not (pair? x)) 1)
	(else (+ (count-leaves (car x))
				(count-leaves (cdr x))))))

(display (count-leaves (list x x)))
(newline)

