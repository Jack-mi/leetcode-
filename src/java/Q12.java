package java;

public class Q12 {
    /*
    I             1
    IV            4
    V             5
    IX            9

    X             10
    XL            40
    L             50
    XC            90

    C             100
    CD            400
    D             500
    CM            900

    M             1000

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    1987 = 1000 + 900 + 50 + 10 + 10 + 10 + 5 + 2
    */
    public String makeChar(int count, char c) {
        String ans = "";
        for (int i = 1;i <= count; i++) {
            ans += c;
        }
        return ans;
    }

    public String makeString(int count, String s) {
        String ans = "";
        for (int i = 1;i <= count; i++) {
            ans += s;
        }
        return ans;
    }

    public String calThousand(int num) {
        String ans = "";
        int k = num/1000;
        ans = makeChar(k, 'M');
        num %= 1000;
        return ans;
    }

    public String calHundred(int num) {
        String ans = "";
        int k = num/100;
        if (k == 9) {
            ans += makeString(1, "CM");
        } else if (k >= 5) {
            ans += makeChar(1, 'D');
            k -= 5;
            ans += makeChar(k, 'C');
        } else if (k >= 4) {
            ans += makeString(1, "CD");
        } else {
            ans += makeChar(k, 'C');
        }
        num %= 100;
        return ans;
    }

    public String calTen(int num) {
        String ans = "";
        int k = num/10;
        if (k == 9) {
            ans += makeString(1, "XC");
        } else if (k >= 5) {
            ans += makeChar(1, 'L');
            k -= 5;
            ans += makeChar(k, 'X');
        } else if (k >= 4) {
            ans += makeString(1, "XL");
        } else {
            ans += makeChar(k, 'X');
        }
        num %= 10;
        return ans;
    }
    public String calSingle(int num) {
        String ans = "";
        int k = num;
        if (k == 9) {
            ans += makeString(1, "IX");
        } else if (k >= 5) {
            ans += makeChar(1, 'V');
            k -= 5;
            ans += makeChar(k, 'I');
        } else if (k >= 4) {
            ans += makeString(1, "IV");
        } else {
            ans += makeChar(k, 'I');
        }
        return ans;
    }
    public String intToRoman(int num) {
        String s1 = calThousand(num);
        String s2 = calHundred(num);
        String s3 = calTen(num);
        String s4 = calSingle(num);
        return s1+s2+s3+s4;
    }

}
