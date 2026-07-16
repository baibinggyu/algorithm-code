SELECT nt.unique_id as unique_id , et.name as name
FROM  Employees as et LEFT JOIN EmployeeUNI as nt
ON et.id = nt.id
