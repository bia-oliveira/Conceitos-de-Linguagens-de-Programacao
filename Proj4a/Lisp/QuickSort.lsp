(defun generate-random-list (n)
  (let ((lst nil))
    (dotimes (i n (nreverse lst))
      (push (random 1000000) lst))))

(defun print-list (lst)
  (dolist (x lst)
    (format t "~d " x))
  (format t "~%"))

(defun partition (pivot lst)
  (let ((less nil)
        (greater nil))
    (dolist (x lst)
      (if (<= x pivot)
          (push x less)
          (push x greater)))
    (values (nreverse less) (nreverse greater))))

(defun quick-sort (lst)
  (if (or (null lst) (null (cdr lst)))
      lst
      (let ((pivot (car lst)))
        (multiple-value-bind (less greater) (partition pivot (cdr lst))
          (append (quick-sort less) (list pivot) (quick-sort greater))))))

(defun main ()
  (let ((list10 (generate-random-list 10))
        (list100 (generate-random-list 100))
        (list1000 (generate-random-list 1000))
        (list10000 (generate-random-list 10000))
        (list100000 (generate-random-list 100000))
        (list1000000 (generate-random-list 1000000)))
        
    (write (quick-sort list100000))))

(main)
