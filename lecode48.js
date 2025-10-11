/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
	const n = matrix.length;
	const loop = n / 2;
	for(let i = 0;i < loop;++i)
	{
		const leftTop = i,rightDown = n - 1 -i;
		let lloop = rightDown - leftTop;
		for(let j = 0;j < lloop;++j) //第一次 rightDown = 2
		[matrix[leftTop][leftTop + j],matrix[leftTop + j][rightDown]] = [matrix[leftTop + j][rightDown],matrix[leftTop][leftTop + j]];
		for(let j = 0;j < lloop;++j)
		[matrix[leftTop][leftTop + j],matrix[rightDown][rightDown - j]] = [matrix[rightDown][rightDown - j],matrix[leftTop][leftTop + j]];
		for(let j = 0;j < lloop;++j)
		[matrix[leftTop][leftTop + j],matrix[rightDown - j][leftTop]] = [matrix[rightDown - j][leftTop],matrix[leftTop][leftTop + j]];
		}
};