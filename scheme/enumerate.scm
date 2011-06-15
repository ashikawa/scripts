(load "./inc/std.scm")
(load "./inc/vector.scm")



(define (prime-sum? pair)
	(prime? (+ (car pair) (cadr pair))))

(define (make-pair-sum pair)
	(list (car pair) (cadr pair) (+ (car pair) (cadr pair))))

(define (flatmap proc seq)
			(accumulate append '() (map proc seq)))

(define (prime-sum-pairs n)
	(map make-pair-sum
			(filter prime-sum?
				(flatmap
				(lambda (i)
					(map (lambda (j) (list i j))
							(enumerate-interval 1 (- i 1))))
					(enumerate-interval 1 n)))))

(display-map (prime-sum-pairs 6))
(newline)

(display "-----unique-pairs-----\n")
(define (unique-pairs n)
				(flatmap
				(lambda (i)
					(map (lambda (j) (list i j))
							(enumerate-interval 1 (- i 1))))
					(enumerate-interval 1 n)))

(display-map (unique-pairs 6))

(newline)

