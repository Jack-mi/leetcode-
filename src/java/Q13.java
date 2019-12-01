package java;

public class Q13 {
    /*
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    * */
    public int project(char c) {
        int ans = 0;
        switch (c) {
            case 'I':
                ans = 1;
                break;
            case 'V':
                ans = 5;
                break;
            case 'X':
                ans = 10;
                break;
            case 'L':
                ans = 50;
                break;
            case 'C':
                ans = 100;
                break;
            case 'D':
                ans = 500;
                break;
            case 'M':
                ans = 1000;
                break;
        }
        return ans;
    }
    public int romanToInt(String s) {
        int ans = 0;
        for (int i = 0;i < s.length();i++) {
            char c = s.charAt(i);
            if (c == 'I' && i != s.length()-1) {
                if (s.charAt(i+1) == 'V') {
                    ans += 4;
                    i++;
                    continue;
                }
                if (s.charAt(i+1) == 'X') {
                    ans += 9;
                    i++;
                    continue;
                }
            } else if (c == 'X' && i != s.length()-1) {
                if (s.charAt(i+1) == 'L') {
                    ans += 40;
                    i++;
                    continue;
                }
                if (s.charAt(i+1) == 'C') {
                    ans += 90;
                    i++;
                    continue;
                }
            } else if (c == 'C' && i != s.length()-1) {
                if (s.charAt(i+1) == 'D') {
                    ans += 400;
                    i++;
                    continue;
                }
                if (s.charAt(i+1) == 'M') {
                    ans += 900;
                    i++;
                    continue;
                }
            }
            ans += project(c);
        }
        return ans;
    }
}
