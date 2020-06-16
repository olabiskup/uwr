;;Aleksandra Biskup 317424

#lang racket

;;funkcje pomocnicze:
(provide cont-frac)

(define (square x) (* x x))

(define (abs x)
  (if (> x 0)
      x
      (- x)))

(define (dist x y) (abs (- x y)))

(define (close-to? x y)
  (< (abs (- x y)) 0.00001))

;;funkcja główna:
(define (cont-frac num den)
  (define (iter Nn Dn An-1 An-2 Bn-1 Bn-2 prev n)
;;An - licznik i Bn - mianownik przepisane z definicji
    (let
    ([An (+ (* Dn An-1)(* Nn An-2))]
     [Bn (+ (* Dn Bn-1)(* Nn Bn-2))])
     (define curr (/ An Bn))
     (if (close-to? prev curr)
         curr
         (iter (num (+ n 1)) (den (+ n 1)) An An-1 Bn Bn-1 curr (+ n 1)))))
  (iter (num 1) (den 1) 0.0 1.0 1.0 0.0 0.0 1))

;;funkcja licząca arctan (zadanie 8)
(define (atan-cf x)
  (cont-frac
   (lambda (i) (if (= i 1) x
                   (square (* x (- i 1)))))
   (lambda (i) (- (* 2 i) 1))))

;;testy z wykorzystaniem zadania 8 - porównuję wyniki mojej własnej funkcji z wbudowaną funkcją atan
(atan-cf 1)
(atan 1)
(atan-cf 0)
(atan 0)
(atan-cf -15)
(atan -15)
(atan-cf 7)
(atan 7)







                                 
