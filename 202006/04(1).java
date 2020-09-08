import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main m = new Main();
        System.out.println(m.solve(sc.nextInt(), sc.next()));
    }
    int M = 998244353;
    int[] val2id = new int[67];
    int[] baseEle =   { 1,  2,     4,      6,     16,  26,  41,  42,  44,  46,  61,  62,  64,  66};
    int[][] convert = {{2},{4},{1,6,16},{6,4,64},{26},{46},{62},{64},{61},{66},{42},{44},{41},{46}};
    {
        Arrays.fill(val2id, -1);
        for (int i = 0; i < baseEle.length; i++) val2id[baseEle[i]] = i;
    }
    private int solve(int n, String s) {
        if (s.length() <= 2) return solveBase(val2id[Integer.parseInt(s)], n); // 96分
        else { // 4分
            int res = 0;
            for (int[] i : shorten(s, 0)) res = (res + solveBase(i[0], n - i[1])) % M;
            return res;
        }
    }
    
    private int solveBase(int id, int n) { // 矩阵快速幂
        int[][] init = new int[1][14]; init[0][0] = 1;
        int[][] mat = new int[14][14];
        for (int from  = 0; from < 14; from++) for (int to : convert[from]) mat[from][val2id[to]]++;
        while (n > 0) {
            if ((n & 1) == 1) init = mul(init, mat);
            mat = mul(mat, mat);
            n >>= 1;
        }
        return init[0][id];
    }

    private int[][] mul(int[][] a, int[][] b) { // 矩阵乘法
        int n = a.length, m = a[0].length, k = b[0].length;
        int[][] res = new int[n][k];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                for (int q = 0; q < m; q++)
                    res[i][j] = (int) ((res[i][j] + (long) a[i][q] * b[q][j] % M) % M);
        return res;
    }

    int[] ones = {'4', 6, '6', 4}; // 2种忽略掉16的1，和64的6的特殊情况
    private List<int[]> shorten(String s, int dep) { // 回溯到上层；处理首字母，因为首字母可能有>1种情况
        if (s.length() <= 2) {
            int id = val2id[Integer.parseInt(s)];
            return id == -1 ? Collections.EMPTY_LIST : Arrays.asList(new int[]{id, dep});
        }
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < ones.length; i += 2)
            if (ones[i] == s.charAt(0)) res.addAll(shorten(ones[i+1] + postShorten(s, 1), dep + 1));
        res.addAll(shorten(postShorten(s, 0), dep + 1));
        return res;
    }
    String[] pos = {"2", "4", "/", "16", "/", "64"};
    private String postShorten(String s, int idx) { // 唯一可能性的回溯，找不到就返回一个非法字符代表无解
        StringBuilder sb = new StringBuilder();
        while (idx < s.length()) {
            int i = 0;
            for (; i < pos.length; i++) {
                if (s.startsWith(pos[i], idx) || (idx == s.length() - 1 && pos[i].charAt(0) == s.charAt(idx))) {
                    idx += pos[i].length();
                    sb.append(i + 1);
                    break;
                }
            }
            if (i == pos.length) return "0"; // invalid number
        }
        return sb.toString();
    }
}