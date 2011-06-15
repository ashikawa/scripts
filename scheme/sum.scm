(load "./inc/std.scm")

(define (inc n) (+ n 1))
(define (identity x) x)


(define (sum-cube a b) (sum cube a inc b))
(sum-cube 1 10)

(define (sum-int a b) (sum identity a inc b))
(sum-int 1 10)

