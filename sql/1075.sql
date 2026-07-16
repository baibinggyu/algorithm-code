SELECT project_id , ROUND(AVG(experience_years),2) as average_years 
FROM Project as t1 JOIN Employee as t2
ON t1.employee_id = t2.employee_id
GROUP BY t1.project_id
