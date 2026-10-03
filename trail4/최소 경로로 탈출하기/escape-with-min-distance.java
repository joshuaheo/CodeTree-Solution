import java.util.*;

public class Main {
    static int[] dr = { -1, 0, 1, 0 };
    static int[] dc = { 0, 1, 0, -1 };
    static int cnt = 0;
    static int n;
    static int m;

    static void pushing(Queue<int[]> q, int row, int col, int[][] a) {
        if (row > n - 1 || row < 0 || col > m - 1 || col < 0) {
            return;
        }
        if (a[row][col] == 0) {
            return;
        }
        q.offer(new int[] { row, col });
        a[row][col] = 0;
        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(a[i], 1);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = sc.nextInt();
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] { 0, 0 });
        a[0][0] = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz != 0) {
                int cur[] = q.poll();
                if (cur[0] == n - 1 && cur[1] == m - 1) {
                    System.out.printf("%d", cnt);
                    return;
                }
                for (int i = 0; i < 4; i++) {
                    int row = cur[0] + dr[i];
                    int col = cur[1] + dc[i];
                    pushing(q, row, col, a);
                }
                sz--;
            }
            cnt++;
        }
        System.out.print("-1");

        // Please write your code here.
    }
}