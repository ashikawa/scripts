(load "./inc/std.scm")


;ちなみにmapもある。
(define (map proc items)
	(if (null? items)
		'()
		(cons (proc (car items))
				(map proc (cdr items)))))

(define in (list -10 6 -3 1 7))

(display (map abs in))
(newline)

(display (map (lambda (x) (* x x)) in))
(newline)



;あるじゃん(怒
(for-each (lambda (x) (newline) (display x)) in)


(newline)

(define (foreach proc items)
	(if (null? items)
		'()
		(begin (proc (car items)) (foreach proc (cdr items)))))

(foreach (lambda (x) (newline) (display x)) in)

(newline)

