SELECT customer_name, count(*)
FROM payments
GROUP BY customer_name
ORDER BY count DESC;

SELECT sum(amount), extract(year FROM processed_at) as year, extract(month from processed_at) as month
FROM payments,
GROUP BY month, year
ORDER BY sum DESC;

SELECT customer_name, sum(amount), extract(year from processed_at) as year, extract(month from processed_at) as month
FROM payments
GROUP BY customer_name, month, year
ORDER BY customer_name DESC;

SELECT max(amount), year, month
FROM (
    SELECT customer_name, sum(amount) as amount, extract(year from processed_at) as year, extract(month from processed_at) as month
    FROM payments
    GROUP BY customer_name, month, year
) AS monthly_sums
GROUP BY year, month;


BEGIN TRANSACTION;
UPDATE balances SET balance = balance - 100 WHERE username = 'clement';
UPDATE balances SET balance = balance + 100 WHERE username = 'antoine';
COMMIT;


SELECT * FROM large_table ORDER BY random_int DESC LIMIT 10;

CREATE INDEX large_table_random_int_idx ON large_table(random_int);
