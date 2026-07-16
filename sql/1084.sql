SELECT DISTINCT t1.product_id , t1.product_name 
FROM Product as t1 JOIN Sales as t2
ON t1.product_id = t2.product_id
GROUP BY t1.product_id
HAVING MIN(t2.sale_date) >= '2019-01-01'
AND MAX(t2.sale_date) <= '2019-03-31'
