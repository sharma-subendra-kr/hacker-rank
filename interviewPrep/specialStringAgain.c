// Special String Again
// https://www.hackerrank.com/challenges/special-palindrome-again/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=strings
//

#include <stdio.h>
#include <stdlib.h>

int main () {
	int count = 0, n;
	int map[26];
	char *str;
	int i, index, front, mid, last, iter, len;
	
	scanf("%d", &n);

	str = (char*) malloc(sizeof(char) * (n));
	scanf("%s", str);
	//printf("%s", str);
	
	/*	
	for (i = 0; i < 26; i++) {
		map[i] = 0;
	}

	for (i = 0; i < n; i++) {
		index = str[i] - 0 - 97;
		map[index]++;
	}
		
	for (i = 0; i < 26; i++) {
		count += map[i];
	}
	*/
	
	front = 0;
	for (i = 0; i < n; i++) {
		if (str[i] != str[i+1] && i < n-1) {	
			len = i - front + 1;
			count += ((len * (len + 1))/2);

			mid = i + 1;
			last = mid + (mid - front);
			iter = mid + 1;
			while (iter <= last && iter <= n-1) {
				if (str[iter] != str[front]) {
					break;
				}
				iter++;
			}
			if (iter != (mid + 1)) {
				count+=(iter - (mid + 1));
			}
			
			front = i + 1;
		} else if (i == n-1) {
			if (str[front] == str[i]) {
				len = i - front + 1;
				count += ((len * (len + 1))/2);		
			} else {
				count++;		
			}
		}
	}
	
	printf("%d", count);
}
