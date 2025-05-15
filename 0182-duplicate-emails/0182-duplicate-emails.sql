# Write your MySQL query statement below

SELECT email as Email from (
    SELECT email, count(email) as num 
    FROM Person
    group by email
) AS _
WHERE num > 1;