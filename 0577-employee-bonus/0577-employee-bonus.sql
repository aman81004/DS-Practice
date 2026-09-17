# Write your MySQL query statement below

Select e.name , b.bonus
From Employee e 
Left Join Bonus b 
On e.empId = b.empId
WHERE IFNULL(b.bonus, 0) < 1000;