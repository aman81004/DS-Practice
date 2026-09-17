# Write your MySQL query statement below
Select customer_number
From Orders
Group By customer_number
ORDER BY COUNT(*) DESC
LIMIT 1