# Write your MySQL query statement below
SELECT e.name AS Employee 
FROM Employee AS e
INNER JOIN Employee as m ON e.managerId=m.id AND e.salary > m.salary; 