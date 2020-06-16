#lang racket
;;Aleksandra Biskup 317424
;;Partnerka: Julita Osman
(provide merge split mergesort)

(define (merge left right)
  (define (merge-rec left right res)
    (cond  [(null? left) (append res right)]
           [(null? right) (append res left)]
           [(if (< (car left) (car right))
                     (merge-rec (cdr left) right (append res (list(car left))))
                     (merge-rec left (cdr right) (append res (list(car right)))))]))
  (merge-rec left right '()))

(define (split lst)
  (define n (floor(/(length lst)2)))
  (define (part1 lst res)
    (if (> (length lst) n)
        (part1 (cdr lst) (append res (list(car lst))))
        (cons res lst)))
  (part1 lst '()))

(define (mergesort lst)
  (if (< (length lst) 2)
      lst
      (merge (mergesort(car (split lst))) (mergesort(cdr (split lst))))))

;;testy

(mergesort (list 1 2 3 4 5)) 
(mergesort (list 5 4 3 2 1))

(mergesort (list 4 1 3 5 2))
(mergesort (list 3 1 5 2 4))

(mergesort (list 3 1 5 2 3 4 5 1 7 6 3))
