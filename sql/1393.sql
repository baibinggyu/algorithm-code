SELECT st.stock_name as stock_name , SUM(CASE WHEN operation = "Buy" THEN -price ELSE price END) as capital_gain_loss
FROM Stocks as st
GROUP BY st.stock_name
