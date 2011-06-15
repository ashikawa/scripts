(load "./inc/stream.scm")

(display
(stream-car
	(stream-cdr
		(stream-filter prime?
								(stream-enumerate-interval 10000 1000000))))
)
(newline)
