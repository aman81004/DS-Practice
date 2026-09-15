# Write your MySQL query statement below
Select 
    e.name As Employee
From 
    Employee e 
Join
    Employee m
    ON e.managerId = m.Id 
Where 
    e.salary > m.salary ;