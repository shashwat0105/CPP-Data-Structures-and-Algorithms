https://leetcode.com/problems/encode-and-decode-tinyurl/

Official
https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/


https://leetcode.com/discuss/interview-question/system-design/?currentPage=1&orderBy=hot&query=


Simple u can map the later part to integers

class Solution {
public:
    map<string, string> mp;
    int num=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++;
        string addOn = to_string(num);
        string ans = "http://tinyurl.com/";
        ans+= (string)addOn;
        mp[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

/////////////////////**********************************

https://youtu.be/4cIDGXBbW34 

else in actual how will u implement a good one

https://leetcode.com/problems/encode-and-decode-tinyurl/solutions/100268/two-solutions-and-thoughts/

https://leetcode.com/problems/encode-and-decode-tinyurl/solutions/1110674/encode-and-decode-tinyurl-short-easy-w-explanation/
