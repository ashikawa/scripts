;(load "./inc/std.scm")

(define fail #f)

(define-syntax amb
	(syntax-rules ()
	((_) (fail))
	((_ a) a)
	((_ a b ...)
		(let ((fail0 fail))
			(call/cc
				(lambda (cc)
					(set! fail
						(lambda ()
							(set! fail fail0)
								(cc (amb b ...))))
									(cc a)))))))

(define (require p)
	(if (not p) (amb)))

(define (distinct? items)
	(cond ((null? items) #t)
		((null? (cdr items)) #t)
		((member (car items) (cdr items)) #f)
		(else (distinct? (cdr items)))))

(define (multiple-dwelling)
	(let ((baker (amb 1 2 3 4 5))
		(cooper (amb 1 2 3 4 5))
		(fletcher (amb 1 2 3 4 5))
		(miller (amb 1 2 3 4 5))
		(smith (amb 1 2 3 4 5)))
	(require
		(distinct? (list baker cooper fletcher miller smith)))
	(require (not (= baker 5)))
	(require (not (= cooper 1)))
	(require (not (= fletcher 5)))
	(require (not (= fletcher 1)))
	(require (> miller cooper))
	(require (not (= (abs (- smith fletcher)) 1)))
	(require (not (= (abs (- fletcher cooper)) 1)))
	(list
		(list 'bakerr baker)
		(list 'cooper cooper)
		(list 'fletcher fletcher)
		(list 'miller miller)
		(list 'smith smith))))


(display (multiple-dwelling))
(newline)

