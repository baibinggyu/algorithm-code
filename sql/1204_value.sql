WITH descTable as (
    SELECT person_name , weight
    FROM Queue 
    ORDER BY turn ASC 
)
SELECT person_name 
FROM (
    SELECT person_name , @pre := @pre + weight as pre_sum
    FROM descTable JOIN (SELECT @pre := 0) as tmp
) as t
WHERE pre_sum <= 1000
ORDER BY pre_sum DESC LIMIT 1
