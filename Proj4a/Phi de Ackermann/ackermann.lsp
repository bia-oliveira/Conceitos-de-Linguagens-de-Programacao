(defun ackermann-phi (m n p)
  (cond ((= p 0) (+ m n))
        ((and (= n 0) (= p 1)) 0)
        ((and (= n 0) (= p 2)) m)
        ((> p 2) p)
        ((and (> n 0) (> p 0)) (ackermann-phi m (ackermann-phi m (- n 1) p) (- p 1)))
        (t 0))) ; para casos não cobertos (deve-se evitar alcançar aqui)

(format t "ackermann-phi(2, 3, 0) = ~d~%" (ackermann-phi 2 3 0))