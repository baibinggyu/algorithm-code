WITH user_with_orders as (
  SELECT
  t1.user_id as buyer_id , t1.join_date as join_date,COUNT(t3.item_id) as orders_in_2019
  FROM Users as t1 JOIN Orders as t2 JOIN  Items as t3
  ON t1.user_id = t2.buyer_id AND t2.item_id = t3.item_id
  WHERE YEAR(t2.order_date) = 2019
  GROUP BY t1.user_id
)
SELECT * FROM user_with_orders
UNION
SELECT user_id as buyer_id ,join_date as join_date,0 as orders_in_2019
FROM Users
WHERE user_id NOT IN (SELECT buyer_id FROM user_with_orders)
