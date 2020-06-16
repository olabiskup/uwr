#lang racket
;;Aleksandra Biskup 317424
(provide partition quicksort)

(define (partition n xs)
  (define (part left right xs)
    (if (null? xs)
        (cons left right)
        (if (> n (car xs))
            (part (append left (list(car xs))) right (cdr xs))
            (part left (append right (list(car xs))) (cdr xs)))))
  (part '() '() xs))
 
(define (quicksort xs)
  (if (< (length xs) 2)
      xs
      (let ([pivot (car xs)])
      (append (quicksort(car (partition pivot (cdr xs)))) (list pivot) (quicksort(cdr (partition pivot (cdr xs))))))))

;;testy:

;;Posortowana lista wejściowa to najgorszy przypadek dla quicksort'a, który jako pivot wybiera pierwszy element.
;;Listy po dokonaniu podziału są krótsze niż lista wejściowa: dla listy uporządkowanej rosnąco left pozostaje puste, right ma (length xs) - 1 elementów,
;;a pivot zostaje wstawiony pomiędzy te dwie listy. Dla listy malejącej - analogicznie.
(quicksort (list 1 2 3 4 5)) 
(quicksort (list 5 4 3 2 1))

(quicksort (list 4 1 3 5 2))
;;Przypadek o najbardziej optymistycznej złożoności czasowej to taki, w którym pivot będzie elementem środkowym listy, tj. zostanie ona podzielona dokładnie na pół.
(quicksort (list 3 1 5 2 4))

(quicksort (list 3 1 5 2 3 4 5 1 7 6 3))
