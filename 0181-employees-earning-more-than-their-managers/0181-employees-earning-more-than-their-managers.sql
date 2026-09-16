# Write your MySQL query statement below
Select e1.name as Employee
From Employee e1
Left Join Employee e2
On e1.managerId = e2.id
Where e1.salary > e2.salary