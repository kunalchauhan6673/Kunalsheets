// https://leetcode.com/problems/gcd-of-odd-and-even-sums/description
class Solution {
public:
    int gdc(int a,int b){
        while(b!=0){
            int temp = a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumEven = (1+n)*n; // calculates sum of n smallest even number
        int sumOdd = n*n;     // calculates sum of n smallest odd number
        return gcd(sumOdd, sumEven);
    }
};

// note: lol even this works:
// class Solution {
// public:
//     int gcdOfOddEvenSums(int n) {
//         return n;
//     }
// };