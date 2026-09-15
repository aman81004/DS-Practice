# Write your MySQL query statement below
Select 
    d.name As Department ,
    e.name As Employee ,
    e.salary As Salary 
From 
    Employee e 
Join 
    Department d 
    On e.departmentId = d.id 
Where 
    ( e.departmentId , e.salary ) In (
        Select 
            departmentId ,
            MAX( salary )
        From 
            Employee 
        Group By 
            departmentId
    );