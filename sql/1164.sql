WITH BeforeDate as (
  SELECT * 
  FROM Products 
  WHERE change_date <= "2019-08-16"
  ), name as (
  SELECT DISTINCT product_id
  FROM Products
)

SELECT t1.product_id , t2.new_price as price 
FROM (
  SELECT product_id , MAX(change_date) as date
  FROM BeforeDate
  GROUP BY product_id
) as t1 JOIN Products as t2
ON t1.date = t2.change_date AND t1.product_id = t2.product_id
UNION
SELECT product_id , 10 as price
FROM name 
WHERE product_id not in (
  SELECT product_id
  FROM BeforeDate
)
