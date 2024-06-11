(defun generate-random-list (n)
  (let ((lst nil))
    (dotimes (i n (nreverse lst))
      (push (random 100000) lst))))

(defun print-list (lst)
  (dolist (x lst)
    (format t "~d " x))
  (format t "~%"))
  
(defun insert (x lst)
  (cond
    ((null lst) (list x))
    ((<= x (car lst)) (cons x lst))
    (t (cons (car lst) (insert x (cdr lst))))))

(defun insertion-sort (lst)
  (if (null lst)
      nil
      (insert (car lst) (insertion-sort (cdr lst)))))


(defun main ()
  (let ((list10 (generate-random-list 10))
        (list100 (generate-random-list 100))
        (list1000 (generate-random-list 1000))
        (list10000 (generate-random-list 10000))
        (list100000 (generate-random-list 100000)))
        
    (write (insertion-sort list10000))))

(main)
