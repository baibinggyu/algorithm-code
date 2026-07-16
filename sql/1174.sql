with firsttable as (
  select customer_id , min(order_date) as earliest
  from delivery
  group by customer_id
)


select round(
  (
    select count(*)
    from firsttable as t1 join delivery as t2
    on t1.customer_id = t2.customer_id and t1.earliest = t2.order_date
    where t2.order_date = t2.customer_pref_delivery_date
    ) / (
    select count(*)
    from firsttable as t1 join delivery as t2
    on t1.customer_id = t2.customer_id and t1.earliest = t2.order_date

  ) * 100.00,2
) as immediate_percentage
