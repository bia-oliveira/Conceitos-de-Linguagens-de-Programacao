(defun A (m n)
  (cond ((= m 0) (+ n 1))
        ((= n 0) (A (- m 1) 1))
        (t (A (- m 1) (A m (- n 1))))))
        
;; Testando a função A de Peter e Robinson
(format t "A(4, 0) = ~d~%" (A 4 0))