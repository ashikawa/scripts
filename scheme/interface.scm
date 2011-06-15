(load "./inc/std.scm")



(define (filter predicate sequence)
	(cond ((null? sequence) '())
			((predicate (car sequence))
			(cons (car sequence)
					(filter predicate (cdr sequence))))
			(else (filter predicate (cdr sequence)))))

(display (filter odd? (list 1 2 3 4 5)))
(newline)


(define (accumulate op initial sequence)
	(if (null? sequence)
		initial
		(op (car sequence)
			(accumulate op initial (cdr sequence)))))

(display (accumulate + 0 (list 1 2 3 4 5)))
(newline)


(define (enumerate-interval low high)
		(if (> low high)
		'()
		(cons low (enumerate-interval (+ low 1) high))))

(display (enumerate-interval 2 7))
(newline)


(define (enumerate-tree tree)
	(cond ((null? tree) '())
			((not (pair? tree)) (list tree))
			(else (append (enumerate-tree (car tree))
								(enumerate-tree (cdr tree))))))

(display (enumerate-tree (list 1 (list 2 (list 3 4 )) 5)))
(newline)


(define (sum-odd-squares tree)
	(accumulate +
					0
					(map square ( filter odd? (enumerate-tree tree)))))

(display (sum-odd-squares  (list 1 (list 2 (list 3 4 )) 5)))
(newline)

