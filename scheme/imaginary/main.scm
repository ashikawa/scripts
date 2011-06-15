(load "../inc/std.scm")
(load "./polar.scm")
(load "./rectangular.scm")


(define (add-complex z1 z2)
	(make-from-real-imag (+ (real-part z1) (real-part z2))
		(+ (imag-part z1) (imag-part z2))))

(define (sub-complex z1 z2)
	(make-from-real-imag (- (real-part z1) (real-part z2))
		(- (imag-part z1) (imag-part z2))))

(define (mul-complex z1 z2)
	(make-from-mag-ang (* (magnitude z1) (magnitude z2))
		(+ (angle z1) (angle z2))))

(define (dev-complex z1 z2)
	(make-from-mag-ang (/ (magnitude z1) (magnitude z2))
		(- (angle z1) (angle z2))))

;2.4.2
(define (attach-tag type-tag contents)
	(cons type-tag contents))

(define (type-tag datum)
	(if (pair? datum)
		(car datum)
		(error "Bad tagged datum -- TPYE-TAG" datum)))

(define (contents datum)
	(if (pair? datum)
		(cdr datum)
		(error "BAD tagged datum -- CONTENTS" datum)))


(define (real-part z)
	(cond ((rectangular? z)
				(real-part-rectangular (contents z)))
			((polar? z)
				(real-part-polar (contents)))
			(else (error "Unknown type -- REAL-PART" z))))

(define (imag-part z)
	(cond ((rectangular? z)
				(imag-part-rectangular (contents z))
			((polar? z)
				(imag-part-polar (contents z)))
			(else (error "Unknown type -- IMAG-PART" z)))))

(define (magnitude z)
	(cond ((rectangular? z)
				(magnitude-rectangular (contents z))
			((polar? z)
				(magnitude-polar (contents z))
			(else (error "Unknown type -- MAGNITUDE" z))))))

(define (angle z)
	(cond ((rectangular? z)
				(angle-rectangular (contents z))
			((polar? z)
				(angle-polar (contents z))
			(else (error "Unknown type -- ANGLE" z))))))

(define (make-from-real-imag x y)
	(make-from-real-imag-rectangular x y))

(define (make-from-mag-ang r a)
	(make-from-mag-ang-polar r a))


(define num (make-from-mag-ang 1 45))
;(define num (make-from-real-imag 1 1))

(define (display-complex z)
	(display (magnitude z)))

(display-complex num)
(newline)

