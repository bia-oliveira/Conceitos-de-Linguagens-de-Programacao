(defun generate-random-list (n)
  (let ((lst nil))
    (dotimes (i n (nreverse lst))
      (push (random 100000) lst))))

(defun print-list (lst)
  (dolist (x lst)
    (format t "~d " x))
  (format t "~%"))
  
(defun bubble (lst)
  (cond
    ((null lst) nil)
    ((null (cdr lst)) lst)
    (t (let ((a (car lst))
             (b (cadr lst)))
         (if (> a b)
             (cons b (bubble (cons a (cddr lst))))
             (cons a (bubble (cdr lst))))))))

(defun bubble-sort (lst)
  (let ((sorted (bubble lst)))
    (if (equal sorted lst)
        sorted
        (bubble-sort sorted))))


(defun main ()
  (let ((list10 (generate-random-list 10))
        (list100 (generate-random-list 100))
        (list1000 (generate-random-list 1000))
        (list10000 (generate-random-list 10000))
        (list100000 (generate-random-list 100000)))
        
    (write (bubble-sort list10000))))

(main)
