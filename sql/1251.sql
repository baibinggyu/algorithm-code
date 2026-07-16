WITH join_table as (
    SELECT t01.product_id as product_id,start_date , end_date ,IF(units is NULL,0,units) as units , price
    FROM Prices as t01 LEFT JOIN UnitsSold as t02
    ON t01.product_id = t02.product_id AND purchase_date BETWEEN start_date AND end_date
)
SELECT product_id , IFNULL(ROUND(SUM(units * price) / SUM(units),2),0) as average_price
FROM join_table
GROUP BY product_id 