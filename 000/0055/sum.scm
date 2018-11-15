(define (seq-sum acc n end)
  (define (add f)
    (+ (f acc) (sum (f acc) (+ 1 n) end)))
  (cond ((> n end) 1)
        ((zero? (modulo n 2))
         (add (lambda (n) (* n 2))))
        (else
          (add (lambda (n) (/ n 3))))))
(seq-sum 1 2 10) ; 211/27
