#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10

static int n, k;
static int parts[MAXN][MAXN];   // parts[i] holds elements of i-th subset
static int sz[MAXN];            // size of each subset

static char **lines = NULL;     // collected partitions as strings
static int L = 0, C = 0;

static char *my_strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *d = (char *)malloc(len);
    if (d) memcpy(d, s, len);
    return d;
}
static void add_line(const char *s) {
    if (L == C) {
        C = C ? C * 2 : 64;
        lines = (char **)realloc(lines, C * sizeof(char *));
    }
    lines[L++] = my_strdup(s);
}

static void emit_partition(int used) {
    char buf[1024];
    int p = 0;
    for (int i = 0; i < used; i++) {
        buf[p++] = '{';
        for (int j = 0; j < sz[i]; j++) {
            p += sprintf(buf + p, "%d", parts[i][j]);
            if (j + 1 < sz[i]) { buf[p++] = ','; buf[p++] = ' '; }
        }
        buf[p++] = '}';
        if (i + 1 < used) { buf[p++] = ','; buf[p++] = ' '; }
    }
    buf[p] = '\0';
    add_line(buf);
}

static void gen(int next, int used) {
    if (used > k) return;
    int remaining = n - next + 1;
    if (used + remaining < k) return;

    if (next > n) {
        if (used == k) emit_partition(used);
        return;
    }

    // Try putting next into existing subsets (unique generation)
    for (int i = 0; i < used; i++) {
        parts[i][sz[i]++] = next;
        gen(next + 1, used);
        sz[i]--;
    }

    // Start a new subset (at the end) if we still can
    if (used < k) {
        parts[used][0] = next;
        sz[used] = 1;
        gen(next + 1, used + 1);
        sz[used] = 0;
    }
}

static int cmp_lines(const void *a, const void *b) {
    const char *sa = *(const char * const *)a;
    const char *sb = *(const char * const *)b;
    return strcmp(sa, sb);
}

int main(void) {
    if (scanf("%d %d", &n, &k) != 2) return 0;

    memset(sz, 0, sizeof(sz));
    gen(1, 0);

    qsort(lines, L, sizeof(char *), cmp_lines);
    for (int i = 0; i < L; i++) {
        puts(lines[i]);
        free(lines[i]);
    }
    free(lines);
    return 0;
}