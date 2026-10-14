SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS maxsalary
    FROM Employee
) AS t
WHERE maxsalary = 2;