# Write your MySQL query statement below
WITH order_counts AS (
    SELECT customerId as id, COUNT(customerId) as num
    FROM Orders
    GROUP BY customerId
)


SELECT name as Customers FROM Customers WHERE id NOT IN (SELECT id FROM order_counts);