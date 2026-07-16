WITH preTable as (
    SELECT
    person_name ,
    SUM(weight) OVER (ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as pre_sum
    FROM
    Queue 
)
SELECT person_name FROM preTable
WHERE pre_sum <= 1000
order by pre_sum DESC LIMIT 1