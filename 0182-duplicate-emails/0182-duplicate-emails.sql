# Write your MySQL query statement below

    SELECT email as Email
    FROM Person
    group by email 
    HAVING count(email) > 1
