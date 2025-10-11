#!/bin/bash

cpp_count=$(find . -type f -name "*.cpp" | wc -l)
c_count=$(find . -type f -name "*.c" | wc -l)
js_count=$(find . -type f -name "*.js" | wc -l)
py_count=$(find . -type f -name "*.py" | wc -l)

echo ".cpp 文件数量: $cpp_count"
echo ".c   文件数量: $c_count"
echo ".js  文件数量: $js_count"
echo ".py  文件数量: $py_count"
echo "总数: $((cpp_count + c_count + js_count + py_count))"
