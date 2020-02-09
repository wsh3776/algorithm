// 1185_Day of the Week
/* 根据给定日期计算是星期几
基姆拉尔森计算公式
W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1) mod 7

在公式中d表示日期中的日数，m表示月份数，y表示年数。

注意：在公式中有个与其他公式不同的地方：
把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
*/
string CaculateWeekDay(int y, int m, int d) {
    string res;
    if(m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int Weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch(Weekday) {
    case 0:
        res = "Monday";
        break;
    case 1:
        res = "Tuesday";
        break;
    case 2:
        res = "Wednesday";
        break;
    case 3:
        res = "Thursday";
        break;
    case 4:
        res = "Friday";
        break;
    case 5:
        res = "Saturday";
        break;
    case 6:
        res = "Sunday";
        break;
    }

    return res;
}

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        return CaculateWeekDay(year, month, day);
    }
};