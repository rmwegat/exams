#include "bsq.h"

static int min3(int a, int b, int c) {
	int m = a < b ? a : b;
	return m < c ? m : c;
}

static void free_map(t_bsq *bsq) {
	if (!bsq->map)
		return;
	for (int i = 0; i < bsq->rows; i++)
		free(bsq->map[i]);
	free(bsq->map);
}

static int parse_header(FILE *f, t_bsq *bsq) {
	if (fscanf(f, "%d %c %c %c\n", &bsq->rows, &bsq->empty, &bsq->obstacle, &bsq->full) != 4)
		return 0;
	if (bsq->rows < 1 || bsq->empty == bsq->obstacle || bsq->empty == bsq->full || bsq->obstacle == bsq->full)
		return 0;
	return 1;
}

static int read_map(FILE *f, t_bsq *bsq) {
	char *line = NULL;
	size_t len = 0;
	
	bsq->map = malloc(bsq->rows * sizeof(char *));
	if (!bsq->map)
		return 0;
	
	for (int i = 0; i < bsq->rows; i++) {
		if (getline(&line, &len, f) == -1) {
			free(line);
			return 0;
		}
		
		int line_len = strlen(line);
		if (line[line_len - 1] == '\n')
			line_len--;
		
		if (i == 0)
			bsq->cols = line_len;
		else if (line_len != bsq->cols) {
			free(line);
			return 0;
		}
		
		bsq->map[i] = malloc(bsq->cols);
		if (!bsq->map[i]) {
			free(line);
			return 0;
		}
		
		for (int j = 0; j < bsq->cols; j++) {
			if (line[j] != bsq->empty && line[j] != bsq->obstacle) {
				free(line);
				return 0;
			}
			bsq->map[i][j] = line[j];
		}
	}
	free(line);
	return 1;
}

static void solve(t_bsq *bsq) {
	int **dp = malloc(bsq->rows * sizeof(int *));
	for (int i = 0; i < bsq->rows; i++)
		dp[i] = calloc(bsq->cols, sizeof(int));
	
	int max_size = 0, max_i = 0, max_j = 0;
	
	for (int i = 0; i < bsq->rows; i++) {
		for (int j = 0; j < bsq->cols; j++) {
			if (bsq->map[i][j] == bsq->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
			
			if (dp[i][j] > max_size) {
				max_size = dp[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	
	for (int i = max_i - max_size + 1; i <= max_i; i++)
		for (int j = max_j - max_size + 1; j <= max_j; j++)
			bsq->map[i][j] = bsq->full;
	
	for (int i = 0; i < bsq->rows; i++)
		free(dp[i]);
	free(dp);
}

static void print_map(t_bsq *bsq) {
	for (int i = 0; i < bsq->rows; i++) {
		for (int j = 0; j < bsq->cols; j++)
			putchar(bsq->map[i][j]);
		putchar('\n');
	}
}

static void process_file(FILE *f) {
	t_bsq bsq = {0};
	
	if (!parse_header(f, &bsq) || !read_map(f, &bsq)) {
		fprintf(stderr, "map error\n");
		free_map(&bsq);
		return;
	}
	
	solve(&bsq);
	print_map(&bsq);
	free_map(&bsq);
}

int main(int argc, char **argv) {
	if (argc < 2) {
		process_file(stdin);
	} else {
		for (int i = 1; i < argc; i++) {
			FILE *f = fopen(argv[i], "r");
			if (!f) {
				fprintf(stderr, "map error\n");
				continue;
			}
			process_file(f);
			fclose(f);
		}
	}
	return 0;
}
