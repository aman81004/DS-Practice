# Write your MySQL query statement below

Select c.name As Customers
From Customers c
Left Join Orders o
On c.id = o.customerId
Where o.id Is NULL