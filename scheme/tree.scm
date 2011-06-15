(load "./inc/std.scm")


(define (entry tree) (car tree))

(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))


(define (make-tree entry left right)
	(list entry left right))

(define (element-of-set? x set)
	(cond ((null? set) #f)
		((= x (entry set)) #t)
		((< x (entry set))
			(element-of-set? x (left-branch set)))
		((> x (entry set))
			(element-of-set? x (right-branch set)))))


(define (adjoin-set x set)
	(cond ((null? set) (make-tree x '() '()))
		((= x (entry set)) set)
		((< x (entry set))
			(make-tree (entry set)
				(adjoin-set x (left-branch set))
				(right-branch set)))
		((> x (entry set))
			(make-tree (entry set)
				(left-branch set)
				(adjoin-set x (right-branch set))))))


(define (tree->list-1 tree)
	(if (null? tree)
		'()
		(append (tree->list-1 (left-branch tree))
			(cons (entry tree)
				(tree->list-1 (right-branch tree))))))

(define (tree->list-2 tree)
	(define (copy-to-list tree result-list)
		(if (null? tree)
			result-list
			(copy-to-list (left-branch tree)
				(cons (entry tree)
					(copy-to-list (right-branch tree)
						result-list)))))
	(copy-to-list tree '()))



(define (list->tree elements)
	(car (partial-tree elements (length elements))))

(define (partial-tree elts n)
	(if (= n 0)
		(cons '() elts)
		(let ((left-size (quotient (- n 1) 2)))
			(let ((left-result (partial-tree elts left-size)))
				(let ((left-tree (car left-result))
					(non-left-elts (cdr left-result))
					(right-size (- n (+ left-size 1))))
				(let ((this-entry (car non-left-elts))
					(right-result (partial-tree (cdr non-left-elts)
						right-size)))
				(let ((right-tree (car right-result))
						(remaining-elts (cdr right-result)))
					(cons (make-tree this-entry left-tree right-tree)
						remaining-elts))))))))

;orginal list to tree
;(define (list-to-tree items set)
;	(map (lambda (x) (adjoin-set x set)) items))

;(define tree (list-to-tree (list 1 2 3 4 5 6 7 8) '()))

;(define tree (adjoin-set 3(adjoin-set 2 (adjoin-set 1 '()))))

;(display tree)
;(newline)

;(display (tree->list-1 tree))
;(newline)

;(display (tree->list-2 tree))
;(newline)


;(display (list->tree tree))

(display (list->tree (list 1 3 5 7 9 11)))
(newline)



