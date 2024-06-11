(defun generate-random-list (n)
  (let ((lst nil))
    (dotimes (i n (nreverse lst))
      (push (random 100000) lst))))

(defun print-list (lst)
  (dolist (x lst)
    (format t "~d " x))
  (format t "~%"))

(defun split (lst)
  (if (null lst)
      (values nil nil)
      (let ((l1 nil)
            (l2 nil))
        (loop for x in lst
              for i = 0 then (1+ i)
              do (if (evenp i)
                     (push x l1)
                     (push x l2)))
        (values (nreverse l1) (nreverse l2)))))

(defun my-merge (left right)
  (cond
    ((null left) right)
    ((null right) left)
    ((<= (car left) (car right)) (cons (car left) (my-merge (cdr left) right)))
    (t (cons (car right) (my-merge left (cdr right))))))

(defun merge-sort (lst)
  (if (or (null lst) (null (cdr lst)))
      lst
      (multiple-value-bind (left right) (split lst)
        (my-merge (merge-sort left) (merge-sort right)))))

(defun main ()
  (let ((list10 (generate-random-list 10))
        (list100 (generate-random-list 100))
        (list1000 (generate-random-list 1000))
        (list10000 (generate-random-list 10000))
        (list100000 (generate-random-list 100000)))
        
    (write (merge-sort list10000))))

(main)
