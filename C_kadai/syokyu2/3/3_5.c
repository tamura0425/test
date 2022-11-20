#include <stdio.h>
#include <math.h>

#define NOT_ANSWER 1000
int n, m, taro[100], hanako[100];
int ans1 = NOT_ANSWER, ans2 = NOT_ANSWER;

int search(int diff)
{
	int i, j;

	ans1 = ans2 = NOT_ANSWER;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (taro[i] - hanako[j] == diff) {
				if (taro[i] + hanako[j] < ans1 + ans2) {
					ans1 = taro[i];
					ans2 = hanako[j];
				}
			}
		}
	}
	return -1;
}

int main(void)
{
	int i;
	int taro_sum = 0, hanako_sum = 0;
	int ave, taro1, hanako1;

	while (1) {
		scanf("%d %d\n", &n, &m);
		if (n == 0 && m == 0)
			break;

		taro_sum = 0;
		hanako_sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &taro[i]);
			taro_sum += taro[i];
		}
		for (i = 0; i < m; i++) {
			scanf("%d", &hanako[i]);
			hanako_sum += hanako[i];
		}
		if( (taro_sum + hanako_sum) % 2 == 0) {
			ave = (taro_sum + hanako_sum) / 2;
			search(taro_sum - ave);
			if (ans1 != NOT_ANSWER && ans2 != NOT_ANSWER)
				printf("%d %d\n", ans1, ans2);
			else
				printf("-1\n");
		} else {
			printf("-1\n");
		}

	}
}
