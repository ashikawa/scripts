(load "./inc/std.scm")

(define (deriv exp var)
	(cond ((number? exp) 0)
			((variable? exp)
				(if (same-variable? exp var) 1 0))
			((sum? exp)
				(make-sum (deriv (addend exp) var)
							(deriv (augend exp) var)))
			((product? exp)
				(make-sum
					(make-product (multiplier exp)
										(deriv (multiplicand exp) var))
					(make-product (deriv (multiplier exp) var)
										(multiplicand exp))))
			((power? exp)
				(make-product
					(make-power (multiplier exp) (- (multiplicand exp) 1))
					(multiplicand exp)))
			(else
				(error "unknown expression"))))


(define (variable? x) (symbol? x))

(define (same-variable? v1 v2)
	(and (variable? v1) (variable? v2) (eq? v1 v2)))

(define (sum? x) (is? x '+))

(define (product? x) (is? x '*))
;指数
(define (power? x) (is? x '**))

(define (is? x var)
	(and (pair? x) (eq? (car x) var)))

(define (addend s) (cadr s))

;(define (augend s) (caddr s))
(define (augend s) (caddr s))

;(define (make-sum a1 a2) (list '+ a1 a2))
(define (make-sum a1 a2)
	(cond ((=number? a1 0) a2)
			((=number? a2 0) a1)
			((and (number? a1) (number? a2)) (+ a1 a2))
			(else (list '+ a1 a2))))

(define (=number? exp num)
	(and (number? exp) (= exp num)))

;(define (make-product m1 m2) (list '* m1 m2))
(define (make-product m1 m2)
	(cond ((or (=number? m1 0) (=number? m2 0)) 0)
		((=number? m1 1) m2)
		((=number? m2 1) m1)
		((and (number? m1) (number? m2)) (* m1 m2))
		(else (list '* m1 m2))))

(define (make-power exp n)
		(cond ((=number? n 0) 1)
				((=number? n 1) exp)
				(else (list '** exp n))))

(define (multiplier p) (cadr p))

(define (multiplicand p) (caddr p))


(display (deriv '(+ x 3) 'x))
(newline)

(display (deriv '(* x y) 'x))
(newline)

(display (deriv '(* (* x y) (+ x 3)) 'x))
(newline)

(display (deriv '(+ (** x 3) (** x 2)) 'x))
(newline)


