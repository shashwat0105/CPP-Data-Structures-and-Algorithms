https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<pair<int, string>> m = {{1000, "M"},{900, "CM"} , {500, "D"},{400, "CD"} , {100, "C"} , {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"}, {9, "IX"},{5, "V"} , {4, "IV"},{1, "I"} };

        // You can do separately as well, just add from str array and subtract from val arr for the same index.
        // vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        // vector<string> str{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        // map<int, char> m;     // This map doesn't work well because we want to subtract first by 1000 then 900 and so on ie orderly.
        // m[1] = 'I';
        // m[4] = 'IV';
        // m[5] = 'V';
        // m[9] = 'IX';
        // m[10] = 'X';
        // m[40] = 'XL';
        // m[50] = 'L';
        // m[90] = 'XC';
        // m[100] = 'C';
        // m[400] = 'CD';
        // m[500] = 'D';
        // m[900] = 'CM';
        // m[1000] = 'M';
        
        while(num>0){
            for(auto x: m){
                while(num >= x.first){
                    res += x.second;
                    num -= x.first;
                }
            }
        }
        return res;
    }
};


// Another good solution
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};