// Highest Value Palindrome
// https://www.hackerrank.com/challenges/richie-rich/problem
//

#include <stdio.h>
#include <stdlib.h>

int isPallindrome (char *pstr, int n, int mid) {
	int iter = 0, front, end;

	while (mid != 0) {
		front = iter;
		end = n - 1 - iter;
		if (pstr[front] != pstr[end]) {
			return 0;
		}
		mid--;
		iter++;
	}
	return 1;
}

int main () {
	char *pstr;
	int n, k, i, mid, iter, front, end, *map;
	
	scanf("%d%d", &n, &k);
	
	pstr = (char *) malloc(sizeof(char) * n);
	map = (int *) malloc(sizeof(int) * n);

	scanf("%s", pstr);

	for (i = 0; i < n; i++) {
		map[i] = 0;
	}
		
	mid = n/2;
	if (n % 2 != 0) {
		mid += 1;
	}
	
	// first pass
	while (mid != iter) {
		front = iter;
		end = n - 1 - iter;
		
		if (iter + 1 == mid && mid > n/2) {
			break;					
		}

		if (pstr[front] != pstr[end] && k > 0) {
			if (pstr[front] - '0' > pstr[end] - '0') {
				pstr[end] = pstr[front];
				map[end] = 1;
				k--;
			}	else {
				pstr[front] = pstr[end];
				map[front] = 1;
				k--;
			}
		}
		
		if (k == 0) {
			break;
		}

		iter++;
	}
	
	if (isPallindrome(pstr, n, mid) != 1) {
		printf("-1");
		exit(0);
	}
	
	iter = 0;	
	while (mid != iter) {
		front = iter;
		end = n - 1 - iter;
		
		if (iter + 1 == mid && mid > n/2) {
			if (pstr[front] != '9') {
				k--;
				pstr[front] = '9';
			}
			break;					
		}
	
		if ((map[front] == 1 || map[end] == 1) && pstr[front] != '9') {
			k--;
			pstr[front] = '9';
			pstr[end] = '9';
		} else if (pstr[front] != '9' && k > 1) {
			k-=2;
			pstr[front] = '9';
			pstr[end] = '9';
		}
		
		if (k == 0) {
			break;
		}

		iter++;
	}

	if (isPallindrome(pstr, n, mid)) {
		printf("%s", pstr);
	} else {
		printf("-1");
	}

	return 0;
}
