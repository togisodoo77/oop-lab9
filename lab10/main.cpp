#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
using namespace std;

const float PI = 3.14159f;

// 1. Template LinkedList class

template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    int count;

    Node* nodeAt(int index) const {
        if (index < 0 || index >= count) { throw out_of_range("Index out of range"); }

        Node* current = head;
        for (int i = 0; i < index; i++) {current = current->next;}
        return current;
    }

public:
    LinkedList() {
        head = nullptr;
        count = 0;
    }

    ~LinkedList() { clear(); }

    // Жагсаалтын сүүлд элемент нэмнэ
    void add(T t) {
        Node* newNode = new Node(t);

        if (head == nullptr) { head = newNode;} 
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        count++;
    }

    // index байрлалд элемент оруулна
    void insert(T t, int index) {
        if (index < 0 || index > count) { throw out_of_range("Index out of range"); }

        Node* newNode = new Node(t);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* prev = nodeAt(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }

        count++;
    }

    // index-р элементийн утгыг буцаана
    T get(int index) const { return nodeAt(index)->data; }

    // C++ хэлэнд delete гэдэг нь keyword тул deleteAt гэж нэрлэв
    void deleteAt(int index) {
        if (index < 0 || index >= count) { throw out_of_range("Index out of range"); }

        Node* del;

        if (index == 0) {
            del = head;
            head = head->next;
        } else {
            Node* prev = nodeAt(index - 1);
            del = prev->next;
            prev->next = del->next;
        }

        delete del;
        count--;
    }

    // Жагсаалтын уртыг буцаана
    int length() const { return count; }

    // Эрэмбэлэх үед хоёр node-ийн data-г солино
    void swapItems(int i, int j) {
        if (i == j) return;

        Node* a = nodeAt(i);
        Node* b = nodeAt(j);

        T temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        count = 0;
    }
};

// 2. Lab07 shape classes

class Shape {
protected:
    char name[30];
    float x, y;

public:
    Shape(const char* n = "Shape", float px = 0, float py = 0) {
        strcpy(name, n);
        x = px;
        y = py;
    }

    const char* getName() const { return name; }

    virtual ~Shape() {}
};

class TwoDShape : public Shape {
public:
    TwoDShape(const char* n = "2DShape", float px = 0, float py = 0)
        : Shape(n, px, py) {}

    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    virtual void show() const = 0;

    virtual ~TwoDShape() {}
};

class Circle : public TwoDShape {
private:
    float radius;

public:
    Circle(float cx, float cy, float r)
        : TwoDShape("Circle", cx, cy) {
        radius = r;
    }

    float area() const override {
        return PI * radius * radius;
    }

    float perimeter() const override {
        return 2 * PI * radius;
    }

    void show() const override {
        cout << left << setw(12) << getName()
             << setw(12) << radius
             << setw(12) << area()
             << setw(12) << perimeter() << endl;
    }
};

class Square : public TwoDShape {
private:
    float side;
    float x2, y2, x3, y3, x4, y4;

public:
    Square(float leftTopX, float leftTopY, float s)
        : TwoDShape("Square", leftTopX, leftTopY) {
        side = s;

        x2 = x + side;  y2 = y;
        x3 = x + side;  y3 = y - side;
        x4 = x;         y4 = y - side;
    }

    float area() const override { return side * side; }
    float perimeter() const override { return 4 * side; }

    void show() const override {
        cout << left << setw(12) << getName()
             << setw(12) << side
             << setw(12) << area()
             << setw(12) << perimeter() << endl;
    }
};

class Triangle : public TwoDShape {
private:
    float side;
    float x2, y2, x3, y3;

public:
    Triangle(float topX, float topY, float s)
        : TwoDShape("Triangle", topX, topY) {
        side = s;

        float h = (sqrt(3.0f) / 2.0f) * side;

        x2 = x - side / 2.0f;
        y2 = y - h;

        x3 = x + side / 2.0f;
        y3 = y - h;
    }

    float area() const override { return (sqrt(3.0f) / 4.0f) * side * side;}
    float perimeter() const override { return 3 * side; }

    void show() const override {
        cout << left << setw(12) << getName()
             << setw(12) << side
             << setw(12) << area()
             << setw(12) << perimeter() << endl;
    }
};

// 3. Shape list functions

int randomInt(int min, int max) { return min + rand() % (max - min + 1); }

void printShapes(const LinkedList<TwoDShape*>& shapes) {
    cout << left << setw(5) << "No"
         << setw(12) << "Type"
         << setw(12) << "Side/R"
         << setw(12) << "Area"
         << setw(12) << "Perim" << endl;

    cout << "--------------------------------------------------\n";

    for (int i = 0; i < shapes.length(); i++) {
        cout << left << setw(5) << i + 1;
        shapes.get(i)->show();
    }
}

void sortByArea(LinkedList<TwoDShape*>& shapes) {
    int n = shapes.length();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (shapes.get(j)->area() > shapes.get(j + 1)->area()) {
                shapes.swapItems(j, j + 1);
            }
        }
    }
}

int main() {
    srand((unsigned)time(0));

    // Template LinkedList нь primitive төрөл дээр ажиллаж байгааг шалгах жишээ
    LinkedList<int> nums;

    nums.add(10);
    nums.add(30);
    nums.insert(20, 1);

    cout << "Integer list length: " << nums.length() << endl;
    cout << "Integer list second value: " << nums.get(1) << "\n\n";

    LinkedList<TwoDShape*> shapes;

    // 20-30 ширхэг санамсаргүй дүрс үүсгэнэ
    int n = randomInt(20, 30);

    for (int i = 0; i < n; i++) {
        int type = randomInt(0, 2);
        float side = (float)randomInt(1, 20);
        float x = (float)randomInt(-10, 10);
        float y = (float)randomInt(-10, 10);

        if (type == 0) { shapes.add(new Circle(x, y, side)); } 
        else if (type == 1) { shapes.add(new Square(x, y, side)); } 
        else { shapes.add(new Triangle(x, y, side)); }
    }

    cout << fixed << setprecision(2);

    cout << "BEFORE SORT\n";
    printShapes(shapes);

    sortByArea(shapes);

    cout << "\nAFTER SORT BY AREA\n";
    printShapes(shapes);

    // Эхлээд shape объектуудыг устгаад, дараа нь node-уудыг устгана
    while (shapes.length() > 0) {
        delete shapes.get(0);
        shapes.deleteAt(0);
    }

    return 0;
}