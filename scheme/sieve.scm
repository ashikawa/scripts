(load "./inc/stream.scm")

(define (integres-starting-from n)
	(cons-stream n (integres-starting-from (+ n 1))))

(define (sieve stream)
	(cons-stream
		(stream-car stream)
		(sieve (stream-filter
			(lambda (x)
				(not (divisible? x (stream-car stream))))
			(stream-cdr stream)))))

(define prime (sieve (integres-starting-from 2)))

(display (stream-ref prime 50))
(newline)



(define ones (cons-stream 1 ones))

(define (add-streams s1 s2)
	(stream-map + s1 s2))

;(define integres (cons-stream 1 (add-streams ones integres)))

;(display (stream-ref integres 1))
;(newline)

