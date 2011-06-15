(load "./inc/std.scm")

(define (integral f a b dx)
	(define (add-dx x) (+ x dx))
	(* (sum f (+ a (/ dx 2.0)) add-dx b)
	dx))

(integral cube 0 1 0.01)

