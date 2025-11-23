CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE res INT;
    DECLARE skip INT;
    SET skip = N - 1;
    SELECT DISTINCT salary INTO res from Employee ORDER BY salary DESC limit skip,1;
  RETURN res;
END