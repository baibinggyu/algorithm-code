(
SELECT ut.name as results
FROM Users as ut JOIN MovieRating as rt
ON ut.user_id = rt.user_id
GROUP BY ut.user_id
ORDER BY COUNT(ut.name) DESC , ut.name ASC LIMIT 1
)

UNION all
(
SELECT mt.title FROM Movies as mt JOIN MovieRating as rt
ON mt.movie_id = rt.movie_id
WHERE DATE_FORMAT(rt.created_at,"%Y-%c") = "2020-2"
GROUP BY mt.movie_id
ORDER BY AVG(rt.rating) DESC , mt.title ASC LIMIT 1
)
