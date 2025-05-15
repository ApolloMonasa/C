/*************************************************************************
	> File Name: 7.Mystring.cpp
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 24 Apr 2025 01:41:19 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cctype>
#include<utility>
using namespace std;

class MyString {
    char* data;
    size_t length;

    void allocateAndCopy(const char* str, size_t len) {
        if (str && len) {
            data = new char[len + 1];
            strncpy(data, str, len);
            data[len] = '\0';
            length = len;
        } else {
            data = NULL;
            length = 0;
        }
    }
public:
    //constructor
    MyString() noexcept : data(NULL), length(0) {}
    //avoid 隐式转换
    explicit MyString(const char* str) {
        if (str) {
            length = strlen(str);
            allocateAndCopy(str, length);
        } else {
            data = NULL;
            length = 0;
        }
    }

    MyString(const char* str, size_t len) {
        allocateAndCopy(str, len);
    }

    //拷贝构造函数
    MyString(const MyString& obj) {
        if (obj.data) {
            allocateAndCopy(obj.data, obj.length);
        } else {
            data = NULL;
            length = 0;
        }
    }

    //移动构造函数
    MyString(MyString&& obj) noexcept
    : data(obj.data), length(obj.length) {
        obj.data = NULL;
        obj.length = 0;
    }
    //析构函数
    ~MyString() {
        delete[] data;
    }
    //拷贝赋值运算符
    MyString& operator=(const MyString& obj){
        if (this != &obj) {
            MyString temp(obj);
            swap(temp);
        }
        return *this;
    }
    //移动赋值
    MyString& operator=(MyString&& obj) noexcept {
        if (this != &obj) {
            delete[] data;
            data = obj.data;
            length = obj.length;
            obj.data = NULL;
            obj.length = 0;
        }
        return *this;
    }

    //swap
    void swap(MyString& obj) noexcept {
        std::swap(data, obj.data);
        std::swap(length, obj.length);
    }

    //比较
    bool operator==(const MyString& obj) const {
        if (length != obj.length) return false;
        if (data == obj.data) return true;
        if (!data || obj.data) return false;
        return strcmp(data, obj.data) == 0;
    }
    bool operator<(const MyString& obj) const {
        if (!data) return obj.data != NULL;
        if (!obj.data) return false;
        return strcmp(data, obj.data) < 0;
    }
    //tolower
    MyString toLower() const {
        if (!data) return MyString();

        MyString result(*this);
        for (size_t i = 0; i < result.length; ++i) {
            result.data[i] = static_cast<char>(tolower(result.data[i]));
        }
        return result;
    }

    // 获取C风格字符串
    const char* c_str() const noexcept { return data; }
    
    // 获取字符串长度
    size_t size() const noexcept { return length; }
    
    // 判断是否为空
    bool empty() const noexcept { return length == 0; }
    
    // 输出运算符
    friend ostream& operator<<(ostream& os, const MyString& str) {
        if (str.data) os << str.data;
        return os;
    }
};

//分割
vector<MyString> splitString(const MyString& str) {
    vector<MyString> words;
    const char* p = str.c_str();

    while (p && *p) {
        //skip
        while (*p && !isalpha(*p)) ++p;
        if (!*p) break;

        //find start
        const char* start = p;
        while (*p && isalpha(*p)) ++p;
        //add
        words.emplace_back(start, p-start);
    }

    return words;
}

//count words
void countWords(const vector<MyString>& words) {
    if (words.empty()) {
        cout << "No words to count.\n";
        return ;
    }

    map<MyString, int> wordCount;
    for (const auto& word : words) {
        ++wordCount[word.toLower()];
    }
    cout << "Word count results (" << wordCount.size() << "unique words) :\n";
    cout << "----------------------------------------\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    //测试拷贝控制和移动
    MyString s1("Hello");
    MyString s2 = s1; //拷贝构造
    MyString s3 = move(s1);//移动构造

    cout << "=== Copy And Move Test ===\n";
    cout << "s1 (after move): " << s1 << endl;
    cout << "s2 (copy): " << s2 << endl;
    cout << "s3 (moved): " << s3 << endl;

    //测试统计单词功能
    cout << "\n=== Word Count Test ===\n";
    MyString text("This is a test string. String proccessing is important! Test test TEST.");
    cout << "Text : " << text << endl;
    auto words = splitString(text);
    countWords(words);

    return 0;
}

