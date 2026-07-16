SELECT product_name , unit_sum as unit
FROM (
  SELECT  t.product_name as product_name , SUM(unit) as unit_sum
  FROM (
    select pt.product_id as product_id , ot.order_date as order_date,
    pt.product_name as product_name , ot.unit
    from products as pt join orders ot
    on pt.product_id = ot.product_id
    where date_format(ot.order_date,'%Y-%m') = '2020-02'
  ) as t
  GROUP BY t.product_id
) as res
WHERE unit_sum >= 100
