// @comment 单行注释
/* @comment 多行注释 */

/// @comment 文档注释
#pragma once // @preproc 预处理指令

// @module 模块声明 (C++20)
export module shapes;

// @module 模块导入
import std.core;

// @type 类型定义
template<typename T>
class [[deprecated]] Shape { // @attribute 属性
public:
    virtual ~Shape() noexcept = default;
    virtual T area() const = 0;
    
    // @function 方法声明
    void scale(double factor) {
        // @variable.builtin this指针
        this->m_factor *= factor;
    }

private:
    double m_factor = 1.0;
};

// @type 具体类型
class Circle : public Shape<double> {
    constexpr Circle(double r) : radius(r) {} // @keyword 关键字
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double radius;
};

// @function 模板函数
template<integral T> // @type 概念约束 (C++20)
T add(T a, T b) requires (sizeof(T) > 2) {
    return a + b;
}

// @function 自由函数
auto lambda_example() {
    // @function lambda表达式
    return [](int x) -> std::future<int> {
        co_return x * 2; // @keyword 协程关键字
    };
}

// @constant 常量表达式
constexpr int MAX_SIZE = 100;

// @string 字符串字面量
const char* greeting = "Hello \nWorld";
const wchar_t* unicode_str = L"宽字符串";
const char8_t* utf8_str = u8"UTF-8字符串";

// @string 原始字符串
const char* raw_str = R"(Raw
String)";

int main() try { // @keyword 异常处理
    // @type 自动类型推导
    auto ptr = std::make_unique<Circle>(5.0);
    
    // @function 函数调用
    std::cout << "Area: " << ptr->area() << '\n';
    
    // @constant 空指针
    if (ptr != nullptr) {
        ptr->scale(1.5);
    }
    
    // @number 数值字面量
    return 0x1A;
} 
catch (const std::exception& e) { // @type 异常类型
    std::cerr << e.what();
}

