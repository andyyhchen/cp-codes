#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>

#include <algorithm>

#define TESTCASE 20

int A[50000000], R[50000000];

void move(int n) {
	int i;
	for (i=0; i<n; i++)
		A[i] = R[i];
}

void generate(int n, int seed) {
	int i;
	srand(seed);
	for (i=0; i<n; i++) {
		R[i] = rand()*rand()*rand()*rand()*rand();
	}
}

inline void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

inline void insertion(int L, int R) {
	int i, j;
		for (i=L+1; i<=R; i++) {
			for (j=i; j>L; j--) {
				if (A[j] >= A[j-1]) break;
				swap(A[j], A[j-1]);
			}
		}
}

void quicksort(int L, int R) {
	int i, j = L;
	if (L < R-1) {
		swap(A[R], A[rand()%(R-L) + L]);
		for (i=L; i<R; i++)
			if (A[i] < A[R])
				swap(A[i], A[j++]);
		swap(A[R], A[j]);
		quicksort(L, j-1);
		quicksort(j+1, R);
	}
}

void introsort(int L, int R) {
	int i, j;
	if (R-L <= 16-1) {
		insertion(L, R);
	} else if (L < R-1) {
		swap(A[R], A[rand()%(R-L) + L]);
		for (i=j=L; i<R; i++)
			if (A[i] < A[R])
				swap(A[i], A[j++]);
		swap(A[R], A[j]);
		introsort(L, j-1);
		introsort(j+1, R);
	}
}

void introsort2(int L, int R) {
	int i, j, m;
	if (R-L <= 16-1) {
		insertion(L, R);
	} else if (L < R-1) {
		m = (L+R)/2;
		if (A[L] <= A[R]) {
			if (A[L]<=A[m] && A[m]<=A[R]) swap(A[m], A[R]);
			else if (A[m]<=A[L]) swap(A[L], A[R]);
		} else {
			if (A[R]<=A[m] && A[m]<=A[L]) swap(A[m], A[R]);
			else if (A[m]>=A[L]) swap(A[L], A[R]);
		}
		for (i=j=L; i<R; i++)
			if (A[i] < A[R])
				swap(A[i], A[j++]);
		swap(A[R], A[j]);
		introsort2(L, j-1);
		introsort2(j+1, R);
	}
}

void introsort3(int L, int R) {
	int i, j, m;
	if (R-L <= 16-1) {
		insertion(L, R);
	} else if (L < R) {
		m = (L+R)/2;
		if (A[R] <= A[L]) {
			if (A[R]<=A[m] && A[m]<=A[L]) swap(A[m], A[L]);
			else if (A[m]<=A[L]) swap(A[L], A[R]);
		} else {
			if (A[L]<=A[m] && A[m]<=A[R]) swap(A[m], A[L]);
			else if (A[m]>=A[R]) swap(A[R], A[L]);
		}
		i = L-1, j = R+1;
		while (1) {
			do -- j; while (A[j]>A[L]);
			do ++ i; while (A[i]<A[L]);
			if (i >= j) break;
			swap(A[i], A[j]);
		}
		swap(A[j], A[L]);
		introsort3(L, j-1);
		introsort3(j+1, R);
	}
}

inline int cmp(const void *A, const void *B) {
	int a = *(int*)A, b = *(int*)B;
	if (a == b) return 0;
	return a < b ? -1 : 1;
}

void QSort(int L, int R) {qsort(A+L, R-L+1, sizeof(int), cmp);}
void STLsort(int L, int R) {std::sort(A+L, A+R+1);}

const int sortNumber = 6;

void (*sortList[])(int,int) = {
	quicksort,
	introsort,
	introsort2,
	introsort3,
	QSort,
	STLsort
};

const char * sortName[] = {
	"quick",
	"intro",
	"intro2",
	"intro3",
	"qsort",
	"STLsort"
};

int main() {
	clock_t start, end;
	int T, i, n, MAX;
	FILE *fp = fopen("sorts.txt", "w");

	double t_run, i_sum = 0, t_sum[10] = {0};

	system("CLS");

	printf("How many numbers max> ");
	scanf("%d", &MAX);
	if (MAX == 0) MAX = 50000000;
	printf("\n");
	fprintf(fp, "%d numbers max.\n", MAX);

	fprintf(fp, "%32s", "");
	for (i=0; i<sortNumber; i++)
		fprintf(fp, "%10s", sortName[i]);
	fputc('\n', fp);

	printf("%14s", "");
	for (i=0; i<sortNumber; i++)
		printf("%10s", sortName[i]);
	putchar('\n');

	for (T=1; T<=TESTCASE; T++) {
		n = (int)(pow(MAX, double(T)/TESTCASE)+10.0);
		generate(n, 1313131);
		fprintf(fp, "Test case %2d, %8d numbers: ", T, n);
		printf("Test case %2d: ", T, n);
		i_sum += n;

		for (i=0; i<sortNumber; i++) {
			move(n);
			start = clock();
			(*sortList[i])(0, n-1);
			end = clock();
			t_run = double(end - start) / CLOCKS_PER_SEC;
			t_sum[i] += t_run*n;
			fprintf(fp, "%6.2lf sec", t_run);
			printf("%6.2lf sec", t_run);
		}

		fputc('\n', fp);
		printf("\n");
	}

	t_run = i_sum;

	fprintf(fp, "\nAll: %.0lf numbers\n\n", i_sum);
	for (i=0; i<sortNumber; i++) {
		fprintf(fp, "\t%11s average running time: %5.2lf sec\n", sortName[i], t_sum[i]/t_run);
	}
	fputc('\n', fp);

	printf("\nAll: %.0lf numbers\n\n", i_sum);
	for (i=0; i<sortNumber; i++) {
		printf("\t%11s average running time: %5.2lf sec\n", sortName[i], t_sum[i]/t_run);
	}

	putchar('\n');
	fclose(fp);
	system("PAUSE");
	return 0;
}
