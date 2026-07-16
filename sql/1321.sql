WITH time_sum as
(
    SELECT visited_on , SUM(amount) as amount
    FROM Customer
    GROUP BY visited_on
)
SELECT visited_on , amount , average_amount
FROM (
    SELECT  visited_on, SUM(amount) over (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW)  as amount ,
    ROUND((SUM(amount) over (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) ) / 7,2) as average_amount ,
    COUNT(*) over (ORDER BY visited_on  ROWS BETWEEN 6 PRECEDING AND CURRENT ROW ) as cnt
    FROM time_sum as tt
) as res 
WHERE cnt = 7