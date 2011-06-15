(load "./inc/std.scm")
(load "./inc/queue.scm")


(define q1 (make-queue))

(insert-queue! q1 'a)
(display q1)
(newline)

(insert-queue! q1 'b)
(display q1)
(newline)

(delete-queue! q1)
(display q1)
(newline)

(print-queue q1)
(newline)

(delete-queue! q1)
(display q1)
(newline)




