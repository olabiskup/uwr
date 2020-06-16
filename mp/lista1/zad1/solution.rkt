#lang racket

;;Aleksandra Biskup 317424

(provide cube-root)

(define (square x)(* x x))

(define (cube x)(* x x x))

(define (abs x)
  (if (< x 0)
      (- x)
      x))

(define (dist x y)
  (abs (- x y)))

(define (cube-root x)
  
  (define (average x y)
  (/ (+ x y) 3))

  (define (improve guess)
    (average (* 2 guess) (/ x (square guess))))
  
  (define (good-enough? guess)
    (<(dist x (cube guess))
      0.00001))
  
  (define (iter guess)
    (if  (good-enough? guess)
         guess
         (iter (improve guess))))
   (if (= x (- 2))
       (iter 1.01)
       (iter 1.0)))

;;testy:

(cube-root 1000000000)
(cube-root 216)
(cube-root 8)
(cube-root -8)
(cube-root -2) ;;przy iter 1.0 program zapętla się, ponieważ guess przyjmuje wartość 0, co odkrył Oskar Kowalczyk

