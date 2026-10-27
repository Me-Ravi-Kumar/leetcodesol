CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary
      from Employee
      order by Salary desc
      LIMIT N,1

  );
END