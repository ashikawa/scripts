(load "../inc/std.scm")
(load "./logical.scm")
(load "./agenda.scm")

(define (make-wire)
	(let ((signal-value 0) (action-procedures '()))
		(define (set-my-signal! new-value)
			(if (not (= signal-value new-value))
				(begin (set! signal-value new-value)
					(call-each action-procedures))
				'done))

	(define (accept-action-procedure! proc)
		(set! action-procedures (cons proc action-procedures))
		(proc))
	(define (dispatch m)
		(cond ((eq? m 'get-signal) signal-value)
			((eq? m 'set-signal!) set-my-signal!)
			((eq? m 'add-action!) accept-action-procedure!)
			(else (error "Unknown operation -- WIRE" m))))
	dispatch))


(define (call-each procedures)
	(if (null? procedures)
		'done
		(begin
			((car procedures))
			(call-each (cdr procedures)))))

(define (get-signal wire)
	(wire 'get-signal))

(define (set-signal! wire new-value)
	((wire 'set-signal!) new-value))

(define (add-action! wire action-procedure)
	((wire 'add-action!) action-procedure))




(define (inverter input output)
	(define (invert-input)
		(let ((new-value (logical-not (get-signal input))))
			(after-delay inverter-delay
				(lambda ()
					(set-signal! output new-value)))))
	(add-action! input invert-input)
	'ok)

(define (and-gate a1 a2 output)
	(define (and-action-procedure)
		(let ((new-value
				(logical-and (get-signal a1) (get-signal a2))))
			(after-delay and-gate-delay
				(lambda ()
					(set-signal! output new-value)))))
	(add-action! a1 and-action-procedure)
	(add-action! a2 and-action-procedure)
	'ok)

(define (or-gate a1 a2 output)
	(define (or-action-procedure)
		(let ((new-value
				(logical-or (get-signal a1) (get-signal a2))))
			(after-delay or-gate-delay
				(lambda ()
					(set-signal! output new-value)))))
	(add-action! a1 or-action-procedure)
	(add-action! a2 or-action-procedure)
	'ok)



(define (half-adder a b s c)
	(let ((d (make-wire)) (e (make-wire)))
		(or-gate a b d)
		(and-gate a b c)
		(inverter c e)
		(and-gate d e s)
		'ok))

(define (full-addr a b c-in sum c-out)
	(let ((s (make-wire))
		(c1 (make-wire))
		(c2 (make-wire)))
	(half-addr b c-in s c1)
	(half-addr a s sum c2)
	(or-gate c1 c2 c-out)
	'ok))


(define (after-delay delays action)
	(add-to-agenda! (+ delays (current-time the-agenda))
						action
						the-agenda))


(define (prob name wire)
	(add-action! wire
		(lambda ()
			(newline)
			(display name)
			(display " ")
			(display (current-time the-agenda))
			(display " New-value = ")
			(display (get-signal wire)))))


(define the-agenda (make-agenda))
(define inverter-delay 2)
(define and-gate-delay 3)
(define or-gate-delay 5)



(define a (make-wire))
(define b (make-wire))
(define c (make-wire))
(define d (make-wire))
(define e (make-wire))
(define s (make-wire))


(define (half-adder a b s c)
	(let ((d (make-wire)) (e (make-wire)))
		(or-gate a b d)
		(and-gate a b c)
		(inverter c e)
		(and-gate d e s)
		'ok))

(display (or-gate a b d))
(display (and-gate a b c))
(display (inverter c e))
(display (and-gate d e s))

(define input-1 (make-wire))
(define input-2 (make-wire))
(define sum (make-wire))
(define carry (make-wire))

(prob 'sum sum)
(prob 'carry carry)
(newline)

(half-adder input-1 input-2 sum carry)
(newline)

(set-signal! input-1 1)
(newline)

(propagate)

(set-signal! input-2 1)
(newline)

(propagate)
(newline)
