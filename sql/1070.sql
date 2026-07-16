SELECT t.product_id , t.year as first_year , t.quantity , t.price
FROM (
  SELECT * , RANK() OVER (PARTITION BY product_id ORDER BY year ASC) as rk
  FROM Sales
) as t
WHERE rk = 1
