(load "./inc/std.scm")


(define random-init 5)
(define (random-update x)
	(% (+ (* 11 x) 7) 100))

(define rand
	(let ((x random-init))
		(lambda ()
			(set! x (random-update x))
			x)))

(define (estimate-pi trials)
	(sqrt (/ 6 (monte-carlo trials cesaro-test))))

(define (cesaro-test)
	(= (gcd (rand) (rand)) 1))

(define (monte-carlo trials experiment)
	(define (iter trials-remaining trials-passed)
		(cond ((= trials-remaining 0)
			(/ trials-passed trials))
			((experiment)
				(iter (- trials-remaining 1) (+ trials-passed 1)))
		(else
			(iter (- trials-remaining 1) trials-passed))))
	(iter trials 0))


(display (estimate-pi 10000))
(newline)

;(define (estimate-pi trials)
;	(sqrt (/ 6 (random-gcd-test trials random-init))))



