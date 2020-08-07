// Common Child
// https://www.hackerrank.com/challenges/common-child/problem
// Refer this page for explaination
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

#include <stdio.h>
#include <stdlib.h>

int main () {
	char s1[5000], s2[5000];
	int s1Len = 0, s2Len = 0, m, n;
	int i, j;
	int	**arr;

	for (i = 0; i < 5000; i++) {
		s1[i] = '\0';
		s2[i] = '\0';
	}	

	scanf("%s", s1);
	scanf("%s", s2);
	
	
	for (i = 0; i < 5000; i++) {
		if (s1[i] != '\0') {
			s1Len++;
		}

		if (s2[i] != '\0') {
			s2Len++;
		}
	}
	
	n = s1Len+1;
	m = s2Len+1;
	

	//printf("%d %d\n", s1Len, s2Len);
		
	if ((arr = (int **)malloc(n * sizeof(int*))) == NULL) {
		printf("error initializing memory for arr**");
	}
	for (i = 0; i < n; i++) {
		if ((arr[i] = (int *)malloc(m * sizeof(int))) == NULL) {
			printf("error initializing memory for arr[%d]", i);	
		}
	}

	for (i = 0; i < n; i++) {
		arr[i][0] = 0; 	
	}
	
	for (j = 0; j < m; j++) {
		arr[0][j] = 0;
	}
	
	for (i = 1; i <= s1Len; i++) {
		for (j = 1; j <= s2Len; j++) {
			if (s1[i-1] == s2[j-1]) {
				arr[i][j] = arr[i-1][j-1] + 1;
			} else {
				arr[i][j] = arr[i][j-1] > arr[i-1][j] ? arr[i][j-1] : arr[i-1][j];
			}
		}
	}
	
	printf("%d", arr[s1Len][s2Len]);

	/*
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	*/

	free(arr);

	return 0;
}
