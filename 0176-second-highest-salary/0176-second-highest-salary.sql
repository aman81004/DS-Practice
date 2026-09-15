# Write your MySQL query statement below
Select MAX(salary) As secondHighestSalary 
From Employee
Where salary < (
    Select Max(salary)
    From Employee
);