SELECT DATE_FORMAT(trans_date,"%Y-%m") as month , country as country ,
      COUNT(*) as trans_count , SUM(IF(state = 'approved',1,0)) as approved_count,
      SUM(amount) as trans_total_amount,
      sum(IF(state = 'approved',amount,0)) as approved_total_amount
FROM Transactions
GROUP BY country ,DATE_FORMAT(trans_date,"%Y-%m") 
