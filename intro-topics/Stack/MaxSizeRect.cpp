#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4


int maxHist(int row[]) {
	stack<int> result;

	int topVal, maxArea = 0, area = 0, i = 0;
	while (i < C) {
		// If this bar is higher than the bar on top stack,
		// push it to stack
		if (result.empty() || row[result.top()] <= row[i]) result.push(i++);
		else {
			// If this bar is lower than top of stack, then
			// calculate area of rectangle with stack top as
			// the smallest (or minimum height) bar. 'i' is
			// 'right index' for the top and element before
			// top in stack is 'left index'
			topVal = row[result.top()];
			result.pop();
			area = topVal * i;

			if (!result.empty())
				area = topVal * (i - result.top() - 1);
			maxArea = max(area, maxArea);
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (!result.empty()) {
		topVal = row[result.top()];
		result.pop();
		area = topVal * i;
		if (!result.empty())
			area = topVal * (i - result.top() - 1);

		maxArea = max(area, maxArea);
	}
	return maxArea;
}

// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle(int A[][C])
{
	// Calculate area for first row and initialize it as
	// result
	int result = maxHist(A[0]);

	// iterate over row to find maximum rectangular area
	// considering each row as histogram
	for (int i = 1; i < R; i++) {

		for (int j = 0; j < C; j++)

			// if A[i][j] is 1 then add A[i -1][j]
			if (A[i][j])
				A[i][j] += A[i - 1][j];

		// Update result if area with current row (as last
		// row) of rectangle) is more
		result = max(result, maxHist(A[i]));
	}

	return result;
}

// Driver code
int main()
{
	int A[][C] = {
		{ 0, 1, 1, 0 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 0 },
	};

	cout << "Area of maximum rectangle is "
		<< maxRectangle(A);

	return 0;
}
