;;Aleksandra Biskup 317424

#lang racket
(provide nth-root)

(define (abs x)
  (if (> x 0)
      x
      (- x)))

(define (close-to? x y)
  (< (abs(- x y)) 0.0001))

(define (average x y)
  (/ (+ x y) 2))

(define (compose f g)
  (lambda (x) (f (g x))))

(define (identity f) f)

(define (repeated f n)
  (if(= n 0)
     identity
     (compose f (repeated f (- n 1)))))

(define (fixed-point f guess1)
  (define (try guess)
    (let ([next (f guess)])
      (if (close-to? guess next)
          next
          (try next))))
  (try guess1))

(define (average-damp f)
  (lambda (x) (average x (f x))))

(define (log2 x) (/ (log x) (log 2))) 

(define (nth-root n x)
  (fixed-point ((repeated average-damp (floor (log2 n)))
                (lambda (k) (/ x (expt k (- n 1)))))
  1.0))

;;testy

;;liczba tłumień jest równa (floor(log2 n))


(nth-root 2048 7) (display "Pierwiastek 7 stopnia z 2048. Liczba tłumień: ") (floor (log2 7))
(nth-root 2048 8) (display "Pierwiastek 8 stopnia z 2048. Liczba tłumień: ") (floor (log2 8))
(nth-root 2048 15) (display "Pierwiastek 15 stopnia z 2048. Liczba tłumień: ") (floor (log2 15))
(nth-root 2048 16) (display "Pierwiastek 16 stopnia z 2048. Liczba tłumień: ") (floor (log2 16))

(nth-root 21784 15)  (floor (log2 15))
(nth-root 21784 16)  (floor (log2 16))
(nth-root 21784 2)  (floor (log2 3))
(nth-root 21784 3)  (floor (log2 4))








