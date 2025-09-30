class Solution {
    const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

    std::string intToBase64(uint32_t num) {
        std::string result;
        do {
            result = base64_chars[num % 64] + result;
            num /= 64;
        } while (num > 0);
        return result;
    }

public:
    unordered_map<string, string> short2Long;
    int last = 0;
    

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string next = intToBase64(last);
        last++;
        short2Long[next] = longUrl;
        return next;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2Long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));