//
//  main.c
//  OhMyC
//
//  Created by 申屠云飞 on 2018/5/16.
//  Copyright © 2018年 styf. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 计算球体积
 */
void qiuti_tiji(){
    float banjin = 10;
    float tiji = 4.0 / 3.0 * M_PI * banjin * banjin * banjin;
    printf("体积:%f\n",tiji);
}

/**
 计算球体积
 */
void qiuti_tiji2(){
    float banjin;
    printf("输入半径:");
    scanf("%f",&banjin);
    float tiji = 4.0 / 3.0 * M_PI * banjin * banjin * banjin;
    printf("体积:%f\n",tiji);
}

/**
 显示美金
 */
void meijin(){
    float amount;
    printf("Enter an amount:");
    scanf("%f",&amount);
    printf("With tax added:$%.2f\n",amount * 1.05);
}

/**
 求方程式的值
 */
void fangchengshi(){
    printf("X的值:");
    int x;
    scanf("%d",&x);
//    printf("%d\n",3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);
    printf("%d\n",((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6);
}

/**
 美元付钱
 */
void meiyuanfuqian(){
    printf("输入一个美元金额:");
    int amount;
    scanf("%d",&amount);
    
    int meiyuan20,meiyuan10,meiyuan5;
    meiyuan20 = amount / 20;
    amount = amount - meiyuan20 * 20;
    meiyuan10 = amount / 10;
    amount = amount - meiyuan10 * 10;
    meiyuan5 = amount / 5;
    amount = amount - meiyuan5 * 5;
    printf("20美元:%d\n",meiyuan20);
    printf("10美元:%d\n",meiyuan10);
    printf("5美元:%d\n",meiyuan5);
    printf("1美元:%d\n",amount);
}

/**
 计算贷款余额
 */
void daikuanyue(){
    printf("输入贷款金额:");
    float amount;
    scanf("%f",&amount);
    
    printf("输入利率:");
    float rate;
    scanf("%f",&rate);
    
    printf("输入每月还贷:");
    float payment;
    scanf("%f",&payment);
    
    double yueli;
    for (int i = 1; i < 4; i++) {
        yueli = amount * (rate / 100.0 / 12);
        amount = amount - payment + yueli;
        printf("第%d月后的贷款金额:%.2f\n",i,amount);
    }
}

/**
 日期输出
 */
void riqishuchu() {
    int mm,dd,yy;
    printf("输入一个日期(mm/dd/yyyy):");
    scanf("%d/%d/%d",&mm,&dd,&yy);
    printf("格式化后:%d%.2d%.2d\n",yy,mm,dd);
}

/**
 电话输出
 */
void dianhuashuchu() {
    int a, b, c;
    printf("输入手机号[(xxx) xxx-xxxx]:");
    scanf("(%d) %d-%d", &a, &b, &c);
    printf("格式化后:%d.%d.%d\n", a, b, c);
}

/**
 幻方
 */
void huanfnag() {
    //16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
    int a[16];
    for (int i = 0; i < 16; i++) {
        scanf("%d",&a[i]);
    }
    
    for (int i = 0; i < 16; i++) {
        printf("%4d",a[i]);
        if (i%4 == 3) {
            printf("\n");
        }
    }
   
    printf("行的和:%d %d %d %d\n",a[0] + a[1] + a[2] + a[3],a[4] + a[5] + a[6] + a[7],a[8] + a[9] + a[10] + a[11],a[12] + a[13] + a[14] + a[15]);
    printf("列的和:%d %d %d %d\n",a[0] + a[4] + a[8] + a[12],a[1] + a[5] + a[9] + a[13],a[2] + a[6] + a[10] + a[14],a[3] + a[7] + a[11] + a[15]);
    printf("交叉的和:%d %d\n",a[0] + a[5] + a[10] + a[15],a[3] + a[6] + a[9] + a[12]);
    
}

/**
 逆序打印两位数
 */
void nixuliangwei() {
    int a;
    printf("输入一个两位数:");
    scanf("%d",&a);
    int ge = a % 10;
    int shi = a / 10;
    ge = ge * 10 + shi;
    printf("新数:%.2d\n",ge);
}

/**
 逆序打印几位
 */
void nixujiwei() {
    int a;
    printf("输入一个数:");
    scanf("%d",&a);
    int weishu = 0;
    int temp = a;
    while (temp%10) {
        weishu++;
        temp = temp / 10;
    }
    int xin = 0;
    while (a%10) {
        temp = a%10;
        for (int i = weishu - 1; i > 0; i--) {
            temp *= 10;
        }
        xin += temp;
        weishu--;
        a = a / 10;
    }
    printf("逆序:%d\n",xin);
}

/**
 把十进制转为八进制
 */
void print10to8() {
    int a;
    printf("输入一个数:");
    scanf("%d",&a);
    int temp = 0;
    int weishu = 0;
    int xin = 0;
    while (a % 8) {
        temp = a % 8;
        for (int i = weishu; i > 0; i--) {
            temp *= 10;
        }
        weishu++;
        xin += temp;
        a = a / 8;
    }
    printf("8进制:%.5d\n",xin);
}

/**
 求最大公约数
 */
int gongyueshu() {
    int m, n, yushu;
    printf("输入两个数:");
    scanf("%d %d", &m, &n);
    while (n != 0) {
        yushu = m % n;
        m = n;
        n = yushu;
    }
    printf("最大公约数是:%d\n",m);
    return m;
}

/**
 约分
 */
void yuefen() {
    int m, n, yushu,mm,nn;
    printf("输入一个分数:");
    scanf("%d/%d", &m, &n);
    mm = m;
    nn = n;
    while (n != 0) {
        yushu = m % n;
        m = n;
        n = yushu;
    }
    
    printf("约分后:%d/%d\n",mm/m,nn/m);
}

/**
 打印日历
 */
void rili() {
    int days,start;
    printf("输入一个月的天数:");
    scanf("%d",&days);
    printf("该月起始日是星期几:");
    scanf("%d",&start);
    for (int i = - start + 2; i <= days; i++) {
        if (i <= 0) {
            printf("   ");
        }else{
            printf("%3d",i);
        }
        if ((i + start - 1)%7 == 0) {
            printf("\n");
        }

    }
    printf("\n");
}

/**
 数学常量e
 */
void qiue() {
    int n, fenmu;
    double e = 0;
    printf("输入一个n:");
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) {
        fenmu = 1;
        for (int j = 1; j <= i; j++) {
            fenmu *= j;
        }
        e += 1.0 / fenmu;
    }
    printf("e = %f\n",e);
}

/**7-4
 字母电话转换为数字
 */
void zimudianhua() {
    printf("输入一个字母电话:");
    char c;
    while ((c = getchar())) {
        if (c >= 65&&c <= 89) {
            switch (c) {
                case 65:case 66:case 67:
                    c = '2';
                    break;
                case 68:case 69:case 70:
                    c = '3';
                    break;
                case 71:case 72:case 73:
                    c = '4';
                    break;
                case 74:case 75:case 76:
                    c = '5';
                    break;
                case 77:case 78:case 79:
                    c = '6';
                    break;
                case 80:case 82:case 83:
                    c = '7';
                    break;
                case 84:case 85:case 86:
                    c = '8';
                    break;
                case 87:case 88:case 89:
                    c = '9';
                    break;
                default:
                    break;
            }
        }
        printf("%c",c);
    }
}

/**7-9
 12小时制转24小时制
 */
void shierzhuanershisi(){
    printf("输入一个12小时制时间:");
    int hour = 0;
    int minute = 0;
    bool hourEnd = false;
    bool needAdd = false;
    char ch;
    while ((ch = getchar())!='\n') {
        if (ch ==':') {
            hourEnd = true;
        }
        if (ch == 'p' || ch == 'P') {
            needAdd = true;
        }
        if (ch >= '0'&&ch <= '9') {
            if (hourEnd) {
                if (minute) {
                    minute *= 10;
                    minute += ch - 48;
                }else{
                    minute += ch - 48;
                }
            }else{
                if (hour) {
                    hour *= 10;
                    hour += ch - 48;
                }else{
                    hour += ch - 48;
                }
            }
        }
    }
    if (needAdd) {
        hour += 12;
    }
    
    printf("%d:%d\n",hour,minute);
}

/**7-10
 计算元音个数
 */
void tongjiyuanyin() {
    printf("输入一串英文字符:");
    char ch;
    int count = 0;
    while ((ch = getchar())!='\n') {
        switch (toupper(ch)) {
            case 'A':case 'E':case 'I':case 'O':case 'U':
                count++;
                break;
                
            default:
                break;
        }
    }
    printf("含有元音%d个\n",count);
}

/**
 7-11指定格式输出英文名
 */
void shuchuyingwenming() {
    
    printf("输入一个带空格的英文名:");
    char shou = getchar();
    
    while (getchar() != ' ') {
        
    }
    char xing;
    while ((xing = getchar()) != '\n')//获得姓氏
    {
        
        printf("%c",xing);
    }
    
    printf(", %c.\n", shou);//输出结果
}

/**
 7-12从左往右顺序求值
 */
void shunxuqiuzhi() {
    printf("输入一个表达式:");
    double zhi = 0;
    double shu;
    char opt;
    scanf("%lf",&shu);
    zhi += shu;
    while ((opt = getchar()) != '\n') {
        scanf("%lf",&shu);
        switch (opt) {
            case '+':
                zhi += shu;
                break;
            case '-':
                zhi -= shu;
                break;
            case '*':
                zhi *= shu;
                break;
            case '/':
                zhi /= shu;
                break;
            default:
                break;
        }
    }

    printf("计算结果:%f\n",zhi);
}

/**
 7-13计算平均词长
 */
void pingjuncichang() {
    printf("输入一个英文语句:");
    double pingjunzhi = 0;
    int length = 0;
    int count = 0;
    char ch;
    while ((ch = getchar())!='\n') {
        if (ch == ' ') {
            pingjunzhi += length;
            length = 0;
            count++;
        }else{
            length++;
        }
    }
    pingjunzhi += length;
    count++;
    
    printf("算平均词长%.1lf\n",pingjunzhi/count);
}

/**
 7-14牛顿方法求平方根
 */
void niudunfangfa() {
    printf("输入一个数:");
    int x;
    scanf("%d",&x);
    double y = 1;
    double ny = x / y;
    while (fabs(ny - y) >= 0.00001 * y) {
        y = (y + ny) / 2;
        ny = x / y;
    }
    printf("x的平方根:%lf\n",y);
}

/**
 8-5斐波那契数
 */
void feibonaqi() {
    int a[40] = {0,1};
    for (int i = 2; i < sizeof(a)/sizeof(a[0]); i++) {
        a[i] = a[i-2] + a[i-1];
    }
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d,",a[i]);
    }
}

/**
 8-1重复数字
 */
void chongfushuzi() {
    int num[10] = {0};
    int in;
    printf("输入一个数字:");
    scanf("%d",&in);
    int index = 0;
    while (in) {
        index = in%10;
        num[index]++;
        in /= 10;
    }
//    printf("重复数字:");
//    for (int i = 0; i < 10; i++) {
//        if (num[i] > 1) {
//            printf(" %d ",i);
//        }
//    }

    for (int i = 0; i < 10; i++) {
        printf(" %d ",i);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf(" %d ",num[i]);
    }
}

/**
 8-6b1ff转换
 */
void b1ff() {
    int i = 0;
    char ch[100];
    char c;
    printf("输入一串英文字符:");
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        switch (c) {
            case 'A':
                c = '4';
                break;
            case 'B':
                c = '8';
                break;
            case 'E':
                c = '3';
                break;
            case 'I':
                c = '1';
                break;
            case 'O':
                c = '0';
                break;
            case 'S':
                c = '5';
                break;
            default:
                break;
        }
        ch[i] = c;
        i++;
    }
    for (int j = 0; j < 10; j++) {
        ch[i] = '!';
        i++;
    }
    ch[i] = '\n';
    for (int j = 0; j < sizeof(ch)/sizeof(ch[0]); j++) {
        c = ch[j];
        printf("%c",c);
        if (c == '\n') {
            break;
        }
    }
}

/**
 8-7 5✖️5矩阵 行、列的和
 */
void wujuzhen() {
    int juzhen[5][5] = {{0}};
    for (int i = 0; i < 5; i++) {
        printf("输入第%d行:",i + 1);
        for (int j = 0; j < 5; j++) {
            scanf("%d",&juzhen[i][j]);
        }
    }
    int hang[5] = {0};
    int lie[5] = {0};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            hang[i] += juzhen[i][j];
            lie[i] += juzhen[j][i];
        }
    }
    printf("行: ");
    for (int i = 0; i < 5; i++) {
        printf(" %d ",hang[i]);
    }
    printf("\n列: ");
    for (int i = 0; i < 5; i++) {
        printf(" %d ",lie[i]);
    }
    printf("\n");
}

/**
 8-9随机走
 */
void suijizou() {
    char juzhen[10][10] = {{0}};
    char zimu[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            juzhen[i][j] = '.';
        }
    }
    
    srand((unsigned)time(NULL));
    int bushu = 0;
    int fangxiang = 0;
    int x = 0;
    int y = 0;
    juzhen[y][x] = zimu[bushu];
    bushu++;
    while (bushu < 26) {
        //检查可走的方向
        if ((juzhen[y][x-1] != '.' || x - 1 < 0)&&(y - 1 < 0 || juzhen[y - 1][x] != '.')&&(x + 1 > 9 || juzhen[y][x + 1] != '.')&&(y + 1 > 9 || juzhen[y + 1][x] != '.')) {
            //无路可走
            break;
        }
        
        fangxiang = rand()%4;
        switch (fangxiang) {
            case 0:{//向左
                if (x - 1 < 0 || juzhen[y][x - 1] != '.') {
                    continue;
                }else{
                    x--;
                }
                break;
            }
            case 1:{//向上
                if (y - 1 < 0 || juzhen[y - 1][x] != '.') {
                    continue;
                }else{
                    y--;
                }
                break;
            }
            case 2:{//向右
                if (x + 1 > 9 || juzhen[y][x + 1] != '.') {
                    continue;
                }else{
                    x++;
                }
                break;
            }
            case 3:{//向下
                if (y + 1 > 9 || juzhen[y + 1][x] != '.') {
                    continue;
                }else{
                    y++;
                }
                break;
            }
            default:
                break;
        }
        
        juzhen[y][x] = zimu[bushu];
        bushu++;
    }
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", juzhen[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

/**
 8-14颠倒语句单词
 you can cage a swallow can't you?
 */
void diandaoyujudanci(){
    char yuju[100][100] = {};
    char c;
    int length = 0;
    int count = 0;
    int allLength[100] = {};
    
    printf("输入一句英文语句:");
    while ((c = getchar())) {
        
        if (c == '.' || c == '?') {
            allLength[count] = length;
            count++;
            break;
        }else if (c == ' ') {
            allLength[count] = length;
            length = 0;
            count++;
        }else{
            yuju[count][length] = c;
            length++;
        }
    }
    
    for (int i = count - 1; i >= 0; i--) {
        length = allLength[i];
        for (int j = 0; j < length; j++) {
            printf("%c",yuju[i][j]);
        }
        if (i == 0) {
            printf("%c",c);
        }else{
            printf(" ");
        }
    }
    printf("\n");
}

/**
 8-15凯撒加密
 Go ahead,make my day.
 Jr dkhdg,pdnh pb gdb.
 */
void kaisajiami() {
    char yuju[100] = {};
    char ch;
    int index = 0;
    printf("输入一句英文语句:");
    while ((ch = getchar())) {
        yuju[index] = ch;
        index++;
        if (ch == '\n') {
            break;
        }
    }
    
    printf("输入一个间隔(1-25):");
    int jiange;
    scanf("%d",&jiange);
    
    char jiami[index - 1];
    for (int i = 0; i < index; i++) {
        ch = yuju[i];
        if (ch >= 'a'&&ch <= 'z') {
            if (ch + jiange > 'z') {
                ch = ((ch - 'a') + jiange)%26 + 'a';
            }else{
                ch += jiange;
            }
        }else if (ch >= 'A'&&ch <= 'Z') {
            if (ch + jiange > 'Z') {
                ch = ((ch - 'A') + jiange)%26 + 'A';
            }else{
                ch += jiange;
            }
        }
        jiami[i] = ch;
    }
    printf("加密后:");
    for (int i = 0; i < index; i++) {
        ch = jiami[i];
        printf("%c",ch);
    }
    printf("\n");
}

/**
 8-16判断两个单词是否变位词  smartest mattress
 */
void bianweici() {
    int first[26] = {};
    char ch;
    printf("输入第一个单词:");
    while ((ch = getchar())) {
        first[ch - 'a']++;
        if (ch == '\n') {
            break;
        }
    }
    
    printf("输入第二个单词:");
    while ((ch = getchar())) {
        first[ch - 'a']--;
        if (ch == '\n') {
            break;
        }
    }
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (first[i] != 0) {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        printf("是相位词\n");
    }else{
        printf("不是相位词\n");
    }
}

/**
 8-17 打印nxn的幻方
 */
void dayinNhuanfang() {
    printf("输入n的值:");
    int n;
    scanf("%d",&n);
    int hf[n][n];
    int hang = 0;
    int lie = n/2;
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hf[i][j] = 0;
        }
    }
    
    hf[hang][lie] = 1;

    int thang = 0;
    int tlie = 0;
    for (int i = 1; i < n * n; i++) {
        thang = hang;
        tlie = lie;

        hang--;
        if (hang < 0) {
            hang = n - 1;
        }
        lie++;
        if (lie == n) {
            lie = 0;
        }
        if (hf[hang][lie] != 0) {
            hang = thang + 1;
            lie = tlie;
        }

        hf[hang][lie] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d",hf[i][j]);
        }
        printf("\n");
    }
}

/**
 9-5计算n的位数
 */
int num_digits(int n) {
    int i = 0;
    while (n%10) {
        i++;
        n/=10;
    }
    printf("i=%d\n",i);
    return i;
}

/**
 9-6返回n的第k位数字
 */
int digit(int n,int k) {
    if (k <= 0||n <= 0) {
        return 0;
    }
    int weishu = num_digits(n);
    if (k > weishu) {
        return 0;
    }
    for (int i = 1; i < k; i++) {
        n /= 10;
    }
    return n%10;
}
//9-10返回数组最大数,平均值,正数数量
int arrayMax(int a[],int n) {
    if (n <= 0) {
        return 0;
    }else{
        //最大数
//        int temp = a[0];
//        for (int i = 1; i < n; i++) {
//            if (temp < a[i]) {
//                temp = a[i];
//            }
//        }
//        return temp;
        //平均值
//        double temp = 0;
//        for (int i = 1; i < n; i++) {
//            temp += a[i];
//        }
//        temp = temp / n;
//        return temp;
        //正数数量
        int temp = 0;
        for (int i = 1; i < n; i++) {
            if (a[i]) {
                temp++;
            }
        }
        return temp;
    }
}
//9-11计算等级的平均值
float compute_GPA(char grades[],int n) {
    float avg = 0;
    for (int i = 0; i < n; i++) {
        switch (toupper(grades[i])) {
            case 'A':
                avg += 4;
                break;
            case 'B':
                avg += 3;
                break;
            case 'C':
                avg += 2;
                break;
            case 'D':
                avg += 1;
                break;
            default:
                break;
        }
    }
    avg /= n;
    return avg;
}
//9-12数组相乘的和
double inner_product(double a[],double b[],int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] * b[i]);
    }
    return sum;
}
//9-18用递归求公约数
int gcd(int m,int n){
    if (n == 0) {
        return m;
    }else {
        return gcd(n, m % n);
    }
}

//9-1升序排列数组
void selection_sort(int a[],int n) {
    if (n > 1) {
        int maxValue = a[0];
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (maxValue < a[i]) {
                maxValue = a[i];
                maxIndex = i;
            }
        }
        a[maxIndex] = a[n-1];
        a[n-1] = maxValue;
        selection_sort(a, n-1);
    }
}
//9-6计算多项式的值
double duoxiangshi(int x) {
    return (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - x * x + 7 * x - 6;
}
//9-7幂递归
double midigui(int x,int n) {
    if (n == 0) {
        return 1;
    }else{
        if (n%2) {
            return x * midigui(x, n - 1);
        }else{
            return (midigui(x, n/2)) * (midigui(x, n/2));
        }
    }
}
//9-8掷骰子游戏
int roll_dice() {
    int one = 0;
    int two = 0;
    while (!one) {
        one = rand()%6;
    }
    while (!two) {
        two = rand()%6;
    }
    printf("You rolled:%d\n",one + two);
    return one + two;
}

bool play_game() {
    srand((unsigned)time(NULL));
    int roll = roll_dice();
    if (roll == 7 || roll == 11) {
        printf("You win!\n");
        return true;
    }else if (roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return false;
    }else{
        printf("Your point is %d\n",roll);
        roll = 0;
        while (roll != 7 && roll != 1 && roll != 4 && roll != 5 && roll != 6 && roll != 8 && roll != 9 && roll != 10) {
            roll = roll_dice();
            if (roll == 7) {
                printf("You lose!\n");
                return false;
            }else {
                printf("You win!\n");
                return true;
            }
        }
        printf("haha You lose!\n");
        return false;
    }
}

//10-1栈
#define STACK_SIZE 100
char contents[STACK_SIZE];
int top = 0;

void make_empty()
{
    top = 0;
}

bool is_empty()
{
    return top == 0;
}

bool is_full()
{
    return top == STACK_SIZE;
}

void push(char i)
{
    if (is_full()) {
        printf("满了\n");
    }else{
        contents[top++] = i;
    }
}

char pop()
{
    if (is_empty()) {
        printf("空的\n");
        return ' ';
    }else{
        return contents[--top];
    }
}

//11-4交换两个变量的值
void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
//11-5计算从0点开始当前时间
void split_time(long total_sec,int *hr,int *min,int *sec) {
    *sec = total_sec%60;
    total_sec -= *sec;
    *min = (int)total_sec/60;
    *hr = *min / 60;
    *min -= *hr * 60;
}
//11-6寻找第一第二大元素
void find_two_largest(int a[], int n, int *largest, int *second_largest) {
    *largest = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        }else if (a[i] > *second_largest) {
            *second_largest = a[i];
        }
    }
}
//11-7最大元素的指针
int *find_largest(int a[], int n) {
    int *max = &a[0];
    for (int i = 1; i < n; i++) {
        if (*max < a[i]) {
            max = &a[i];
        }
    }
    return max;
}

//12-3 首尾交换
#define NNN 10
void shouweijiaohuan() {
    int a[NNN] = {1,2,3,4,5,6,7,8,9,10};
    int *p = &a[0], *q = &a[NNN-1], temp;
    
    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
    
    for (int i = 0; i < NNN; i++) {
        printf("%d",a[i]);
    }
    printf("\n");
}

//12-6 指针算数运算修改函数
int zhizhen_sum_array(int *a, int n) {
    int sum = 0;
    for (int *p = a; p < a + n; p++) {
        sum += *p;
    }
    return sum;
}
//12-7 数组是否包含某个元素
bool zhizhen_search(const int a[], int n,int key) {
    for (const int *p = a; p < a + n; p++) {
        if (*p == key) {
            return true;
        }
    }
    return false;
}

//12-8 数组清0
void zhizhen_store_zeros(int a[],int n) {
    for (int *p = a; p < a + n; p++) {
        *p = 0;
    }
}

//12-9 数组元素乘的和
double zhizhen_inner_product(const double *a,const double *b,int n) {
    double sum = 0;
    const double *q = b;
    for (const double *p = a; p < a + n; p++) {
        sum += (*q) * (*p);
        q++;
    }
    return sum;
}
//12-12 找出数组最大和第二大元素
void zhizhen_find_two_largest(int *a, int n, int *largest, int *second_largest) {
    *largest = *a;
    for (int *p = a + 1; p < a + n; p++) {
        if (*largest < *p) {
            *second_largest = *largest;
            *largest = *p;
        }else if (*second_largest < *p) {
            *second_largest = *p;
        }
    }
}
//12-17 二维数组的和
int sum_two_dimensional_array(const int a[][4], int n) {
    int sum = 0;
    for (const int *p = &a[0][0]; p <= &a[n - 1][3]; p++) {
        sum += *p;
    }
    return sum;
}
//12-1 逆序打印输入
//Don't get mad,get even.
void zhizhen_nixudayin() {
    char a[100];
    char *pch = a;
    while (pch < a + 100) {
        *pch = getchar();
        if (*pch == '\n') {
            pch--;
            break;
        }
        pch++;
    }
    
    while (pch >= a) {
        printf("%c",*pch);
        pch--;
    }
    printf("\n");
}
//12-2 检查是否是回文
void check_huiwen() {
    char a[100],b[100];
    char *pch = a;
    char *ppch = b;
    while (pch < a + 100) {
        *pch = getchar();
        *ppch = *pch;
        if (*pch == '\n') {
            pch--;
            ppch = b;
            break;
        }else if ((*pch >= 'a'&&*pch <='z')||(*pch >= 'A'&&*pch <='Z')) {
            pch++;
            ppch++;
        }
    }
    
    bool flag = true;
    while (pch >= a) {
        if (toupper(*pch) != toupper(*ppch)) {
            flag = false;
            break;
        }
        pch--;
        ppch++;
    }
    
    if (flag) {
        printf("回文\n");
    }else{
        printf("不是回文\n");
    }
}
// 13.5 把参数中字母改为大写
void capitalize1(char *a,int n) {
//    for (int i = 0; i < n; i++) {
//        if (a[i] >= 'a'&&a[i] <= 'z') {
//            a[i] = toupper(a[i]);
//        }
//    }
//
    for (char *p = a; p < a + n; p++) {
        if (*p >= 'a'&&*p <= 'z') {
//            p[0] = toupper(p[0]);
            *p = toupper(*p);
        }
    }
}
// 13.6把foo替换为xxx
void censor(char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] == 'f'&&a[i+1] == 'o'&&a[i+2] == 'o') {
            a[i] = a[i+1] = a[i+2] = 'x';
        }
    }
}
//13.11
int mystrcmp(char *s, char *t) {
    while (*s == *t) {
        if (*s == '\0') {
            return 0;
        }
        s++;
        t++;
    }
    return *s - *t;
}
//13.12 获取扩展名
void get_extension(const char *file_name, char *extension) {
    int i;
    for (i = 0; i < strlen(file_name); i++) {
        if (file_name[i] == '.') {
            i++;
            break;
        }
    }
    strcpy(extension, &file_name[i]);
}
//13.13 生成首页
void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}
//13.17 检测后缀名是否正确
bool test_extension(const char *file_name,const char *extension) {
    while (*file_name) {
        if (*file_name == '.') {
            file_name++;
            break;
        }
        file_name++;
    }
    
    if (*file_name != '\0') {
        while (*file_name) {
            if (toupper(*file_name) == toupper(*extension)) {
                file_name++;
                extension++;
            }else{
                return false;
            }
        }
        return true;
    }
    return false;
}
//13.18
void remove_filename(char *url) {
    url+= 7;
    while (*url) {
        if (*url == '/') {
            url[0] = '\0';
            break;
        }
        url++;
    }
}
//13.1找出最小最大单词
void find_maxminword() {
    char a[100][20];
    int i = 0;
    char *smallest = "";
    char *largest = "";
    bool flag = false;
    while (1) {
        printf("输入一个单词:");
        scanf("%s",a[i]);
        if (strlen(a[i]) == 4) {
            flag = true;
        }
        if (strcmp(a[i], largest) > 0) {
            largest = a[i];
        } else if (strlen(smallest) == 0) {
            smallest = a[i];
        }else if (strcmp(a[i], smallest) < 0) {
            smallest = a[i];
        }
        
        if (flag) {
            break;
        }
        i++;
    }
    printf("最小单词:%s\n",smallest);
    printf("最大单词:%s\n",largest);
}
//13.8 7.5 返回十字拼字游戏的单词值
int compute_scrabble_value(const char *word) {
    int num = 0;
    while (*word) {
        switch (toupper(*word)) {
            case 'A':case 'E':case 'I':case 'L':case 'N':case 'O':case 'R':case 'S':case 'T':case 'U':
                num++;
                break;
            case 'D':case 'G':
                num+=2;
                break;
            case 'B':case 'C':case 'M':case 'P':
                num+=3;
                break;
            case 'F':case 'H':case 'V':case 'W':case 'Y':
                num+=4;
                break;
            case 'K':
                num+=5;
                break;
            case 'J':case 'X':
                num+=8;
                break;
            case 'Q':case 'Z':
                num+=10;
                break;
            default:
                break;
        }
        word++;
    }
    return num;
}
//13.9 7.10 返回一个单词的元音个数
int compute_vowel_count(const char * sentence) {
    int count = 0;
    while (*sentence) {
        if (toupper(*sentence) == 'A'||toupper(*sentence) == 'E'||toupper(*sentence) == 'I'||toupper(*sentence) == 'O'||toupper(*sentence) == 'U') {
            count++;
        }
        sentence++;
    }
    return count;
}

//13.10 7.11 修改一个姓名  jim green ==> green, J.
void reverse_name(char *name) {
    char namefisrt = *name;
    while (*name++ != ' ') {
        ;
    }
    printf("%s, %c.\n",name,toupper(namefisrt));
}

//13.11 7-13计算一个英文语句的平均单词长度
double compute_average_word_length(const char *sentence) {
    int wordcount = 0,charcount = 0;
    while (*sentence) {
        if (*sentence == ' ') {
            wordcount++;
        }else{
            charcount++;
        }
        sentence++;
    }
    wordcount++;
    return (double)charcount/wordcount;
}
//13.12 8-14 颠倒语句单词
void diandaoyujudanci2(const char *sentence) {
    char a[30][20];
    int i = 0;
    int j = 0;
    char end = ' ';
    while (*sentence) {
        if (*sentence != ' ') {
            if (*sentence == '.'||*sentence == '?' || *sentence == '!') {
                end = *sentence;
                break;
            }else{
                a[j][i] = *sentence;
            }
            i++;
        }else{
            a[j][i] = '\0';
            j++;
            i = 0;
        }
        sentence++;
    }
    
    for (int x = j; x >= 0; x--) {
        printf("%s",a[x]);
        if (x == 0) {
            printf("%c",end);
        }else{
            printf(" ");
        }
    }
    printf("\n");
}

//13.14  8-16判断两个单词是否变位词  smartest mattress
bool are_anagrams(const char *word1,const char *word2) {
    int a[26] = {};
    while (*word1) {
        a[*word1 - 'a']++;
        word1++;
    }
    while (*word2) {
        a[*word2 - 'a']--;
        word2++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i]) {
            return false;
        }
    }
    return true;
}
//13.16 12-1 逆序打印输入 Don't get mad,get even.
void reverse(char *message) {
    char *start = message;
    char *end = message + strlen(message) - 1;
    char temp = ' ';
    while (start <= end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("%s\n",message);
}

//void read_line(char str[],int n) {
//    int ch,i = 0;
//    while ((ch = getchar()) != '\n') {
//        if (i < n) {
//            str[i++] = ch;
//        }
//    }
//    str[i] = '\0';
//}
#define CONCAT(x,y) x##y
#define CONCAT2(x,y) CONCAT(x,y)
//14.2 数组元素个数
#define NELEMS(a) (sizeof(a)/sizeof(a[0]))
//14.6
#define DISP(f,x) printf(#f"(%g) = %g\n", x, f(x))
//14.8
#define LINE_FILE3(x,y) "Line "#x" of file "#y
#define LINE_FILE2(x,y) LINE_FILE3(x,y)
#define LINE_FILE LINE_FILE2(__LINE__,__FILE__)
//14.9
//(a)
#define CHECK(x,y,n) ((((x)>= 0)&&((y)>= 0)&&((x)<= n-1)&&((y)<= n-1))?1:0)
//14.11
#define ERROR(f,c) fprintf(stderr, f,c)
//14.12     11010
//14.15
//#define ENGLISH
#define FRENCH
//#define SPANISH
//14.16
#define PRAGMA(x) printf("%s\n",#x);
#define IDENT(x) PRAGMA(ident #x);

#include "justify.h"
#define DEBUGG
#include "debug.h"

struct haha {
    int i;
}p;

#include "inventory.h"
#include <ctype.h>
//struct {
//    int x,y;
//}x;
//
//struct {
//    int x,y;
//}y;

//16.2
//struct c {
//    double real;
//    double imaginary;
//};

//16.4
//typedef struct {
//    double real;
//    double imaginary;
//}Complex;

//16.5
struct date {
    int month,day,year;
};

int day_of_year(struct date d) {
    return d.day;
}
int compare_dates(struct date d1,struct date d2) {
    if (d1.year < d2.year) {
        return -1;
    }else if (d1.year > d2.year) {
        return 1;
    }
    if (d1.month < d2.month) {
        return -1;
    }else if (d1.month > d2.month) {
        return 1;
    }
    if (d1.day < d2.day) {
        return -1;
    }else if (d1.day > d2.day) {
        return 1;
    }
    return 0;
}

////16.6
//struct time {
//    int hours,minutes,seconds;
//};
//struct time split_time1(long total_seconds) {
//    int sec = total_seconds%60;
//    total_seconds -= sec;
//    int min = (int)total_seconds/60;
//    int hr = min / 60;
//    min -= hr * 60;
//    return (struct time){hr,min,sec};
//}

//16.7分数运算
struct fraction {
    int numerator,denominator;
};
//最简
struct fraction zuijian(struct fraction f) {
    int gongyueshu = gcd(f.numerator, f.denominator);
    f.numerator /= gongyueshu;
    f.denominator /= gongyueshu;
    return f;
}
//分数相加
struct fraction f_xiangjia(struct fraction f1,struct fraction f2) {
    int denominator = f1.denominator * f2.denominator;
    int numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    return zuijian((struct fraction){numerator,denominator});
}

//16.8
struct color {
    int red;
    int green;
    int blue;
};
//16.10矩形计算
struct point{int x,y;};
struct rectangle {struct point upper_left,lower_right;};
//面积
int r_mianji(struct rectangle r) {
    return r.upper_left.y * r.lower_right.x;
}
//中心
struct point r_zhongxin(struct rectangle r) {
    return (struct point){r.lower_right.x/2,r.upper_left.y/2};
}
//16.11
//8+8+4 = 20;

//16.12
//8+4+8+4+4

//16.13

#define RECTANGLE 1
#define CIRCLE 2

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int length,width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

//16.14
//面积
int s_mianji(struct shape s) {
    if (s.shape_kind == RECTANGLE) {
        return s.u.rectangle.length * s.u.rectangle.width;
    }else{
        return M_PI * s.u.circle.radius * s.u.circle.radius;
    }
}
//移动
struct shape s_move(struct shape s,int x,int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
}
//放大
struct shape s_fangda(struct shape s, double c) {
    if(s.shape_kind == RECTANGLE) {
        s.u.rectangle.width *= c;
        s.u.rectangle.length *= c;
    }else{
        s.u.circle.radius *= c;
    }
    return s;
}

//16.15
enum myday {
    MONDAY,
};

//16.18 国际象棋
typedef enum {
    bing,
    ma,
    xiang,
    che,
    huanghou,
    guowang,
    kong
}Piece;

typedef enum {
    white,
    black
}PColor;

typedef struct {
    Piece p;
    PColor c;
}Square;

//16.19
typedef enum {
    EM,
    SS
}Machine_type;

struct pinball_machine {
    char name[40];
    int year;
    Machine_type type;
    int players;
};
//16.1
#include "country.h"

//16.5 5-9输入两个日期比大小
void riqibidaxiao(void) {
    struct date d1;
    struct date d2;
    printf("输入第一个日期:(mm/dd/yy):");
    scanf("%d/%d/%d",&d1.month,&d1.day,&d1.year);
    printf("输入第二个日期:(mm/dd/yy):");
    scanf("%d/%d/%d",&d2.month,&d2.day,&d2.year);
    int flag = compare_dates(d1, d2);
    if (flag > 0) {
        printf("%d/%d/%d比较大\n",d1.month,d1.day,d1.year);
    }else if (flag < 0) {
        printf("%d/%d/%d比较大\n",d2.month,d2.day,d2.year);
    }else{
        printf("一样大\n");
    }
}

int compar(const void *a,const void *b) {
//    const int *aa = a;
//    const int *bb = b;
//    if (*aa > *bb) {
//        return 1;
//    }else if (*aa == *bb) {
//        return 0;
//    }else{
//        return -1;
//    }
    return *(int *)a - *(int *)b;
}

int compare(const void *p,const void *q) {
//    return strcmp(p, q);//错误
    return strcmp(* (char **)p, * (char **)q);
}
//17.1
void *my_malloc(int n) {
    void *p = malloc(n);
    if (p) {
        return p;
    }else{
        printf("内存溢出");
        exit(0);
    }
}
//17.2
char *duplicate(char *str) {
    char *copy = malloc(strlen(str) + 1);
    if (copy == NULL) {
        return NULL;
    }
    strcpy(copy, str);
    return copy;
}
//17.3
int *create_array(int n,int initial_value) {
    int *a = malloc(n * sizeof(int));
    if (a == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        a[i] = initial_value;
    }
    return a;
}
//17.5
//b c

//17.8

//17.11 计算链表中n出现的次数
struct node {
    int value;
    struct node *next;
};
int count_occurrences(struct node *list,int n) {
    int i = 0;
    for (struct node *node = list; node != NULL; node = node->next) {
        if (node->value == n) {
            i++;
        }
    }
    return i;
}
//17.12 找出最后一个包含n的节点
struct node *find_last(struct node *list,int n) {
    struct node *last = NULL;
    for (struct node *node = list; node != NULL; node = node->next) {
        if (node->value == n) {
            last = node;
        }
    }
    return last;
}
//17.14
struct node *delete_from_list(struct node*list,int n) {
    struct node *cur, *prev;
    for (cur = list,prev = NULL; cur != NULL && cur->value != n; prev = cur,cur = cur->next) {
        ;
    }
    if (cur == NULL) {
        return list;
    }
    if (prev == NULL) {
        list = list->next;
    }else{
        prev->next = cur->next;
    }
    free(cur);
    return list;
}
void delete_from_list1(struct node **list,int n) {
    struct node *cur, *prev;
    for (cur = *list,prev = NULL; cur != NULL && cur->value != n; prev = cur,cur = cur->next) {
        ;
    }
    
    if (prev == NULL) {
        *list = NULL;
        free(cur);
    }else{
        prev->next = cur->next;
        free(cur);
        *list = prev;
    }
}
//17.16
int sum(int (*f)(int),int start, int end) {
    return f(start) + f(end);
}

//17.5
int r_read_line(char str[], int n) {
    int ch = 0,i = 0;
    ch = getchar();
    if (ch == '\n'&&i == 0) {
        return i;
    }
    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

#define read_word_sort_initial 5
#define read_word_sort_max 20
void read_word_sort(void) {
    int i = 0,j = 0;
    char **chs = malloc(read_word_sort_initial * sizeof(char **));
    for (; ; ) {
        if (i == read_word_sort_initial) {
            printf("扩容");
            chs = realloc(chs,read_word_sort_initial * sizeof(char **) * 2);
        }
        
        chs[i] = malloc(read_word_sort_max + 1);
        printf("输入一个单词:");
        j = r_read_line(chs[i], read_word_sort_max);
        if (j == 0) {
            break;
        }else{
            i++;
        }
    }
    
    qsort(chs, i, 8, compare);
    for (int k = 0; k < i; k++) {
        printf("%s,",chs[k]);
    }
}

typedef int *Fcn(void);
typedef Fcn *Fcn_ptr;
typedef Fcn_ptr Fcn_ptr_array[10];
Fcn_ptr_array x;


extern int my_test_int;

void my_test(void){
    my_test_int--;
    printf("my_test = %d\n",my_test_int);
}

//18.2
//extern
//static

//18.4
// 0 50

//18.5
//0 0 1 0

//18.7
void test_const(int n) {

//    const int a = n;
//    int b = 1;
//    switch (b) {
//        case n:
//
//            break;
//
//        default:
//            break;
//    }
    
    printf("aaaaa");
}

//18.9
//(a)
typedef char X_Fun(int);
typedef X_Fun *X_Fun_Ptr;
typedef X_Fun_Ptr X_Fun_Ptr_Array[10];
//(b)
typedef int *A_Int_Ptr;
typedef A_Int_Ptr A_Int_Ptr_Array[5];
typedef A_Int_Ptr_Array *A_Int_Ptr_Array_Ptr;
typedef A_Int_Ptr_Array_Ptr aaa(int);
//(c)
typedef float *B_Return_Fun(int);
typedef B_Return_Fun *B_Return_Fun_Ptr;
typedef int bbb_fun(void);

//18.11
int (*fff(int a))[] {
//    int aaa[] = {1};
    return NULL;
}
int (*g(int a))(int) {
    return NULL;
}

//18.12
int f_r(double a) {
    return (int)a;
}

float f_p(long a) {
    return a + 1.1;
}

int (*f(float (*ff)(long),char *ch))(double) {
    return &f_r;
}

struct my_node {
    int value;
    struct my_node *node;
};

//位域 类型为unsigned int或signed int，否则会引起二义性
struct file_date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};

typedef unsigned char BYTE;
typedef unsigned short WORD;

//20.4
#define MK_COLOR(r,g,b) ((long)(b)<<16|(g)<<8|(r))
#define GET_BLUE(color) ((long)(color>>16))
#define GET_GREEN(color) ((color & 0x0000ff00)>>8)
#define GET_RED(color) (color & 0x000000ff)
//20.6
unsigned short swap_bytes(unsigned short i) {
    //0x1234
    return (i << 8) | (i >> 8);
}
//20.7
unsigned int rotate_left(unsigned int i, int n) {
    return (i << n) | (i >> (32 - n));
}
unsigned int rotate_right(unsigned int i, int n) {
    return (i >> n) | (i << (32 - n));
}
//20.8
//unsigned int f(unsigned int i, int m, int n) {
//    return (i >> (m+1-n) & ~(~0 << n);
//}

//20.9
int count_ones(unsigned char ch) {
    //(a)
//    int count = 0;
//    while (ch) {
//        if (ch&1) {
//            count++;
//        }
//        ch = ch >> 1;
//    }
//    return count;
    //(b)
    static int count = 0;
    if (ch) {
        if (ch&1) {
            count++;
        }
        return count_ones(ch >> 1);
    }else{
        return count;
    }
}

//20.12
unsigned short create_short(unsigned char high_byte,unsigned char low_byte) {
    return (high_byte << 8) + low_byte;
}

//20.14
struct my_float {
    unsigned int x : 23;
    unsigned int z : 8;
    unsigned int f : 1;
};

//20.15二义性

//20.16
typedef unsigned long DWORD;
union {
    struct {
        WORD ax;
        unsigned int :16;
        WORD bx;
        unsigned int :16;
        WORD cx;
        unsigned int :16;
        WORD dx;
        unsigned int :16;
    }word;
    struct {
        BYTE al;
        BYTE ah;
        unsigned int :16;
        BYTE bl;
        BYTE bh;
        unsigned int :16;
        BYTE cl;
        BYTE ch;
        unsigned int :16;
        BYTE dl;
        BYTE dh;
        unsigned int :16;
    }byte;
    struct {
        DWORD eax,ebx,ecx,edx;
    }dword;
} regs;

//20.1
union {
    struct {
        unsigned int x : 23;
        unsigned int z : 8;
        unsigned int f : 1;
    } my_float_l;
    float ff;
} my_float_union;

struct ss {
    char a;//1
    int b[2];//8
    float c;//4
};

//#include <stddef.h>
#include <stdio.h>

//22.12
int count_periods(const char *filename) {
    FILE *fp;
    int n = 0;
    int ch;
    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '.') {
                n++;
            }
        }
        fclose(fp);
    }
    return n;
}

//22.13 返回第n行的长度，第一行是1
int line_length(const char *filename, int n) {
    FILE *fp;
    int curr = 1;
    int length = 0;
    int ch;
    if ((fp = fopen(filename, "r")) != NULL) {
        while (curr < n) {
            fscanf(fp, "%*[^\n]");
            if (getc(fp) == EOF) {
                break;
            }
            curr++;
        }
        if (curr == n) {
            ch = getc(fp);
            while (ch != '\n'&&ch != EOF) {
                length++;
                ch = getc(fp);
            }
            return length;
        }
    }
    return 0;
}

//22.14 (a)
char *my_fgets(char * __restrict str, int n, FILE *fp) {
    //可以限制读取数量 fgets(str, sizeof(str), fp) 读入sizeof(str)-1个或读到换行符
    int c;
    int i = 0;
    while (i < n - 1) {
        if ((c = getc(fp)) == EOF) {
            if (i == 0 || ferror(fp)) {
                return NULL;
            }
            break;
        }
        str[i++] = c;
        if (c == '\n') {
            break;
        }
    }
    str[i] = '\0';
    return str;
}

//22.14 (b)
int my_fputs(const char * __restrict str, FILE * __restrict fp) {
    //不会自动加换行符,出错返回EOF，否则非负数
    while (*str != '\0') {
        if (putc(*str, fp) == EOF) {
            return EOF;
        }
        str++;
    }
    return 0;
}


#define KEY '&'
//22.6
void printFile(const char * filename) {
    printf("Offset");
    printf("   ");
    printf("                 ");
    printf("Bytes");
    printf("                 ");
    printf("   ");
    printf("Characters");
    printf("\n");
    
    printf("______");
    printf("   ");
    printf("_________________");
    printf("_____");
    printf("_________________");
    printf("   ");
    printf("__________");
    printf("\n");
    
    FILE *fp = fopen(filename, "rb");
    char array[10];
    
    for (int offset = 0; ; offset += 10) {
        size_t n = fread(array, sizeof(array[0]), 10, fp);
        if (n == 0) {
            printf("\n");
            break;
        }
        printf("%6d",offset);
        printf("   ");
        
        for (int i = 0; i < n; i++) {
            printf("%.2X",array[i]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        
        //不满10字节，补空格
        if (n < 10) {
            for (size_t i = n; i < 10; i++) {
                printf("  ");
                if (i != 9) {
                    printf(" ");
                }
            }
            printf("   ");
        }else{
            printf("   ");
        }
        
        for (int i = 0; i < n; i++) {
            if (isprint(array[i])) {
                printf("%c",array[i]);
            }else{
                printf(".");
            }
        }
        printf("\n");
    }

}
#include <float.h>
#include <limits.h>
#if INT_MAX < 100000
#error int type is too small
#endif

#if INT_MAX >= 100000
typedef int  Quan;
#else
typedef long int Quan;
#endif

#include <math.h>
#include <ctype.h>
#include <string.h>
//23.1
double round_nearest(double x,int n) {
    double power = pow(10, n);
    if (x > 0) {
        x = floor(x * power + 0.5)/power;
    }else{
        x = ceil(x * power - 0.5)/power;
    }
    return x;
}
//23.2
double evaluate_polynomial(double a[],int n,double x) {
    double sum = a[n];
    for (int i = n; i - 1 >= 0; i--) {
        sum = fma(sum, x, a[i - 1]);
    }
    return sum;
}
//22.4是否标识符（数字、字母、下划线组成，并以字母或下划线开始）
bool isbiaozhi(char *str) {
    //    isalnum(<#int _c#>)//是否字母或数字
    //    isalpha(<#int _c#>)//是否是字母
    for (int i = 0; i < strlen(str); i++) {
        if (i == 0&&isalpha(str[i]) == 0&&str[i] != '_') {
            return false;
        }else{
            if (isalnum(str[i]) == 0&&str[i] != '_') {
                return false;
            }
        }
    }
    return true;
}

//22.5 0x12
long int isshiliu(const char *str) {
    if (strlen(str) < 2) {
        return -1;
    }
    if (str[0] != '0'||str[1] != 'x') {
        return -1;
    }
    
    for (int i = 2; i < strlen(str); i++) {
        if (isxdigit(str[i]) == 0) {
            return -1;
        }
    }
    long int a;
    sscanf(&str[2], "%lx",&a);
    return a;
}

//22.8
int numchar(const char *s,char ch) {
    int count = 0;
    char *p = strchr(s, ch);
    while (p != NULL) {
        count++;
        p = strchr(p + 1, ch);
    }
    return count;
}

//22.11
void tihuantanhao(char *s,int n) {
    size_t len = strlen(s);
    if (len > n) {
        while (n > 0) {
            s[--len] = '!';
            n--;
        }
    }
}

//22.12(a)
char *my_strdup(const char *s) {
    size_t len = strlen(s);
    char *str = malloc(len + 1);
    if (str != NULL) {
        strcpy(str, s);
        str[len] = '\0';
        return str;
    }
    return NULL;
}
//22.12(b)
int my_stricmp(const char *s1,const char *s2) {
    while (toupper(*s1) == toupper(*s2)) {
        if (*s1 == '\0'&&*s2 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
//22.12(c)
void my_strlwr(char *s) {
    while (*s != '\0') {
        if (islower(*s)) {
            *s = toupper(*s);
        }else if (isupper(*s)){
            *s = tolower(*s);
        }
        s++;
    }
}
//22.12(d)
char *strrev(char *s) {
    size_t len = strlen(s);
    char *start = s;
    char *end = s + len - 1;
    char ch;
    while (end > start&&end != start) {
        ch = *end;
        *end = *start;
        *start = ch;
        start++;
        end--;
    }
    return s;
}

//22.12(e)
char *my_strset(char *s,char ch) {
    char *p = s;
    while (*p != '\0') {
        *p++ = ch;
    }
    return s;
}

//22.13 返回单词数量
int my_count_words(char *sentence) {
    int count = 0;
    char *p = strtok(sentence, " ");
    while (p != NULL) {
        count++;
        p = strtok(NULL, " ");
    }
    return count;
}

//23.1

void qiufangcheng(double a,double b,double c,double *x1,double *x2) {
    double nei = pow(b, 2) - 4 * a * c;
    if (nei < 0) {
        printf("根是复数！！！！！");
    }else{
        *x1 = (-b + nei)/(2 * a);
        *x2 = (-b - nei)/(2 * a);
    }
}
//#define NDEBUG
#include <assert.h>
#include <errno.h>
#include <signal.h>

void handler(int sig) {
    printf("Handler called for signal %d\n",sig);
}
void raise_sig(void) {
    raise(SIGINT);
}
#include <setjmp.h>

jmp_buf env;
void fff2(void) {
    printf("fff2 开始\n");//3
    longjmp(env, 1);
    printf("fff2 结束\n");
}

void fff1(void) {
    printf("fff1 开始\n");//2
    fff2();
    printf("fff1 结束\n");
}

//24.2
double try_math_fun(double (*fun)(double),double x,const char *msg) {
    errno = 0;
    double y = fun(x);
    if (errno != 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return y;
}

#define TRY_MATH_FCN(fun,x) try_math_fun(fun, x, "Error in call of " #fun)

#include <locale.h>
#include <iso646.h>
#include <wchar.h>
#include <wctype.h>
#include <stdarg.h>


int max_int(int n, ...)
{
    va_list ap;
    int i, current, largest;
    va_start(ap, n);
    largest = va_arg(ap, int);
    
    for (i = 1; i < n; i++) {
        current = va_arg(ap, int);
        if (current > largest) {
            largest = current;
        }
    }
    
    va_end(ap);
    return largest;
}

int errorf(const char *format, ...) {
    static int num_errors = 0;
    int n;
    va_list ap;
    
    num_errors++;
    fprintf(stderr, "** Error %d: ", num_errors);
    va_start(ap, format);
    n = vfprintf(stderr, format, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    return n;
}
//26.1
int my_max_int(int n, ...) {
    va_list ap;
    int current, largest;
    va_start(ap, n);
    largest = n;
    while ((current = va_arg(ap, int)) != 0) {
        if (current > largest) {
            largest = current;
        }
    }
    va_end(ap);
    return largest;
}
//26.2
void my_simple_print(const char *format,...) {
    int cur,next,i = 0,digit = 0;
    va_list ap;
    va_start(ap, format);
    while ((cur = format[i]) != '\0') {
        next = format[i + 1];
        if (cur == '%'&&next == 'd') {
            cur = va_arg(ap, int);
            if (cur > 9) {
                int temp = cur;
                int pow = 1;
                while (temp > 9) {
                    temp /= 10;
                    pow *= 10;
                }
                
                do {
                    digit = cur/pow;
                    putchar(digit + '0');
                    cur -= digit * pow;
                    pow /= 10;
                } while (cur > 0);
                
            }else{
                putchar(cur + '0');
            }
            i+=2;
        }else{
            putchar(cur);
            i++;
        }
    }
    va_end(ap);
}

//26.3
void my_simple_print_s(const char *format,...) {
    int cur,next,i = 0,digit = 0;
    char *s;
    va_list ap;
    va_start(ap, format);
    while ((cur = format[i]) != '\0') {
        next = format[i + 1];
        if (cur == '%'&&next == 'd') {
            cur = va_arg(ap, int);
            if (cur > 9) {
                int temp = cur;
                int pow = 1;
                while (temp > 9) {
                    temp /= 10;
                    pow *= 10;
                }
                
                do {
                    digit = cur/pow;
                    putchar(digit + '0');
                    cur -= digit * pow;
                    pow /= 10;
                } while (cur > 0);
                
            }else{
                putchar(cur + '0');
            }
            i+=2;
        }else if (cur == '%'&&next == 's') {
            s = va_arg(ap, char *);
            fputs(s, stdout);
            i+=2;
        }else{
            putchar(cur);
            i++;
        }
    }
    va_end(ap);
}

//26.4
void display(int n, ...) {
    va_list ap;
    va_start(ap, n);
    char *s;
    for (int i = 0; i < n; i++) {
        s = va_arg(ap, char *);
        fputs(s, stdout);
        putchar(' ');
    }
    va_end(ap);
    printf("\n");
}

//26.5
char *vstrcat(const char *first, ...) {
    va_list ap;
    va_start(ap, first);
    char *s;
    size_t length = strlen(first);
    while ((s = va_arg(ap, char *)) != NULL) {
        length+= strlen(s);
    }
    char *str = malloc(length + 1);
    strcpy(str, first);
    
    va_start(ap, first);
    while ((s = va_arg(ap, char *)) != NULL) {
        strcat(str, s);
    }
    str[length] = '\0';
    return str;
}

//26.6
char *max_pair(int num_pairs, ...) {
    int number = 0,i = 0,temp = 0;
    char *s = NULL,*temps;
    va_list ap;
    va_start(ap, num_pairs);
    
    while (i < num_pairs) {
        temp = va_arg(ap, int);
        temps = va_arg(ap, char *);
        if (temp > number) {
            number = temp;
            s = temps;
        }
        i++;
    }
    va_end(ap);
    return s;
}
//26.9
double suijid() {
    srand((unsigned)time(NULL));
//    long a = rand()%1000000;
//    return a/1000000.0;
    printf("%d,%d\n",rand(),RAND_MAX);
    long a = RAND_MAX ;
    a++;
    return (double) rand() / a;
}
//26.12 年第一天
time_t niandiyitian(int year) {
    struct tm mytm;
    mytm.tm_year = year;
    mytm.tm_yday = 0;
    mytm.tm_hour = 12;
    mytm.tm_mday = 1;
    mytm.tm_mon = 0;
    
    mytm.tm_sec = 0;
    mytm.tm_min = 0;
    mytm.tm_isdst = -1;
    return mktime(&mytm);
}
//26.2
void haha1() {
    printf("That's all,");
}
void haha2() {
    printf("folks!\n");
}

//26.3
void my_clock(const int *arr,int n) {
    clock_t start_clock = clock();
    qsort((void *)arr, n, sizeof(arr[0]), compar);
    printf("Processor time used:%f sec.\n",(clock() - start_clock)/(double)CLOCKS_PER_SEC);
}

#include <stdint.h>
#include <inttypes.h>
#include <complex.h>
#include <tgmath.h>
#include <fenv.h>
int main(int argc, const char * argv[]) {
//    #include <fenv.h>浮点环境
//    fexcept_t
//    fenv_t
    
//#pragma STDC FENV_ACCESS ON
    
    //=======================================
//    #include <tgmath.h>泛型数学
    
    //=======================================
    
//    #include <inttypes.h>
//    int_least32_t a = 123;
//    printf("a = %" PRIdLEAST32 "\n",a);
    
    //复数#include <complex.h>
//    float _Complex x;
//    double _Complex y;
//    long double _Complex z;
    
//    _Complex_I 和 I 都表示虚数单位i
//    double complex dc = 2.0 + 3.5 * I;
    
//    ON    OFF    DEFAULT
//#pragma STDC CX_LIMITED_RANGE ON
    
//    <complex.h>函数
    //三角函数
//    cacos(<#_Complex double#>)
//    cacosf(<#_Complex float#>)
//    cacosl(<#_Complex long double#>)
    
//    casin(<#_Complex double#>)
//    casinf(<#_Complex float#>)
//    casinl(<#_Complex long double#>)
//
//    catan(<#_Complex double#>)
//    catanf(<#_Complex float#>)
//    catanl(<#_Complex long double#>)
//
//    ccos(<#_Complex double#>)
//    ccosf(<#_Complex float#>)
//    ccosl(<#_Complex long double#>)
//
//    csin(<#_Complex double#>)
//    csinf(<#_Complex float#>)
//    csinl(<#_Complex long double#>)
//
//    ctan(<#_Complex double#>)
//    ctanf(<#_Complex float#>)
//    ctanl(<#_Complex long double#>)
    
////    双曲函数
//    cacosh(<#_Complex double#>)
//    cacoshf(<#_Complex float#>)
//    cacoshl(<#_Complex long double#>)
//
//    casinh(<#_Complex double#>)
//    casinhf(<#_Complex float#>)
//    casinhl(<#_Complex long double#>)
//
//    catanh(<#_Complex double#>)
//    catanhf(<#_Complex float#>)
//    casinhl(<#_Complex long double#>)
//
//    ccosh(<#_Complex double#>)
//    ccoshf(<#_Complex float#>)
//    ccoshl(<#_Complex long double#>)
//
//    csinh(<#_Complex double#>)
//    csinhf(<#_Complex float#>)
//    csinhl(<#_Complex long double#>)
//
//    ctanh(<#_Complex double#>)
//    ctanhf(<#_Complex float#>)
//    ctanhl(<#_Complex long double#>)

//    指数函数和对数函数
//    cexp(<#_Complex double#>)
//    cexpf(<#_Complex float#>)
//    cexpl(<#_Complex long double#>)
//
//    clog(<#_Complex double#>)
//    clogf(<#_Complex float#>)
//    clogl(<#_Complex long double#>)
    
//    幂函数和绝对值函数
//    cabs(<#_Complex double#>)
//    cabsf(<#_Complex float#>)
//    cabsl(<#_Complex long double#>)
//
//    cpow(<#_Complex double#>, <#_Complex double#>)
//    cpowf(<#_Complex float#>, <#_Complex float#>)
//    cpowl(<#_Complex long double#>, <#_Complex long double#>)
//    csqrt(<#_Complex double#>)
//    csqrtf(<#_Complex float#>)
//    csqrtl(<#_Complex long double#>)
    
//    操作函数
//    carg(<#_Complex double#>)
//    cargf(<#_Complex float#>)
//    cargl(<#_Complex long double#>)
//
//    cimag(<#_Complex double#>)
//    cimagf(<#_Complex float#>)
//    cimagl(<#_Complex long double#>)
//
//    conj(<#_Complex double#>)
//    conjf(<#_Complex float#>)
//    conjl(<#_Complex long double#>)
//
//    cproj(<#_Complex double#>)
//    cprojf(<#_Complex float#>)
//    cprojl(<#_Complex long double#>)
//
//    creal(<#_Complex double#>)
//    crealf(<#_Complex float#>)
//    creall(<#_Complex long double#>)
    
    //=======================================
//    #include <stdint.h>
//    int32_t
//    int_least32_t
//    int_fast32_t
    
//    INT32_MAX
//    INT_LEAST32_MAX
//    INT_FAST32_MAX
//    INTPTR_MAX
//    INTMAX_MAX
    
//    int32_t a = INT32_C(0x12);
//    printf("%d\n",a);
    //=======================================
    
    //26.5
//    int month1 = 2;
//    int day1 = 12;
//    int year1 = 2019;
//
//    int month2 = 2;
//    int day2 = 28;
//    int year2 = 2019;
//
//    struct tm my_tm1;
//    my_tm1.tm_year = year1 - 1900;
//    my_tm1.tm_mon = month1;
//    my_tm1.tm_mday = day1;
//    my_tm1.tm_hour = 0;
//    my_tm1.tm_sec = 0;
//    my_tm1.tm_min = 0;
//    my_tm1.tm_isdst = -1;
//    time_t t1 = mktime(&my_tm1);
//
//    struct tm my_tm2;
//    my_tm2.tm_year = year2 - 1900;
//    my_tm2.tm_mon = month2;
//    my_tm2.tm_mday = day2;
//    my_tm2.tm_hour = 0;
//    my_tm2.tm_sec = 0;
//    my_tm2.tm_min = 0;
//    my_tm2.tm_isdst = -1;
//    time_t t2 = mktime(&my_tm2);
//
//    printf("%f\n",difftime(t2, t1)/(60 * 60 *24));
    
    
    //26.4
//    int month = 2;
//    int day = 12;
//    int year = 2019;
//    int n = 3;
//
//    struct tm mytm;
//    mytm.tm_year = year - 1900;
//    mytm.tm_mon = month;
//    mytm.tm_mday = day + n;
//    mytm.tm_hour = 0;
//    mytm.tm_sec = 0;
//    mytm.tm_min = 0;
//    mytm.tm_isdst = -1;
//
//    time_t t = mktime(&mytm);
//    printf("%s\n",ctime(&t));
    
    //26.3
//    int N = 100000;
//    int temp = N;
//    int a[N];
//    for (int i = 0; i < N; i++) {
//        a[i] = temp--;
//    }
//    my_clock(a,N);
    
    //26.2
//    atexit(<#void (* _Nonnull)(void)#>)//添加清洗函数
//    atexit(haha2);
//    atexit(haha1);
//
    //26.1(a)
//    for (int i = 0; i < 1000; i++) {
//        printf("%d",rand()&1);
//    }
//    printf("\n");
//    (b)
//    long a = RAND_MAX/99 + 1;
//    long b = rand();
//    printf("%f\n",(double)b/a);
//    printf("%ld\n",rand()/(RAND_MAX/99 + 1 ));
    //26.13
//    strftime(<#char *restrict#>, <#size_t#>, <#const char *restrict#>, <#const struct tm *restrict#>)//把分解时间转换成字符串格式
//    char str[101];
//    struct tm mytm;
//    mytm.tm_year = 119;
//    mytm.tm_yday = 30;
//    mytm.tm_hour = 12;
//    mytm.tm_mday = 11;
//    mytm.tm_mon = 2;
    
//    mytm.tm_sec = 0;
//    mytm.tm_min = 0;
//    mytm.tm_isdst = -1;
//    strftime(str, 100, "%Y-%j", &mytm);
//    printf("%s\n",str);
    
    //26.12 年第一天
//    time_t t = niandiyitian(112);
//    char *s = ctime(&t);
//    printf("%s\n",s);
    //26.11
//    可比较大小的
    //26.9
//    printf("%f\n",suijid());
    //26.8
//    int a[] = {7,11,15,19};
//    srand((unsigned)time(NULL));
//    printf("%d\n",a[rand()%4]);
    //26.7
//    char *p = "100a";
//    long int value = strtol(p, &p, 10);
//    printf("%ld\n",value);
    //26.6
//    printf("%s\n",max_pair(5,180,"Sei",181,"Love",39,"Honey",210,"All",86,"Sopranos"));
    //26.5
//    printf("%s\n",vstrcat("abc","def","ghk",NULL));
    //26.4
//    display(4,"Special","Agent","Dale","Cooper");
    //26.3
//    my_simple_print_s("haha %d %d ho %s ho %d hehe %d %d\n",1,2,"abc",3,4,512);
    //26.2
//    my_simple_print("haha %d %d hoho %d hehe %d %d\n",1,2,3,4,512);
    //26.1
//    printf("%d\n",my_max_int(1,2,3,4,5,6,11,8,9,0));
    
    //=======================================
    
    //可变参数
//    <stdarg.h>
//    va_arg(<#ap#>, <#type#>)
//    va_copy(<#dest#>, <#src#>)
//    va_end(<#ap#>)
//    va_start(<#ap#>, <#param#>)
    
//    printf("%d\n",max_int(6,1,2,3,4,5,6));
    
//    调用带有可变参数列表的函数
//    <stdio.h>
//    vfprintf(<#FILE *restrict#>, <#const char *restrict#>, <#struct __va_list_tag *#>)
//    vprintf(<#const char *restrict#>, <#struct __va_list_tag *#>)
//    vsnprintf(<#char *restrict __str#>, <#size_t __size#>, <#const char *restrict __format#>, <#struct __va_list_tag *#>)
//    vsprintf(<#char *restrict#>, <#const char *restrict#>, <#struct __va_list_tag *#>)
    
//    vfscanf(<#FILE *restrict __stream#>, <#const char *restrict __format#>, <#struct __va_list_tag *#>)
//    vscanf(<#const char *restrict __format#>, <#struct __va_list_tag *#>)
//    vsscanf(<#const char *restrict __str#>, <#const char *restrict __format#>, <#struct __va_list_tag *#>)
    
//    <stdlib.h>通用的实用工具
//    atof(<#const char *#>)
//    atoi(<#const char *#>)
//    atol(<#const char *#>)
//    atoll(<#const char *#>)
    
//    strtod(<#const char *#>, <#char **#>)
//    strtof(<#const char *#>, <#char **#>)
//    strtold(<#const char *#>, <#char **#>)
    
//    strtol(<#const char *__str#>, <#char **__endptr#>, <#int __base#>) //base-待转换数的基数2-36
//    strtoll(<#const char *__str#>, <#char **__endptr#>, <#int __base#>)
//    strtoul(<#const char *__str#>, <#char **__endptr#>, <#int __base#>)
//    strtoull(<#const char *__str#>, <#char **__endptr#>, <#int __base#>)
    
//    伪随机序列生成函数
//    rand()//返回0~RAND_MAX
//    srand(<#unsigned int#>)
    
//    与环境的通信
//    abort();
//    atexit(<#void (* _Nonnull)(void)#>)//添加清洗函数
//    exit(<#int#>)
//    _Exit(<#int#>)
//    getenv(<#const char *#>)
//    system(<#const char *#>)
    
//    char *p = getenv("PATH");
//    printf("%s\n",p);
    
//    搜索和排序实用工具
//    bsearch(<#const void *__key#>, <#const void *__base#>, <#size_t __nel#>, <#size_t __width#>, <#int (* _Nonnull __compar)(const void *, const void *)#>)//在有序数组中搜索一个特定的值
//    qsort(<#void *__base#>, <#size_t __nel#>, <#size_t __width#>, <#int (* _Nonnull __compar)(const void *, const void *)#>)
    
//    整数算术运算函数
//    abs(<#int#>)//求绝对值
//    labs(<#long#>)
//    llabs(<#long long#>)
    
//    div(<#int#>, <#int#>)//用第一个数除以第二个数，返回div_t
//    ldiv(<#long#>, <#long#>)
//    lldiv(<#long long#>, <#long long#>)
    
//    日期和时间<time.h>
//    clock_t
//    time_t//紧凑的时间和日期编码
//    struct tm t;//分解时间
    
    //时间处理函数
//    clock()//返回clock_t,表示程序从开始执行到当前时刻的处理器时间，转换成秒要除以CLOCKS_PER_SEC
//    difftime(<#time_t#>, <#time_t#>)//返回两个时间相差的秒数
//    mktime(<#struct tm *#>)//把分解时间转换为日历时间
//    time(<#time_t *#>)//返回当前的日历时间
    
//    计算程序运行时间
//    clock_t start_clock = clock();
//    printf("Processor time used:%g sec.\n",(clock() - start_clock)/(double)CLOCKS_PER_SEC);
    
//    cur_time = time(NULL)
//    time(&cur_time)
    
//    时间转换函数
//    asctime(<#const struct tm *#>)//返回一个指向以空字符结尾的字符串指针
//    ctime(<#const time_t *#>)//返回一个描述本地时间的字符串指针
    
//    ctime(&cur_time)等于asctime(localtime(&cur_time))
    
//    gmtime(<#const time_t *#>)//日历时间转分解时间
//    localtime(<#const time_t *#>)//本地时间转分解时间
//    strftime(<#char *restrict#>, <#size_t#>, <#const char *restrict#>, <#const struct tm *restrict#>)//把分解时间转换成字符串格式
    
    //=======================================
    //25.1
//    locale -a
    //25.2
    //25.3
    //25.4
    
    //=======================================
    
//    宽字符分类和映射实用工具<wctype.h>
//    wctype_t//表示特定于地区的字符分类
//    wctrans_t//表示特定于地区的字符映射
    
//    宽字符分类韩式
//    iswalnum(<#wint_t _wc#>)
//    iswalpha(<#wint_t _wc#>)
//    iswblank(<#wint_t _wc#>)
//    iswcntrl(<#wint_t _wc#>)
//    iswdigit(<#wint_t _wc#>)
//    iswgraph(<#wint_t _wc#>)
//    iswlower(<#wint_t _wc#>)
//    iswprint(<#wint_t _wc#>)
//    iswpunct(<#wint_t _wc#>)
//    iswspace(<#wint_t _wc#>)
//    iswupper(<#wint_t _wc#>)
//    iswxdigit(<#wint_t _wc#>)
    
//    可扩展的宽字符分类函数
//    iswctype(<#wint_t _wc#>, <#wctype_t _charclass#>)
//    wctype(<#const char *#>)
    
//    宽字符大小写映射函数
//    towlower(<#wint_t _wc#>)
//    towupper(<#wint_t _wc#>)
    
//    可扩展的宽字符大小写映射函数
//    towctrans(<#wint_t#>, <#wctrans_t#>)
//    wctrans(<#const char *#>)
    
    //=======================================
    
//    扩展的多字节、宽字符转换实用工具
//    单字节、宽字符转换函数
//    btowc(<#int#>)
//    wctob(<#wint_t#>)
//    转换状态函数
//    mbsinit(<#const mbstate_t *#>)
//    可再次启动的多字节、宽字符转换函数
//    mbrlen(<#const char *restrict#>, <#size_t#>, <#mbstate_t *restrict#>)
//    mbrtowc(<#wchar_t *restrict#>, <#const char *restrict#>, <#size_t#>, <#mbstate_t *restrict#>)
//    wcrtomb(<#char *restrict#>, <#wchar_t#>, <#mbstate_t *restrict#>)
//    可再次启动的多字节、宽字符串转换函数
//    mbsrtowcs(<#wchar_t *restrict#>, <#const char **restrict#>, <#size_t#>, <#mbstate_t *restrict#>)
//    wcsrtombs(<#char *restrict#>, <#const wchar_t **restrict#>, <#size_t#>, <#mbstate_t *restrict#>)
    
    
    //=======================================
    
//    mbstate_t//转换状态
//    wint_t///值表示扩展字符
//    WEOF//和EOF相似，用于指明错误或文件末尾
    
//    格式化宽字符输入输出函数
//    int fwprintf(<#FILE *restrict#>, <#const wchar_t *restrict, ...#>)
//    fwscanf(<#FILE *restrict#>, <#const wchar_t *restrict, ...#>)
//    swprintf(<#wchar_t *restrict#>, <#size_t#>, <#const wchar_t *restrict, ...#>)
//    swscanf(<#const wchar_t *restrict#>, <#const wchar_t *restrict, ...#>)
//    vfwprintf(<#FILE *restrict#>, <#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    vfwscanf(<#FILE *restrict#>, <#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    vswprintf(<#wchar_t *restrict#>, <#size_t#>, <#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    vswscanf(<#const wchar_t *restrict#>, <#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    vwprintf(<#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    vwscanf(<#const wchar_t *restrict#>, <#struct __va_list_tag *#>)
//    wprintf(<#const wchar_t *restrict, ...#>)
//    wscanf(<#const wchar_t *restrict, ...#>)

//    宽字符输入输出函数
//    fgetwc(<#FILE *#>)
//    fgetws(<#wchar_t *restrict#>, <#int#>, <#FILE *restrict#>)
//    fputwc(<#wchar_t#>, <#FILE *#>)
//    fputws(<#const wchar_t *restrict#>, <#FILE *restrict#>)
//    fwide(<#FILE *#>, <#int#>)//>0 如果没有倾向,尝试使流面向宽字符、<0 如果没有倾向,尝试使流面向字节
//    getwc(<#FILE *#>)
//    getwchar()
//    putwc(<#wchar_t#>, <#FILE *#>)
//    putwchar(<#wchar_t#>)
//    ungetwc(<#wint_t#>, <#FILE *#>)
    
//    宽字符串数值转换函数
//    wcstod(<#const wchar_t *restrict#>, <#wchar_t **restrict#>)
//    wcstof(<#const wchar_t *restrict#>, <#wchar_t **restrict#>)
//    wcstold(<#const wchar_t *restrict#>, <#wchar_t **restrict#>)
//    wcstol(<#const wchar_t *restrict#>, <#wchar_t **restrict#>, <#int#>)
//    wcstoll(<#const wchar_t *restrict#>, <#wchar_t **restrict#>, <#int#>)
//    wcstoul(<#const wchar_t *restrict#>, <#wchar_t **restrict#>, <#int#>)
//    wcstoull(<#const wchar_t *restrict#>, <#wchar_t **restrict#>, <#int#>)
    
//    宽字符串复制函数
//    wcscpy(<#wchar_t *restrict#>, <#const wchar_t *restrict#>)
//    wcsncpy(<#wchar_t *restrict#>, <#const wchar_t *restrict#>, <#size_t#>)
//    wmemcpy(<#wchar_t *restrict#>, <#const wchar_t *restrict#>, <#size_t#>)
//    wmemmove(<#wchar_t *#>, <#const wchar_t *#>, <#size_t#>)
    
//    宽字符串拼接函数
//    wcscat(<#wchar_t *restrict#>, <#const wchar_t *restrict#>)
//    wcsncat(<#wchar_t *restrict#>, <#const wchar_t *restrict#>, <#size_t#>)
    
    
//    宽字符串比较函数
//    wcscmp(<#const wchar_t *#>, <#const wchar_t *#>)
//    wcscoll(<#const wchar_t *#>, <#const wchar_t *#>)
//    wcsncmp(<#const wchar_t *#>, <#const wchar_t *#>, <#size_t#>)
//    wcsxfrm(<#wchar_t *restrict#>, <#const wchar_t *restrict#>, <#size_t#>)
//    wmemcmp(<#const wchar_t *#>, <#const wchar_t *#>, <#size_t#>)
    
//    宽字符串搜索函数
//    wcschr(<#const wchar_t *#>, <#wchar_t#>)
//    wcscspn(<#const wchar_t *#>, <#const wchar_t *#>)
//    wcspbrk(<#const wchar_t *#>, <#const wchar_t *#>)
//    wcsrchr(<#const wchar_t *#>, <#wchar_t#>)
//    wcsspn(<#const wchar_t *#>, <#const wchar_t *#>)
//    wcsstr(<#const wchar_t *restrict#>, <#const wchar_t *restrict#>)
//    wcstok(<#wchar_t *restrict#>, <#const wchar_t *restrict#>, <#wchar_t **restrict#>)
//    wmemchr(<#const wchar_t *#>, <#wchar_t#>, <#size_t#>)
    
//    其他函数
//    wcslen(<#const wchar_t *#>)
//    wmemset(<#wchar_t *#>, <#wchar_t#>, <#size_t#>)
    
//    宽字符时间转换函数
//    wcsftime(<#wchar_t *restrict#>, <#size_t#>, <#const wchar_t *restrict#>, <#const struct tm *restrict#>)
//    对应strftime
    
    //================================
    
    //双字符
    //三字符
    
    //多字节/宽字符串转换函数
//    size_t mbstowcs(<#wchar_t *restrict#>, <#const char *restrict#>, <#size_t#>)//把多字节字符序列转换为宽字符
//    size_t wcstombs(<#char *restrict#>, <#const wchar_t *restrict#>, <#size_t#>)//把宽字符序列转换为多字节字符串
    
    //多字节/宽字符转换函数
//    int mblen(<#const char *__s#>, <#size_t __n#>)//检测第一个参数是否指向形成有效多字节字符的字节序列，是则返回字节数，不是则返回-1，空指针返回0。第二个参数用MB_CUR_MAX
    
//    char *s = "aaa";
//    int n;
//    for (mblen(NULL, 0); ; s += n) {
//        if ((n = mblen(s, MB_CUR_MAX)) <= 0) {
//            printf("===>%d\n",n);
//            break;
//        }
//        printf("-===>%d\n",n);
//    }
    
//    int mbtowc(<#wchar_t *restrict#>, <#const char *restrict#>, <#size_t#>)//把第二个多字节字符参数转换为宽字符
//    int wctomb(<#char *#>, <#wchar_t#>)//把第二个宽字符参数转换为多字节字符
    
    
    
//    LC_COLLATE//影响两个字符串比较函数（strcoll和strxfrm）
//    LC_CTYPE
//    LC_MONETARY
//    LC_NUMERIC
//    LC_TIME
    
//    char *setlocale(<#int#>, <#const char *#>)函数
//    setlocale(LC_ALL, "C");//"C"正常模式 “ ”本地模式
//    char *s = setlocale(LC_ALL, "zh_CN.UTF-8");
//    char *s = setlocale(LC_ALL, NULL);
//    printf("%s\n",s);
    
//    struct lconv *localeconv()函数
    
    //多字节字符
//    MB_CUR_MAX//当前地区的最大值
//    MB_LEN_MAX//任意支持地区的最大值
    //宽字符
//    wchar_t
//    wchar_t a = L'abc';
    
    
//    =============================================
    
//    24.2
    
//    int setjmp(<#int *#>)
//    void longjmp(<#int *#>, <#int#>)
    
//    if (setjmp(env) == 0) {
//        printf("setjmp 返回0\n");//1
//    }else{
//        printf("longjmp被调用\n");//4
//        return 0;
//    }
//    fff1();
//    printf("程序结束");
    
//    void (*orig_handler)(int);
//    printf("Installing handler for signal %d\n",SIGINT);
//    orig_handler = signal(SIGINT, handler);
//    raise_sig();
//
//    printf("Changing handler to SIG_IGN\n");
//    signal(SIGILL, SIG_IGN);
//    raise_sig();
//
//    printf("Restoring original handler\n");
//    signal(SIGINT, orig_handler);
//    raise_sig();
//
//    printf("Program terminates normally\n");
    
//    int raise(<#int#>)
//    raise(SIGABRT);
//    printf("=====");
    
//    测试signal是否调用失败
//    if (signal(SIGINT, handler) == SIG_ERR) {
//
//    }
    
//    SIG_DFL
//    signal(SIGINT, SIG_DFL);//默认处理
//    SIG_IGN
//    signal(SIGINT, SIG_IGN);//忽略信号
    
//    void    (*signal(int, void (*)(int)))(int);
//    void (*orig_handler)(int);
//    signal(SIGINT, orig_handler);
    
    
//    void perror(<#const char *#>)      (stdio.h)
//    char *strerror(<#int __errnum#>)   (string.h)
//    puts(strerror(EDOM));
    
//    errno = 0;
//    double y = exp(10000);
//    if (errno != 0) {
//        fprintf(stderr, "sqrt error");
//        exit(EXIT_FAILURE);
//    }
    
//    int i = 11;
//    assert(0 <= i && i < 10);
//    printf("通过断言\n");
    
//    =============================================
    //23.7
//    int count = 0;
//    char str[10000];
//    fgets(str, sizeof(str) - 1, stdin);
//    char *p = strtok(str, ".?!\n");
//    while (p != NULL) {
//        count++;
//        p = strtok(NULL, ".?! \n");
//    }
//    printf("==>%d\n",count);
    
    //23.6
//    int ch;
//    while ((ch = getchar())!= EOF) {
//        if (iscntrl(ch)&&ch != '\n') {
//            ch = '?';
//        }
//        putchar(ch);
//    }
    
    //23.5
//    double P = 10000;
//    int t = 10;
//    double r = 0.06;
//    double sum = P * exp(t * r);
    
    //23.4
//    char str[100];
//    int i = 0;
//    char *arr[100];
//    if (fgets(str, 99, stdin) != NULL) {
//        arr[i] = strtok(str, " ");
//        while (arr[i] != NULL) {
//            arr[++i] = strtok(NULL, " \n");
//        }
//        i--;
//        for (; i >= 0; i--) {
//            printf("%s ",arr[i]);
//        }
//
//        printf("\n");
//    }
    
    //23.3
//    int ch;
//    bool isFirst = true;
//    while ((ch = getchar()) != EOF) {
//        if (isFirst&&isblank(ch) == 0) {
//            ch = toupper(ch);
//            isFirst = false;
//        }else if (!isFirst&&isblank(ch) != 0) {
//            isFirst = true;
//        }
//        putchar(ch);
//    }
    
    //23.2
//    int ch;
//    bool noblack = false;
//    while ((ch = getchar()) != EOF) {
//        if (noblack) {
//            putchar(ch);
//        }else if(!isspace(ch)){
//            noblack = true;
//            putchar(ch);
//        }
//        if (ch == '\n') {
//            noblack = false;
//        }
//    }
    
    //23.13
//    char str[] = "c is niubi si le";
//    printf("%d\n",my_count_words(str));
    //23.12
//    (a)
//    char *ss = my_strdup("123456");
//    printf("%s\n",ss);
//    (b)
//    printf("%d\n",my_stricmp("abC", "Abc"));
//    (c)
//    char s[] = "abc.ABC";
//    my_strlwr(s);
//    printf("%s\n",s);
//    (d)
//    char s[] = "123456";
//    printf("%s\n",strrev(s));
//    (e)
//    char s[] = "123456";
//    printf("%s\n",my_strset(s,'6'));
    
    //23.11
//    char s[] = "123456";
//    tihuantanhao(s, 3);
//    printf("%s\n",s);
    
    //23.10
//    char *str = "bar";
//    char *ss = "foo|bar|baz";
//    char *p = strchr(ss, str[0]);
//    printf("%d\n",p != NULL&&p[0] != '|'&&p[1]==str[1]&&p[2]==str[2]&&p[1]!='|'&&p[2]!='|'&&str[3]=='\0');
    
    //23.9
//    if (strchr("abc", ch) != NULL) {
//        <#statements#>
//    }
//    printf("%s\n",strchr("abc", 'd'));
    
    //23.8
//    printf("%d\n",numchar("abc 2b okbx", 'b'));
    //23.7
//    char *p, str[] = "abc 2b okbx";
//    char str1[strlen(str) + 1];
//    strcpy(str1, str);
//    p = strrchr(str, 'b');
//    printf("%s\n",p);
//    while (p != NULL) {
//        memmove(str, str, p - str);
//        str[p - str] = '\0';
//        p = strrchr(str, 'b');
//        if (p != NULL) {
//            printf("%s\n",&str1[p - str]);
//        }
//    }
    
    //23.6
//    (a)memmove
//    (b)strncpy 错误  memmove
//    (c)strcpy 错误 strncpy
//    (d)memcpy
    
    //23.5
//    printf("%ld\n",isshiliu("0x12"));
    //23.4
//    printf("%d\n",isbiaozhi("1aad1"));
    //23.1
//    printf("%f  %f\n",round_nearest(3.14159, 3),round_nearest(-3.14159, 3));
    
//    =============================================
    
//    复制函数
//    void *memcpy(<#void *__dst#>, <#const void *__src#>, <#size_t __n#>)
//    void *memmove(<#void *__dst#>, <#const void *__src#>, <#size_t __len#>)
//    char *strcpy(<#char *__dst#>, <#const char *__src#>)//持续复制直到遇到空字符
//    char *strncpy(<#char *__dst#>, <#const char *__src#>, <#size_t __n#>)
//    拼接函数
//    char *strcat(<#char *__s1#>, <#const char *__s2#>)
//    char *strncat(<#char *__s1#>, <#const char *__s2#>, <#size_t __n#>)
//    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
//    比较函数
//    int memcmp(<#const void *__s1#>, <#const void *__s2#>, <#size_t __n#>)
//    int strcmp(<#const char *__s1#>, <#const char *__s2#>)
//    int strncmp(<#const char *__s1#>, <#const char *__s2#>, <#size_t __n#>)
    
//    int strcoll(<#const char *__s1#>, <#const char *__s2#>)
//    size_t strxfrm(<#char *__s1#>, <#const char *__s2#>, <#size_t __n#>)
    
//    char *original = "abcde";
//    size_t len;
//    char *transformed;
//    len = strxfrm(NULL, original, 0);
//    transformed = malloc(len + 1);
//    strxfrm(transformed, original, len);
//    printf("%s\n",transformed);
//    搜索函数
//    void *memchr(<#const void *__s#>, <#int __c#>, <#size_t __n#>)
//    char *strchr(<#const char *__s#>, <#int __c#>)//找不到就返回空指针
//    char *strpbrk(<#const char *__s#>, <#const char *__charset#>)//找到任何一个出现在第二个参数中的字符
//    char *strrchr(<#const char *__s#>, <#int __c#>)//反向搜索
//    size_t strcspn(<#const char *__s#>, <#const char *__charset#>)//返回第一个属于搜索字符的下标
//    size_t strspn(<#const char *__s#>, <#const char *__charset#>)//返回第一个不属于搜索字符的下标
//    char *strstr(<#const char *__big#>, <#const char *__little#>)//搜索字符串，返回第一次找到的指针，否则返回空指针
//    char *strtok(<#char *__str#>, <#const char *__sep#>)
    
//    char *p,str[] = "Form follows function.";
//    p = strchr(str, 'f');
//    p = strchr(p + 1, 'f');
//    printf("%s\n",p);
//    其他函数
//    memset(<#void *__b#>, <#int __c#>, <#size_t __len#>)
//    strlen(<#const char *__s#>)
    
//    memset(p, ' ', N);
//    memset(a, 0, sizeof(a))
    
    
//    =============================================
    
//    字符分类函数(如果是就返回非零值)
//    isalnum(<#int _c#>)//是否字母或数字
//    isalpha(<#int _c#>)//是否是字母
//    isblank(<#int _c#>)//是否标准空白字符(空格和\t)
//    iscntrl(<#int _c#>)//是否控制字符(\x00 \x1f \x7f)
//    isdigit(<#int _c#>)//是否十进制
//    isgraph(<#int _c#>)//是否可显示字符（除空格）
//    islower(<#int _c#>)//是否小写字母
//    isprint(<#int _c#>)//是否可打印字符（包括空格）
//    ispunct(<#int _c#>)//是否标点符号
//    isspace(<#int _c#>)//是否空白字符（空格、换页符\t、回车符\r、水平制表符\t、垂直制表符\v）
//    isupper(<#int _c#>)//是否大写字母
//    isxdigit(<#int _c#>)//是否十六进制数
    
//    字符大小写映射函数
//    tolower(<#int _c#>)
//    toupper(<#int _c#>)
    
    //=============================================
//    三角函数
//    extern double acos(double);
//    extern double asin(double);
//    extern double atan(double);
//    extern double atan2(double, double);
//    extern double cos(double);
//    extern double sin(double);
//    extern double tan(double);
    
//    双曲函数
//    extern double cosh(double);
//    extern double sinh(double);
//    extern double tanh(double);
    
//    指数函数和对数函数
//    extern double exp(double);
//    extern double frexp(double, int *);
//    extern double ldexp(double, int);
//    extern double log(double);
//    extern double log10(double);
//    extern double modf(double, double *);
    
//    double a = 1.2;
//    double b;
//    int e;
//    double c = modf(a, &b);
//    double d = frexp(a, &e);// f * (2的n次幂)
//    printf("b:%f c:%f d:%f e:%d\n",b,c,d,e);
//    ldexp抵消frexp产生的结果
    
//    幂函数
//    extern double pow(double, double);//第一个参数的几次方
//    extern double sqrt(double);//求立方
    
//    就近取整函数、绝对值函数和取余函数
//    extern double ceil(double);//向上取整
//    extern double floor(double);//向下取整
//    extern double fabs(double);//绝对值
//    extern double fmod(double, double);//返回第一个参数除以第二个参数所得的余数
    
//    C99
//    float_t
//    double_t
//    INFINITY 正无穷数
//    NAN非数
    
//    C99分类宏
//    int fpclassify(浮点<#x#>)
//    isfinite(<#x#>)
//    isinf(<#x#>)
//    isnan(<#x#>)
//    isnormal(<#x#>)
//    signbit(<#x#>)
    
    //三角函数
    //双曲函数
    //指数函数和对数函数
    
//    幂函数和绝对值函数
//    cbrt(<#double#>)
//    fabsf(<#float#>)
//    hypot(<#double#>, <#double#>)
//    powf(<#float#>, <#float#>)
//    sqrtf(<#float#>)
    
//    误差函数
//    erf(<#double#>)
//    erfc(<#double#>)
//    lgamma(<#double#>)
//    tgamma(<#double#>)
    
//    就近取整函数
//    ceilf(<#float#>)
//    floor(<#double#>)
//    nearbyint(<#double#>)
//    rint(<#double#>)
//    lrint(<#double#>)
//    round(<#double#>)
//    trunc(<#double#>)

//    取余函数
//    fmodf(<#float#>, <#float#>)
//    remainder(<#double#>, <#double#>)
//    remquo(<#double#>, <#double#>, <#int *#>)
    
//    操作函数
//    copysign(<#double#>, <#double#>)
//    nan(<#const char *#>)
//    nextafter(<#double#>, <#double#>)
//    nexttoward(<#double#>, <#long double#>)
    
//    最大值函数、最小值函数、正差函数
//    fdim(<#double#>, <#double#>)
//    fmax(<#double#>, <#double#>)
//    fmin(<#double#>, <#double#>)
    
//    浮点乘加
//    fma(<#double#>, <#double#>, <#double#>)
//    FP_FAST_FMA
//#pragma STDC FP_CONTRACT DEFAULT
    
    //比较宏
//    isgreater(<#x#>, <#y#>)
//    isgreaterequal(<#x#>, <#y#>)
//    isless(<#x#>, <#y#>)
//    islessequal(<#x#>, <#y#>)
//    islessgreater(<#x#>, <#y#>)
//    isunordered(<#x#>, <#y#>)
    
    //=======================================
    
//    FLT_ROUNDS 浮点加法的舍入方向
//    FLT_RADIX 指数表示中的基数
    
    //有效数字宏(基数FLT_RADIX)
//    FLT_MANT_DIG
//    DBL_MANT_DIG
//    LDBL_MANT_DIG
    
//    有效数字宏(十进制)
//    FLT_DIG   >=6
//    DBL_DIG   >=10
//    LDBL_DIG  >=10
    
//    FLT_RADIX的最小的（负的）次幂
//    FLT_MIN_EXP
//    DBL_MIN_EXP
//    LDBL_MIN_EXP
    
//    10的最小(负的)次幂
//    FLT_MIN_10_EXP    <=-37
//    DBL_MIN_10_EXP    <=-37
//    LDBL_MIN_10_EXP   <=-37
    
//    FLT_RADIX的最大次幂
//    FLT_MAX_EXP
//    DBL_MAX_EXP
//    LDBL_MAX_EXP
    
//    10的最大次幂
//    FLT_MAX_10_EXP    >=+37
//    DBL_MAX_10_EXP    >=+37
//    LDBL_MAX_10_EXP   >=+37
    
//    最大的有限值
//    FLT_MAX   >=10e37
//    DBL_MAX   >=10e37
//    LDBL_MAX  >=10e37
    
//    最小的正值
//    FLT_MIN   <=10e-37
//    DBL_MIN   <=10e-37
//    LDBL_MIN  <=10e-37
    
//    两数之间可表示的最小差值
//    FLT_EPSILON   <=10e-5
//    DBL_EPSILON   <=10e-9
//    LDBL_EPSILON  <=10e-9
    
//    所支持的最大浮点类型的有效数字个数（10为基数）
//    DECIMAL_DIG
//    具体的实现中是否用到了超出实际需要的范围和精度的浮点运算
//    FLT_EVAL_METHOD
    
//    22.18
//    FILE *fp = fopen("bbb.txt", "r");
//    int aa;
//    while (fscanf(fp, " %d",&aa) > 0) {
//        printf("%d\n",aa);
//    }
//
//    22.17
//    if (argc < 2) {
//        printf("参数异常");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp = fopen(argv[1], "r");
//    if (fp == NULL) {
//        printf("文件打开失败");
//        exit(EXIT_FAILURE);
//    }
//    char str[100];
//    int a1,a2,a3,n;
//    while (fgets(str, sizeof(str) - 1, fp) != NULL) {
//        n = sscanf(str, "%d.%d.%d",&a1,&a2,&a3);
//        if (n != 3) {
//            n = sscanf(str, "(%d) %d-%d",&a1,&a2,&a3);
//        }
//        if (n != 3) {
//            n = sscanf(str, "%d-%d-%d",&a1,&a2,&a3);
//        }
//        if (n != 3) {
//            n = sscanf(str, "%d %d %d",&a1,&a2,&a3);
//        }
//        if (n != 3) {
//            n = sscanf(str, "%3d%3d%4d",&a1,&a2,&a3);
//        }
//
//        if (a1&&a2&&a3) {
//            printf("(%d) %d-%d\n",a1,a2,a3);
//        }
//    }
//    fclose(fp);
    
    //22.16
//    FILE *source_fp,*dest_fp;
//    if (argc != 3) {
//        fprintf(stderr, "参数不对!");
//        exit(EXIT_FAILURE);
//    }
//    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
//        fprintf(stderr, "不能打开 %s\n",argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
//        fprintf(stderr, "不能打开 %s\n",argv[2]);
//        fclose(source_fp);
//        exit(EXIT_FAILURE);
//    }
//
//    char str[512];
//    size_t n;
//    while ((n = fread(str, 1, 512, source_fp)) > 0) {
//        fwrite(str, 1, n, dest_fp);
//    }
//    fclose(source_fp);
//    fclose(dest_fp);

    
    //22.12
//    if (argc < 2) {
//        printf("参数异常");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp = fopen(argv[1], "r");
//    if (fp == NULL) {
//        printf("文件打开失败");
//        exit(EXIT_FAILURE);
//    }
//    char str[100];
//    int data = 0,months = 0,days = 0,years = 0;
//    double price = 0;
//    printf("Item      Price          Date\n");
//    while (fgets(str, sizeof(str), fp) != NULL) {
//        sscanf(str, "%d,%lf,%d/%d/%d",&data,&price,&months,&days,&years);
//        printf("%-9d$ %-12.2lf%d/%d/%d\n",data,price,months,days,years);
//    }
//    fclose(fp);
    
//    22.11
//    int years = 0,months = 0,days = 0,n = 0;
//    char str[100];
//    while (n != 3) {
//        printf("输入日期:");
//        fgets(str, sizeof(str), stdin);
//        n = sscanf(str, "%d-%d-%d",&months,&days,&years);
//        if (n != 3) {
//            n = sscanf(str, "%d/%d/%d",&months,&days,&years);
//        }
//        if (n != 3) {
//            fprintf(stderr, "日期格式有误\n");
//        }
//    }
//
//    printf("正确的日期格式 %d %d, %d\n",months,days,years);
    
    //22.9
//    start();
    //22.8
//    start();
    //22.7 (b)
//    if (argc < 2) {
//        printf("文件参数不对");
//        exit(EXIT_FAILURE);
//    }
//
//    char houzhui[5];
//    if (strlen(argv[1]) < 4) {
//        printf("文件名不对");
//        exit(EXIT_FAILURE);
//    }else{
//        int j = 0;
//        for (unsigned long i = strlen(argv[1]) - 4; i < strlen(argv[1]); i++) {
//            houzhui[j] = argv[1][i];
//            j++;
//        }
//        if (strcmp(houzhui, ".rle") == 0) {
//            char filename[strlen(argv[1]) - 4 + 1];
//            strncpy(filename, argv[1], sizeof(filename) - 1);
//            filename[strlen(argv[1]) - 4] = '\0';
//
//            //开始解压缩
//            FILE *fp = fopen(argv[1], "rb");
//            FILE *nfp = fopen(filename, "wb");
//            int count;
//            int ch;
//            while ((count = getc(fp)) != EOF) {
//                ch = getc(fp);
//                for (int i = 0; i < count; i++) {
//                    putc(ch, nfp);
//                }
//            }
//
//            fclose(nfp);
//            fclose(fp);
//            printf("解压完成");
//        }else{
//            printf("文件后缀名不对");
//            exit(EXIT_FAILURE);
//        }
//    }
    
    //22.7(a)
//    printFile("pun.c.rle");
//    if (argc < 2) {
//        printf("文件参数不对");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp = fopen(argv[1], "rb");
//    if (fp == NULL) {
//        printf("文件无法打开");
//        exit(EXIT_FAILURE);
//    }
//    char filename[strlen(argv[1]) + 5];
//    strcpy(filename, argv[1]);
//    strcat(filename, ".rle");
//    filename[strlen(argv[1]) + 4] = '\0';
//
//    FILE *nfp = fopen(filename, "wb");
//    int count = 0;
//    int ch;
//    int next_ch;
//    while ((ch = getc(fp)) != EOF) {
//        count++;
//        while ((next_ch = getc(fp)) != EOF) {
//            if (next_ch == ch) {
//                count++;
//            }else{
//                fseek(fp, -1L, SEEK_CUR);
//                break;
//            }
//        }
//        putc(count, nfp);
//        putc(ch, nfp);
//        count = 0;
//    }
//
//    fclose(nfp);
//    fclose(fp);
    
    
    //文件定位
    //    int     fseek(FILE *, long, int);//第二个参数是移动的字节数
    //SEEK_SET:文件起始处
    //SEEK_CUR:当前位置
    //SEEK_END:文件末尾
    //    fseek(fp, 0, SEEK_SET);//移动到文件起始位置
    //    fseek(fp, 0, SEEK_END);//移动到文件末尾位置
    //    fseek(fp, -10L, SEEK_CUR);//往回移动10个字节
    //正确返回0，错误返回非0
    
    //    long     ftell(FILE *);//以长整数返回当前文件位置
    //    void     rewind(FILE *);//把文件位置设置在起始处
    
    //    int     fgetpos(FILE * __restrict, fpos_t *);
    //    int     fsetpos(FILE *, const fpos_t *);
    //正确返回0，错误返回非0
    //    fpos_t file_pos;
    //    fgetpos(fp, &file_pos);
    //    fsetpos(fp, &file_pos);
    
    //22.6
//    printf("Offset");
//    printf("   ");
//    printf("                 ");
//    printf("Bytes");
//    printf("                 ");
//    printf("   ");
//    printf("Characters");
//    printf("\n");
//
//    printf("______");
//    printf("   ");
//    printf("_________________");
//    printf("_____");
//    printf("_________________");
//    printf("   ");
//    printf("__________");
//    printf("\n");
//
//    FILE *fp = fopen("pun.c", "rb");
//    int index = 0;
//    int ch;
//    int array[10];
//
//    while ((ch = getc(fp)) != EOF) {
//        array[index%10] = ch;
//        if (index%10 == 0) {
//            printf("%6d",index);
//            printf("   ");
//        }
//        printf("%.2X",ch);
//        if (index %10 != 9) {
//            printf(" ");
//        }else{
//            printf("   ");
//            for (int i = 0; i <= index%10; i++) {
//                if (isprint(array[i])) {
//                    printf("%c",array[i]);
//                }else{
//                    printf(".");
//                }
//            }
//            printf("\n");
//
//        }
//        index++;
//    }
//
//    if (index%10 != 0) {
//        int j = index%10;
//        while (j < 10) {
//            printf("  ");
//            j++;
//            if (j != 10) {
//                printf(" ");
//            }
//        }
//        printf("   ");
//        for (int i = 0; i < index%10; i++) {
//            if (isprint(array[i])) {
//                printf("%c",array[i]);
//            }else{
//                printf(".");
//            }
//        }
//        printf("\n");
//    }
    
    //22.5
//    if (argc < 3) {
//        printf("文件参数不对");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp = fopen(argv[1], "rb");
//    if (fp == NULL) {
//        printf("文件无法打开");
//        exit(EXIT_FAILURE);
//    }
//
//    FILE *nfp = fopen(argv[2], "wb");
//    if (nfp == NULL) {
//        printf("文件无法打开");
//        exit(EXIT_FAILURE);
//    }
//    int orig_char,new_char;
//    while ((orig_char = getc(fp)) != EOF) {
//        new_char = orig_char ^ KEY;
//        putc(new_char, nfp);
//    }
//    fclose(fp);
//    fclose(nfp);
    
    //22.4(c)
    
    //22.4(b)
    
    //22.4(a)
//    if (argc < 2) {
//        printf("文件参数不对");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp = fopen(argv[1], "r");
//    if (fp == NULL) {
//        printf("文件无法打开");
//        exit(EXIT_FAILURE);
//    }
//    int ch;
//    int count = 0;
//    while ((ch = getc(fp)) != EOF) {
//        count++;
//    }
//    printf("字符数量:%d\n",count);
    
    //22.3
//    if (argc < 2) {
//        printf("文件参数不对");
//        exit(EXIT_FAILURE);
//    }
//    FILE *fp;
//    int ch;
//    for (int i = 1; i < argc; i++) {
//        if ((fp = fopen(argv[i], "r")) == NULL) {
//            printf("%s无法打开",argv[i]);
//        }else{
//            while ((ch = getc(fp)) != EOF) {
//                putchar(ch);
//            }
//            fclose(fp);
//        }
//    }
//    printf("\n");
    
    //22.2
//    FILE *fp = fopen("aa.txt", "r");
//    int ch;
//    while ((ch = getc(fp)) != EOF) {
//        fputc(toupper(ch), stdout);
//    }
//    printf("\n");
//    fclose(fp);
    
    //22.1
//    FILE *fp;
//    if (argc < 2) {
//        printf("canopen filename");
//        exit(EXIT_FAILURE);
//    }
//    for (int i = 1; i < argc; i++) {
//        if ((fp = fopen(argv[i], "r")) == NULL) {
//            printf("%s can't be opened\n",argv[i]);
//        }else{
//            printf("%s can be opened\n",argv[i]);
//            fclose(fp);
//        }
//    }
    
    //22.16
//    char *str = "asdfsdfsdf#1231,23\n,dd";
//    char aa[100];
//    sscanf(str, "%*[^#]#%[0123456789,\n]",aa);
//    printf("===>%s",aa);
    
    //22.15
//    (a)fseek(fp, 64L * (n - 1), SEEK_SET)
//    (b)fseek(fp, -64L, SEEK_END)
//    (c)fseek(fp, 64L, SEEK_CUR)
//    (d)fseek(fp, -128L, SEEK_CUR)
    
    //22.14 (b)
//    char aa[] = "\nThis is a question!";
//    FILE *fp = fopen("fp2.txt", "a");
//    my_fputs(aa, fp);
    
    //22.14 (a)
//    char ch[100];
//    FILE *fp = fopen("fp2.txt", "r");
//    my_fgets(ch, 10, fp);
//    printf("%s\n",ch);
    
    //22.13 返回第n行的长度，第一行是1
//    printf("====>%d\n",line_length("line_length.txt", 1));
    
    //22.12
//    printf("===>%d\n",count_periods("fp1.txt"));
    
//    22.8
//    char c;
//    scanf(" %c",&c);
//    printf("====>%c",c);
    
//    char ch[10];
//    scanf("%1s",ch);//字符串多一个空字符
//    printf("====>%s",ch);
    
    //22.7
//    (a)10*20*30
//    (b)1.0*2.0*3.0
//    (c)0.1*0.2*0.3
//    (d).1*.2*.3
    
//    int i,j,n;
//    float x;
//    n = scanf("%d%f%d",&i,&x,&j);
//    printf("%d  %f  %d   %d\n",i,x,j,n);
    
//    22.6
//    int widget = 2;
//    printf(widget == 1?"%d widget\n":"%d widgets\n",widget);
    
//    22.5
//    printf("%.4d\n",123456789);
//    printf("%04d\n",123456789);
    
//    22.4      %#012.5g     %10.5g
//    (a)83.7361    00000083.736
//    (b)29748.6607  000000029748.
//    (c)1054932234.0 001.0549e+09
//    (d)0.0000235218 002.3521e-05
    
//    22.3
//    FILE *fp;
//    fp = fopen("fp1.txt", "r");
//    int ch;
//    if (fp) {
//        while ((ch = getc(fp)) != EOF) {
//            printf("%c",ch);
//        }
//    }
//    fclose(fp);
    
//    22.2
//    rb+  a  rb   r
    
    //字符串的输入、输出
    //输出
//    int     sprintf(<#char *restrict#>, <#const char *restrict, ...#>)//返回所存储字符的数量，错误返回负值
//    sprintf(date, "%d/%d/%d", 9, 20, 2010);
//    int     snprintf(<#char *restrict __str#>, <#size_t __size#>, <#const char *restrict __format, ...#>)
//    snprintf(name, 13, "%s,%s","Einstein","Albert");
    //输入
//    int     sscanf(const char * __restrict, const char * __restrict, ...)//从字符串读入，返回读入项的数量
//    fgets(str, sizeof(str), stdin);
//    sscanf(str, "%d%d",&i,&j);
    
    //文件定位
//    int     fseek(FILE *, long, int);//第二个参数是移动的字节数
//SEEK_SET:文件起始处
//SEEK_CUR:当前位置
//SEEK_END:文件末尾
//    fseek(fp, 0, SEEK_SET);//移动到文件起始位置
//    fseek(fp, 0, SEEK_END);//移动到文件末尾位置
//    fseek(fp, -10L, SEEK_CUR);//往回移动10个字节
    //正确返回0，错误返回非0

//    long     ftell(FILE *);//以长整数返回当前文件位置
//    void     rewind(FILE *);//把文件位置设置在起始处
    
//    int     fgetpos(FILE * __restrict, fpos_t *);
//    int     fsetpos(FILE *, const fpos_t *);
     //正确返回0，错误返回非0
//    fpos_t file_pos;
//    fgetpos(fp, &file_pos);
//    fsetpos(fp, &file_pos);
    
    
    //块的输入、输出(多数用于二进制流)
//    int a[10];
//    size_t     fread(void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream);//返回读到的元素的数量
//    n = fread(a, sizeof(a[0]), sizeof(a)/sizeof(a[0]), fp)
//    size_t     fwrite(const void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream)//返回写入元素的数量
//    fwrite(a, sizeof(a[0]), sizeof(a)/sizeof(a[0]), fp)
//    fwrite(&s, sizeof(s), 1, fp)
    
    //行的输入、输出(多少用于文本流)
    //输出
//    int     fputs(const char * __restrict, FILE * __restrict)//不会自动加换行符,出错返回EOF，否则非负数
//    int     puts(const char *);//会自动加换行符,出错返回EOF，否则非负数
    //输入
//    char    *fgets(char * __restrict, int, FILE *);//可以限制读取数量 fgets(str, sizeof(str), fp) 读入sizeof(str)-1个或读到换行符
//    char    *gets(char *);//读到换行符为止
    
    //复制文件
//    FILE *source_fp,*dest_fp;
//    int ch;
//    if (argc != 3) {
//        fprintf(stderr, "参数不对!");
//        exit(EXIT_FAILURE);
//    }
//    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
//        fprintf(stderr, "不能打开 %s\n",argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
//        fprintf(stderr, "不能打开 %s\n",argv[2]);
//        fclose(source_fp);
//        exit(EXIT_FAILURE);
//    }
//
//    while ((ch = getc(source_fp)) != EOF) {
//        if (putc(ch, dest_fp) == EOF) {
//            fprintf(stderr, "复制时错误");
//            exit(EXIT_FAILURE);
//        }
//    }
//    fclose(source_fp);
//    fclose(dest_fp);
    
    //字符的输入输出
    //输出函数
//    int     fputc(int, FILE *);
//    int     putc(int, FILE *);//常用，快
//    int     putchar(int);
    //输入函数
//    int     fgetc(FILE *);
//    int     getc(FILE *);
//    int     getchar(void);
//    int     ungetc(int, FILE *);//把读入的字符放回并清除流的文件末尾指示器
    
//    惯用法：从文件中逐个读入字符直到遇到文件末尾
//    while ((ch = getc(fp)) != EOF) {
//        ;
//    }
    
//    fscanf(fp, "%*[^\n]")//读到这一行末尾
    //清除文件末尾指示器和错误指示器
//    void     clearerr(FILE *);
    //流设置了文件末尾指示器，就返回非0
//    int     feof(FILE *);
    //流设置了错误指示器，就返回非0
//    int     ferror(FILE *);

    
//    int     fscanf(FILE * __restrict, const char * __restrict, ...)
//    int     scanf(const char * __restrict, ...)
    
//    int     printf(const char * __restrict, ...)
//    int     fprintf(FILE * __restrict, const char * __restrict, ...)
    
//    删除文件
//    int     remove(const char *);
//    文件重命名
//    int     rename (const char *__old, const char *__new);
    
    //文件缓冲
//    int     fflush(FILE *);
//    fflush(fp)//清洗了fp相关的缓冲区
//    fflush(NULL)//清洗了所有
//    成功返回0，失败返回EOF
    
//    void     setbuf(FILE * __restrict, char * __restrict);
//    设置缓冲模式和缓冲区大小
    
//    int     setvbuf(FILE * __restrict, char * __restrict, int mode, size_t);
//    char buffer[N];
//    setvbuf(stream, buffer, _IOFBF, N);
//    成功返回0，失败返回非0
    
//    创建临时文件
//    FILE    *tmpfile(void);
//    为临时文件产生名字
//    tmpnam(NULL)
//    mkstemp(NULL);
//    L_tmpnam//指明了保存临时文件名的字符数组长度
    
//    char filename[L_tmpnam];
//    tmpnam(filename);
    
//    为打开的流附加文件
//    FILE    *freopen(const char * __restrict, const char * __restrict,
//                     FILE * __restrict)
//    //往foo文件写数据
//    if (freopen("foo", "w", stdout) == NULL) {
//
//    }
    //打开文件
//    FILE    *fopen(const char * __restrict __filename, const char * __restrict __mode)
//    FILE *fp = fopen("in.dat", "r");
//    if ((fp = fopen("in.dat", "r")) == NULL) {
//
//    }
    
//    关闭文件
//    int     fclose(FILE *);
    
//    ptrdiff_t
//    size_t
//    wchar_t
//    offsetof(struct ss, a)
    //21.1
//    printf("大小:%lu\n",sizeof(struct ss));
//    struct ss sss;
//    printf("a大小:%lu\n",sizeof(sss.a));
//    printf("a:%lu\n",offsetof(struct ss, a));
//    printf("b:%lu\n",offsetof(struct ss, b));
//    printf("c:%lu\n",offsetof(struct ss, c));
    
    //20.1
//    my_float_union.my_float_l.f = 1;
//    my_float_union.my_float_l.z = 128;
//    my_float_union.my_float_l.x = 0;
//    printf("%f\n",my_float_union.ff);
    
    //20.16
//    regs.dword.eax = 0x123456789abcdef1;
//    regs.byte.ah = 0x12;
//    regs.byte.al = 0x34;
//    printf("%hx\n",regs.word.ax);
//    printf("%lx\n",regs.dword.eax);
    
    
    //20.13
//    char n = 0b00001111;
//    printf("%d\n",n);
//    while (n) {
//        n &= n - 1;
//        printf("%d\n",n);
//    }
    
    //20.11
//    if ((0x0000 &(1|2|4)) == 0) {
//        printf("======>");
//    }
    //20.9
//    printf("%d\n",count_ones(0b11100000));
    //20.7
//    printf("0x%.8x\n",rotate_left(0x12345678, 16));
//    printf("0x%.8x\n",rotate_right(0x12345678, 16));
    //20.6
//    unsigned short s;
//    printf("输入一个short:");
//    scanf("%hx",&s);//1234
//    printf("交换后0x%.4x\n",swap_bytes(s));
    //20.4
//    long c = MK_COLOR(123,9,100);
//    printf("0x%.8lX\n",c);//0x0064097B
    //20.5
//    printf("%ld\n",GET_BLUE(c));
//    printf("%ld\n",GET_GREEN(c));
//    printf("%ld\n",GET_RED(c));
//    20.3
//    unsigned short x = 0x0010,y = 0x1000;
//    x ^= y;//0x1010
//    y ^= x;//0x0010
//    x ^= y;//0x1000
//    printf("0x%.4x\n",x);
    
//    20.2
//    unsigned short i = 0x0001;
//    i ^= 0x0010;
//    printf("0x%.4x\n",i);
    
    //20.1
//    unsigned short i,j,k;
    //    (a)0
//    i = 8;j = 9;
//    printf("%d\n", i >> 1 + j >> 1);
//    (b)0
//    i = 1;
//    printf("%d\n", i & ~i);
//    (c)1
//    i = 2;j = 1;k = 0;
//    printf("%d\n",~i & j ^ k);
//    (d)15
//    i = 7;j = 8;k = 9;
//    printf("%d\n", i ^ j & k);
    
    //十六进制====>二进制
    //    0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F
    //    0000  0001  0010  0011  0100  0101  0110  0111  1000  1001  1010  1011  1100  1101  1110  1111
    
    //修改位域
//    i = i & ~0x0070 | 0x0050
//    i = i & ~0x0070 | j << 4
    
    //    0000 0000 0111 0000
    // ~  1111 1111 1000 1111
    //    0000 0000 0000 0001
    // &  0000 0000 0000 0001
    // |  0000 0000 0101 0000
    //    0000 0000 0101 0001
    
    //获取位域
//    j = i & 0x0007
//    j = (i >> 4) & 0x0007
    
    
//    printf("%d\n",1 << 3);//0001 ---> 1000
//    //位运算符
//    unsigned short i = 0x0000;
//    unsigned short j = 3;
//    i |= 0x0010;
//    i |= 1 << j;//位的设置-惯用法
//
//    i = 0x00ff;//                           0000 0000 1111 1111
//    i &= ~0x0010;//0000 0000 0001 0000 ---> 1111 1111 1110 1111 ----> 0000 0000 1110 1111
//    i &= ~(1 << j);//位的清除-惯用法
//
//    if (i & 0x0010) {
//
//    }
//    if (i & 1 << j) {//位的测试-惯用法
//
//    }
    
//    int *a = malloc(sizeof(int) * 3);
//    a[0] = 1;
//    a[1] = 2;
//    a[2] = 3;
//
//    a = realloc(a, sizeof(int) * 6);
//    printf("%d\n",a[1]);
    
//    struct my_node *n = malloc(sizeof(struct my_node));
//
//        printf("a address: 0x%.16tX\n",n->node);
//    if (n == NULL) {
//        printf("==========");
//    }
    
    //18.13
    //acd
    
    //18.12
    //f是函数,参数1是函数指针，参数2是字符串，返回值是函数指针
//    int (*f(float (*)(long),char *))(double);
//    f(&f_p, "11");
    
    //18.11
//    int(*a[10])(int);
    
    //18.10
//    (a)
//    char *(*p)(char *);
//    (b)
//    void *f(struct t *p,long n)(void)
//    (c)
//    void(*a[4])(void) = {insert,search,update,print};
//    (d)
//    struct t(*b[10])(int,int);
    
    //18.9
    //(a)
//    X_Fun_Ptr_Array x;
//    (b)
    
    //18.8
//    char (*x[10])(int);//x是函数指针的数组，函数返回值是char,参数是int
//    int (*a(int))[5];//a是函数,参数是int 返回值是一个数组的指针
//    float *(*b(void))(int);//b是函数，参数是void,返回值是 一个函数指针，参数是Int，返回值是float *
//    x is a function with no arguments that returns a pointer to a function with an int argument that returns a pointer to a float value.
    
//    void (*xx(int, void (*yy)(int)))(int);
//    x is a function with two arguments. The first argument is an integer, and the second is a pointer to a function with an int argument and no return value. x returns a pointer to a function with an int argument and no return value. (Although this example may seem artificially complex, the signal function—part of the standard C library—has exactly this prototype. See p. 632 for a discussion of signal.)
    
    
//    my_test();
//    my_test_int--;
//    printf("main = %d\n",my_test_int);
    
//    my_test();
//    int *(*x[10])(void);
    
//    const int n = 10;
//    static int a[n];
//    a[0] = 100;
//    printf("%d\n",a[0]);
    
//    my_debug_fun();
//    printf("%d\n",my_debug_int);
    
    //17.5
//    read_word_sort();
    //17.17
//    int a[100];
//    qsort(&a[50], 50, sizeof(int), compar);
    //17.9
//    struct point pp = (struct point){1,2};
//    printf("===>%d\n",(&pp)->x);
//    printf("===>%d\n",pp.x);
    
    //17.4
//    struct rectangle *p_rec = malloc(sizeof(struct rectangle));
//    p_rec->upper_left.x = 10;
//    p_rec->upper_left.y = 25;
//    p_rec->lower_right.x = 20;
//    p_rec->lower_right.y = 15;
    
    //17.3
//    int *a = create_array(10, 6);
//    for (int *p = a; p < a + 10; p++) {
//        printf("%d\n",*a);
//    }
    
    //17.2
//    char *c = duplicate("哈哈哈");
//    printf("%s\n",c);
    
//    char *aa[] = {"f","aa","d","b","c","e"};
//    qsort(aa, 6, sizeof(aa[0]), compare);
//    for (int i = 0; i < 6; i++) {
//        printf("%s,",aa[i]);
//    }
//    printf("\n");
    
//    struct Test2
//    {
//        int a;
//        int array[];
//    };
////    printf("Test2 size:%zu\n",sizeof(struct Test2));
//    struct Test2 t;
//    t.a = 1;
//    t.array[0] = 100;
//
//    struct Test2 tt = t;
//    printf("%d   %d\n",tt.a, tt.array[0]);
    
//    int * restrict p;
//    int * restrict q;
//    p = malloc(sizeof(int));
////    *p = 1;
//    q = p;
//    *q = 1;
    
//    int a = 1;
//    int * restrict p = &a;
////    *p = 2;
//    int *q = &a;
//    *q = 3;
//    printf("%d\n",a);
    
//    printf("%d\n",strcmp("ab", "c"));
    
//    int aa[10] = {2,22,4,9,3,2,1,66,12,10};
//    qsort(aa, sizeof(aa)/sizeof(aa[0]), sizeof(aa[0]), compar);
//    for (int i = 0; i < 10; i++) {
//        printf("%d,",aa[i]);
//    }
//    printf("\n");
    
//    int n = 10;
//    void *a = calloc(n, sizeof(int));
    
//    void *p;
//    char *p;
//    if ((p = malloc(10000)) == NULL) {
//        printf("内存分配失败");
//    }
//    strcpy(p, "abcd");
//    printf("%s\n",p);
    
    //16.5 5-9输入两个日期比大小
//    riqibidaxiao();
    //16.1国家区号
//    country_start();
    //16.18 国际象棋
//    Square board[8][8];
    //16.8
//    const struct color MAGENTA = {255,0,255};
//    const struct color MAGENTA = {.red = 255,.blue = 255};
    //16.7分数运算
//    struct fraction ff = f_xiangjia((struct fraction){1,2}, (struct fraction){1,3});
//    printf("%d/%d\n",ff.numerator,ff.denominator);
    //16.6
//    struct time t = split_time1(10000);
//    printf("%d %d %d\n",t.hours,t.minutes,t.seconds);
    //16.4
//    Complex c = {1.0,2.0};
    //16.2
//    struct c c1 = {0,1.0};
//    struct c c2 = {1.0,0};
//    c1 = c2;
//    printf("%f\n",c1.real);
//    struct c c3 = {c1.real + c2.real,c1.imaginary + c2.imaginary};
    
    //    printf("%d\n",isspace(' '));
//    start();
    //15.4
//    int i = 1, j = 2, k = 3;
//#ifdef DEBUGG
//    printf("DEBUGG is defined\n");
//#else
//    printf("DEBUGG is not defined\n");
//#endif
//    PRINT_DEBUG(i);
//    PRINT_DEBUG(j);
//    PRINT_DEBUG(k);
    
//    return justify();
    
    //14.16
//    IDENT(foo);
    //14.15
//#ifdef FRENCH
//    printf("le\n");
//#endif
    //14.11
//    ERROR("Range error: index = %d\n", 11);
    //14.9
//    printf("%d\n",CHECK(78, 891, 100));
    //14.8
//    const char *str = LINE_FILE;
//    printf("%s\n",str);
    //14.6
//    DISP(sqrt, 3.0);
    //14.2 数组元素个数
//    int a[] = {1,2,3};
//    printf("%lu\n",NELEMS(a));
    //13.16 12-1 逆序打印输入 Don't get mad,get even. .neve teg,dam teg t'noD
//    char a[] = "Don't get mad,get even.";
//    reverse(a);
    //13.14  8-16判断两个单词是否变位词  smartest
//    printf("%d\n",are_anagrams("smartest", "mattress"));
    //13.12 8-14 颠倒语句单词 you can cage a swallow can't you? you can't swallow a cage can you?
//    diandaoyujudanci2("you can cage a swallow can't you?");
    //13.11 7-13计算一个英文语句的平均单词长度
//    printf("%f\n",compute_average_word_length("a b cd efg hijk mnmkl"));
    //13.10 7.11 修改一个姓名  jim green ==> green, J.
//    char name[] = "jim green";
//    reverse_name(name);
    //13.9 7.10 返回一个单词的元音个数
//    printf("%d\n",compute_vowel_count("asdfboki"));
    //13.8 7.5 返回十字拼字游戏的单词值
//    printf("%d\n",compute_scrabble_value("pitfall"));
    //13.5程序参数求和
//    int sum = 0;
//    for (int i = 1; i < argc; i++) {
//        sum += atoi(argv[i]);
//    }
//    printf("%d\n",sum);
    //13.4逆序打印程序参数
//    for (int i = argc - 1; i > 0; i--) {
//        printf("%s ",argv[i]);
//    }
    //13.1找出最小最大单词
//    find_maxminword();
    //13.18
//    char url[] = "http://baidu.com/index.html";
//    remove_filename(url);
//    printf("%s\n",url);
    //13.17 检测后缀名是否正确
//    printf("%d\n",test_extension("123.txt", "txt"));
    //13.15
//    3
//    0
    //13.14
//    char s[] = "Hsjodi", *p;
//    for (p = s; *p; p++) {
//        --*p;
//    }
//    puts(s);
    //13.13 生成首页
//    char domain[] = "baidu.com";
//    char index_url[200];
//    build_index_url(domain, index_url);
//    printf("%s\n",index_url);
    //13.12 获取扩展名
//    char *file_name = "123.txt";
//    char extension[10];
//    get_extension(file_name, extension);
//    printf("%s\n",extension);
    //13.9
//    char s1[20] = "computer";
//    char s2[20] = "science";
//    if (mystrcmp(s1, s2) < 0) {
//        strcat(s1, s2);
//    }
//    s2[strlen(s2) - 6] = '\0';
//    printf("%s\n",s1);
    // 13.6把foo替换为xxx
//    char a[] = "food fool";
//    censor(a);
//    printf("%s\n",a);
    // 13.5 把参数中字母改为大写
//    char a[] = "abc123def[]";
//    capitalize1(a, 11);
//    printf("%s\n",a);
    //12-2 检查是否是回文
//    check_huiwen();
    //12-1 逆序打印输入
//    zhizhen_nixudayin();
    //12-17 二维数组的和
//    printf("%d\n",sum_two_dimensional_array((int[2][4]){{1,2,3,4},{1,2,3,4}}, 2));
    //12-12 找出数组最大和第二大元素
//    int f, s;
//    zhizhen_find_two_largest((int []){11,22,33,4,1,2,6,56,101,44}, 10, &f, &s);
//    printf("%d %d\n", f, s);
    //12-9 数组元素乘的和
//    printf("%f\n",zhizhen_inner_product((double []){1,2,3}, (double []){1,2,3}, 3));
    //12-7 数组是否包含某个元素
//    printf("%d\n",zhizhen_search((int []){1,2,3,4,5,6,7,8,9,10}, 10, 10));
//12-6 指针算数运算修改函数
//    printf("%d\n",zhizhen_sum_array((int []){1,2,3,4,5,6,7,8,9,10},10));
    //12-3 首尾交换
//    shouweijiaohuan();
    //11-7最大元素的指针
//    int *max = find_largest((int []){11,22,33,4,1,2,6,56,101,44}, 10);
//    printf("%d \n", *max);
    //11-6寻找第一第二大元素
//    int f, s;
//    find_two_largest((int []){11,22,33,4,1,2,6,56,101,44}, 10, &f, &s);
//    printf("%d %d\n", f, s);
    //11-5计算从0点开始当前时间
//    int h, m, s;
//    split_time(10000, &h, &m, &s);
//    printf("%d %d %d\n", h, m, s);
    //11-4交换两个变量的值
//    int a = 1,b = 2;
//    swap(&a, &b);
//    printf("%d %d\n",a,b);
    //10-6逆波兰表示法
//    printf("输入一串逆波兰表示法:");
//    char ch;
//    while ((ch = getchar())) {
//        if (ch == '\n') {
//            continue;
//        }
//        if (ch >= '0'&&ch <= '9') {
//            push(ch);
//        }else if (ch == '+'||ch == '-'||ch == '*'||ch == '/') {
//            int two = pop() - 48;
//            int one = pop() - 48;
//            int result = 0;
//            switch (ch) {
//                case '+':
//                    result = one + two;
//                    break;
//                case '-':
//                    result = one - two;
//                    break;
//                case '*':
//                    result = one * two;
//                    break;
//                case '/':
//                    result = one / two;
//                    break;
//                default:
//                    break;
//            }
//            push(result + 48);
//        }else if (ch == '=') {
//            printf("结果:%d\n",contents[top - 1] - 48);
//            make_empty();
//        }
//    }
    
    //10-1括号是否嵌套正确
//    printf("输入一串括号:");
//    char ch;
//    bool flag = true;
//    while ((ch = getchar())) {
//        if (ch == '\n') {
//            break;
//        }
//        if (ch == '{'||ch == '(') {
//            push(ch);
//        }else if ((ch == '}' || ch == ')')&&pop() == ch){
//            flag = false;
//        }
//    }
//    if (is_empty()||flag) {
//        printf("嵌套正确\n");
//    }else{
//        printf("嵌套不正确\n");
//    }
    
    //9-8掷骰子游戏
//    int win = 0;
//    int lose = 0;
//    char ch;
//    do {
//        if (play_game()) {
//            win++;
//        }else{
//            lose++;
//        }
//        printf("Play again?\n");
//        scanf(" %c",&ch);
//        printf("\n");
//    } while (toupper(ch) == 'Y');
//    printf("wins:%d losses:%d\n",win,lose);
    
    //9-7幂递归
//    printf("%f\n",midigui(2, 5));
    //9-6计算多项式的值
//    printf("%f\n",duoxiangshi(2));
    //9-1升序排列数组
//    int a[] = {11,5,3,22,6};
//    selection_sort(a, 5);
//    for (int i = 0; i < 5; i++) {
//        printf("%d,",a[i]);
//    }
//    printf("\n");
    //9-18用递归求公约数
//    printf("%d\n",gcd(52, 24));
    //9-12数组相乘的和
//    printf("%f\n",inner_product((double []){1,2}, (double []){2,3}, 2));
    //9-11计算等级的平均值
//    printf("%f\n",compute_GPA((char []){'a','b','c','d','f','a'},6));
    //9-10返回数组最大数,平均值,正数数量
//    printf("%d\n",arrayMax((int []){1,2,3,4,-5,6,7,8,9}, 9));
    //9-6返回n的第k位数字
//    printf("%d\n",digit(1234567,3));
    //9-5计算n的位数
//    num_digits(1234567);
    //8-17 打印nxn的幻方
//    dayinNhuanfang();
    //8-16判断两个单词是否变位词
//    bianweici();
    //8-15凯撒加密
//    kaisajiami();
    //8-14颠倒语句单词
//    diandaoyujudanci();
    //8-9随机走
//    suijizou();
    //8-7 5✖️5矩阵 行、列的和
//    wujuzhen();
    //8-6b1ff转换
//    b1ff();
    //8-1重复数字
//    chongfushuzi();
    //8-5斐波那契数
//    feibonaqi();
    //7-14牛顿方法求平方根
//    niudunfangfa();
    //7-13计算平均词长
//    pingjuncichang();
    //7-12从左往右顺序求值
//    shunxuqiuzhi();
    //7-11指定格式输出英文名
//    shuchuyingwenming();
   //7-10计算元音个数
//    tongjiyuanyin();
    //12小时制转24小时制
//    shierzhuanershisi();
    //字母电话转换为数字
//    zimudianhua();
    //数学常量e
//    qiue();
    //日历
//    rili();
    //约分
//    yuefen();
    //求最大公约数
//    gongyueshu();
    
    //把十进制转为八进制
//    print10to8();
    //逆序打印两位数
//    nixuliangwei();
//    nixujiwei();
    //幻方
//    huanfnag();
    //电话输出
//    dianhuashuchu();
    //日期输出
//    riqishuchu();
    
    //3.1_1
//    printf("%6d,%4d\n", 86, 1040);//____86 1040
//    printf("%12.5e\n",30.253);//_3.02530e+01
//    printf("%.4f\n",83.162);//83.1620
//    printf("%-6.2g\n",.0000009979);//1e-06_
    
    
    //输入1-20.3-4.0e3
//    int i,j;
//    float x,y;
//    scanf("%d%d%f%f", &i,&j,&x,&y);
//    scanf("%d/%d",&i,&j);
//    printf("==>%d,%d,%f,%f\n",i,j,x,y);
    
    //计算贷款余额
//    daikuanyue();
    
    //美元付钱
//    meiyuanfuqian();
    
    //求方程式的值
//    fangchengshi();
    
    //显示美金
//    meijin();
    
    //计算球体积
//    qiuti_tiji();
//    qiuti_tiji2();
    return 0;
}
