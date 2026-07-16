SELECT stu.student_id as student_id ,stu.student_name as student_name ,sub.subject_name as subject_name ,
    count(exa.student_id) as attended_exams
FROM Students as stu CROSS JOIN Subjects as sub LEFT JOIN Examinations as exa
ON stu.student_id = exa.student_id AND sub.subject_name = exa.subject_name
GROUP BY stu.student_id , sub.subject_name
ORDER BY stu.student_id , sub.subject_name