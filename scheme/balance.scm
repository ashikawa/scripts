(load "./inc/std.scm")

(define (make-account balance)
	(define (withdraw amount)
		(if (>= balance amount)
			(begin (set! balance (- balance amount))
				balance)
			"Insufficient funds"))
	(define (deposit amount)
		(set! balance (+ balance amount))
			balance)
	(define (dispatch m)
		(cond ((eq? m 'withdraw) withdraw)
			((eq? m 'deposit) deposit)
			(else (error "Unknown request -- MAKE-ACCOUNT"
				m))))
	dispatch)


(define (make-account-with-secret password balance)
	(define acc (make-account balance))
	(define (dispatch-secret p m)
		(if (eq? p password)
			(acc m)
			"Inncorrect password "))
	dispatch-secret)



(define acc (make-account-with-secret 'pass 100))

(display ((acc 'pass 'withdraw) 50))
(newline)
(display ((acc 'pass 'withdraw) 60))
(newline)
(display ((acc 'pass 'deposit) 40))
(newline)
(display ((acc 'pass 'withdraw) 60))
(newline)

