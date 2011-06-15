(define (rectangular? z)
	(eq? (type-tag z) 'rectangular))

(define (real-part-rectangular z) (car z))
(define (imag-part-rectangular z) (cdr z))


(define (magnitude-rectangular z)
	(sqrt (+ (square (real-part-rectangular z))
				(square (imag-part-rectangular z)))))

(define (angle-rectangular z)
	(atan (imag-part-rectangular z)
		(real-part-rectangular z)))

(define (make-from-mag-ang-rectangular x y)
	(attach-tag 'rectangular (cons x y)))

(define (make-from-mag-ang-rectangular r a)
	(attach-tag 'rectangular
		(cons (* r (cos a)) (* r sin a))))

(define (make-from-real-imag-rectangular x y)
	(attach-tag 'rectangular
		(cons x y)))
