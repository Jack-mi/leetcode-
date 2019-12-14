//
// Created by 刘小粟 on 2019/12/1.
//

#ifndef LEETCODE_Q12_H
#define LEETCODE_Q12_H
#include <string>

class Q12 {
public:
    string makeChar(int count, char c) {
        string ans = "";
        for (int i = 1;i <= count; i++) {
            ans += c;
        }
        return ans;
    }

    string makeString(int count, string s) {
        string ans = "";
        for (int i = 1;i <= count; i++) {
            ans += s;
        }
        return ans;
    }

    string calThousand(int& num) {
        string ans = "";
        int k = num/1000;
        ans = makeChar(k, 'M');
        num %= 1000;
        return ans;
    }

    string calHundred(int& num) {
        string ans = "";
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

    string calTen(int& num) {
        string ans = "";
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
    string calSingle(int& num) {
        string ans = "";
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
    string intToRoman(int num) {
        string s1 = calThousand(num);
        string s2 = calHundred(num);
        string s3 = calTen(num);
        string s4 = calSingle(num);
        return s1+s2+s3+s4;
    }
};


#endif //LEETCODE_Q12_H
