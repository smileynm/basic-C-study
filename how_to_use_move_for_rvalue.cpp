#include <iostream>
#include <vector>
#include <utility> // std::move를 사용하기 위해 필요

class MyData {
public:
    int* data;
    size_t size;

    // 생성자
    MyData(size_t s) : size(s), data(new int[s]) {
        std::cout << "생성자 호출, size: " << size << std::endl;
        for(size_t i = 0; i < size; ++i) data[i] = i;
    }

    // 소멸자
    ~MyData() {
        std::cout << "소멸자 호출" << std::endl;
        delete[] data;
    }

    // 복사 생성자 (깊은 복사)
    MyData(const MyData& other) : size(other.size), data(new int[other.size]) {
        std::cout << "복사 생성자 호출 (깊은 복사), size: " << size << std::endl;
        for(size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }

    // 복사 대입 연산자
    MyData& operator=(const MyData& other) {
        std::cout << "복사 대입 연산자 호출" << std::endl;
        if (this != &other) {
            delete[] data; // 기존 자원 해제
            size = other.size;
            data = new int[size];
            for(size_t i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    // 이동 생성자 (r-value 참조 활용)
    MyData(MyData&& other) noexcept : size(other.size), data(other.data) { // noexcept를 붙이는 것이 관례입니다.
        std::cout << "이동 생성자 호출 (자원 소유권 이전), size: " << size << std::endl;
        // 원래 객체의 자원을 무효화
        other.data = nullptr;
        other.size = 0;
    }

    // 이동 대입 연산자 (r-value 참조 활용)
    MyData& operator=(MyData&& other) noexcept {
        std::cout << "이동 대입 연산자 호출" << std::endl;
        if (this != &other) {
            delete[] data; // 기존 자원 해제

            size = other.size;
            data = other.data;

            // 원래 객체의 자원을 무효화
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

// 객체를 반환하는 함수 (임시 객체 생성)
MyData createMyData(size_t s) {
    return MyData(s); // 여기서 MyData(s)는 r-value (임시 객체)
}

int main() {
    std::cout << "--- 이동 시맨틱 예제 ---" << std::endl;

    std::cout << "\ncase 1: 일반 복사 (Copy)" << std::endl;
    MyData original(10); // 생성자 호출
    MyData copy = original; // 복사 생성자 호출

    std::cout << "\ncase 2: 이동 (Move) - std::move 사용" << std::endl;
    // std::move는 l-value를 r-value 참조로 "캐스팅"하여 이동 생성자/대입 연산자가 호출되도록 합니다.
    MyData original2(10); // 생성자 호출
    MyData moved = std::move(original2); // 이동 생성자 호출

    std::cout << "\ncase 3: 함수 반환 값 (RVO 또는 이동)" << std::endl;
    // 대부분의 컴파일러에서 RVO(Return Value Optimization)가 발생하지만,
    // RVO가 불가능한 경우 이동 생성자가 호출됩니다.
    MyData from_function = createMyData(10);

    std::cout << "\n--- 예제 종료 ---" << std::endl;

    return 0;
} // 여기서 객체들의 소멸자가 호출됩니다.
