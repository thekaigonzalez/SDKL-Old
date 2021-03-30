#include <vector>

/* Array. */
template<typename T>
class Sdk_Class {
private:
    T Cls;
    T& operator=(T Temp) {
        Cls = Temp;
    }
    std::vector<T>Contents{};
public:
    T  shift() {
        T c = Contents[0];
        // Remove The First Content after pushing the original to a buffer
        Contents[0] = '\0';
        return c;
    }
    Sdk_Class<T>ListAll() {
        return Contents;
    }
    T get(int index) {
        return Contents[index];
    }
    void push(T C) {
        Contents.push_back(C);
    }


};