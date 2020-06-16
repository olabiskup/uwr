#lang racket
;;Autorzy: Aleksandra Biskup, Krzysztof Chmiel

(require "leftist.rkt")
(provide heapsort)

(define (heapsort xs)
  (define (heapify lst res)
    (if (> (length lst) 0)
        (heapify (cdr lst) (heap-insert (car lst) res))
        res))
  (define (sort heap)
    (if (heap-empty? heap)
        null
        (cons (heap-min heap) (sort (heap-pop heap)))))
  (sort(heapify xs empty-heap)))


;;testy
;;(heapsort '(1 3 4 2 5 2 4))
;;(heapsort '(1 0 -2 5 2 2 3))
;;(heapsort '())