    CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    BEGIN
    RETURN (
        # Write your MySQL query statement below.
        Select Distinct(salary) from (SELECT salary,Dense_rank() over (ORDER BY salary DESC) as salary_rank FROM Employee ) as ranked_salary WHERE salary_rank = n
    );
    END