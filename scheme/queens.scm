(load "./inc/std.scm")
(load "./inc/vector.scm")


(define empty-bord '())

(define (adjoin-position new-row k rest-of-queens)
		(cons (cons new-row k) rest-of-queens));

(define (safe? k positions)
	(define (diagonal a b)
		(let ((ax (car a))
				(ay (cdr a))
				(bx (car b))
				(by (cdr b)))
		(= (abs (- ax bx))
			(abs (- ay by))))) ;end of def diagonal
	(let ((last-queen (car positions))
			(rest-of-queens (cdr positions)))
	(cond ((null? rest-of-queens) #t)
			(else
				(let ((x (car last-queen))
						(y (cdr last-queen)))
					(null?
						(filter
							(lambda (pos)
								(cond ((= x (car pos)) #t)
										((= y (cdr pos)) #t)
										((diagonal last-queen pos) #t)
										(else #f)))
								rest-of-queens)))))))

(define (flatmap proc seq)
	(accumulate append '() (map proc seq)))

(define (queens bord-size)
	(define (queens-cols k)
		(if (= k 0)
			(list empty-bord)
			(filter
				(lambda (positions) (safe? k positions))
				(flatmap
					(lambda (rest-of-queens)
						(map (lambda (new-row)
							(adjoin-position new-row k rest-of-queens))
							(enumerate-interval 1 bord-size)))
					(queens-cols (- k 1))))))
(queens-cols bord-size))

(display-map (queens 8))
(newline)
