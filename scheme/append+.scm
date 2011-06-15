(load "./inc/std.scm")


(define (append! x y)
	(set-cdr! (last-pair x) y)
	x)

(define (last-pair x)
	(if (null? (cdr x))
		x
		(last-pair (cdr x))))

(define x (list 'a 'b))

(define y (list 'c 'd))

(define z (append x y))

(display z)
(newline)

(display (cdr x))
(newline)

(define w (append! x y))

(display w)
(newline)

(display (cdr x))
(newline)




(define (make-cycle x)
	(set-cdr! (last-pair x) x)
	x)

(define z2 (make-cycle (list 'x 'y 'z)))

;無限ループ
;(display z2)

