# Write your MySQL query statement below
-- ON clause: Decides how rows are matched. If there's no match in a LEFT JOIN, the left row is still kept with NULLs.
-- WHERE clause: Filters the result after the join. If a WHERE condition fails (including because of NULL), the entire row is removed.
SELECT P.product_id,ROUND(IFNULL(SUM(P.PRICE*U.UNITS)/(SUM(U.UNITS)),0),2) AS average_price FROM PRICES P LEFT JOIN UNITSSOLD AS U ON P.PRODUCT_ID=U.PRODUCT_ID AND U.PURCHASE_DATE>=P.START_DATE AND U.PURCHASE_DATE<=P.END_DATE GROUP BY P.PRODUCT_ID;