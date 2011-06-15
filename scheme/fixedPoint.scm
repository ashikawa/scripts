(load "./inc/std.scm")

(define tolerance 0.000001)

(define (fixed-point f first-guess)
	(define (close-enough v1 v2)
		(< (abs (- v1 v2)) tolerance))
	(define (try guess)
		(let ((next (f guess)))
			(if (close-enough guess next)
				next
				(try next))))
	(try first-guess))

(fixed-point cos 1.0)

(fixed-point (lambda (x) (/ (log 1000) (log x))) 2.0)

