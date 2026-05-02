// Lab09 - Employee Management System
// UML диаграмын дагуу классуудын харилцаа хэрэгжүүлсэн

#include <iostream>
#include <vector>
#include "Employee.h"
using namespace std;

int main() {

    // ── Division объектууд (1..n хэрэглэнэ) ─────────────────────────────
    Division divIT("Мэдээллийн технологийн хэлтэс");
    Division divHR("Хүний нөөцийн хэлтэс");
    Division divFin("Санхүүгийн хэлтэс");

    // ── JobDescription объектууд ─────────────────────────────────────────
    JobDescription jdBagsh("Багш / Дэд профессор");
    JobDescription jdMentor("Ментор");
    JobDescription jdCEO("Гүйцэтгэх захирал");
    JobDescription jdHR("HR менежер");
    JobDescription jdAnalyst("Санхүүгийн шинжээч");

    // ── Employee 1: Болд ─────────────────────────────────────────────────
    // Байгуулагч дотор Division (1) ба нэг JobDescription (1..n) дамжуулна
    Employee bat("Болд", "NN001", 35,
                 "EMP-001", "Ахлах инженер", "2020-03-01",
                 &divIT, &jdBagsh);

    bat.addJobDescription(&jdMentor); // 1..n: нэмэлт ажлын байр

    // 0..1: Гэр бүлийн хамтрагч тохируулах
    Spouse s1("Номин", "NN002", 32, "2018-06-15");
    bat.setSpouse(&s1);

    // 0..n: Хүүхдүүд нэмэх
    Child c1("Тэмүүлэл", "NN010", 5, "Lego");
    Child c2("Эрдэнэ",   "NN011", 3, "Машин");
    bat.addChild(c1);
    bat.addChild(c2);

    // ── Employee 2: Оюун ─────────────────────────────────────────────────
    Employee oyun("Оюун", "NN003", 28,
                  "EMP-002", "HR Дарга", "2021-07-10",
                  &divHR, &jdHR);

    // Гэр бүлгүй (0..1 → null хэвээр)
    // Хүүхэдтэй
    Child c3("Ану", "NN012", 2, "Барби");
    oyun.addChild(c3);

    // ── Employee 3: Ганбаяр ──────────────────────────────────────────────
    Employee gan("Ганбаяр", "NN004", 45,
                 "EMP-003", "Захирал", "2015-01-01",
                 &divFin, &jdCEO);

    gan.addJobDescription(&jdAnalyst); // 1..n

    Spouse s2("Сарнай", "NN005", 42, "2005-09-20");
    gan.setSpouse(&s2);
    // Хүүхэдгүй (0..n → хоосон хэвээр)

    // ── Бүх мэдээллийг хэвлэх ───────────────────────────────────────────
    cout << "\n===== АЖИЛЧДЫН МЭДЭЭЛЭЛ =====" << endl;
    bat.display();
    oyun.display();
    gan.display();

    // ── vector-т Employee заагч хадгалах ────────────────────────────────
    vector<Employee*> employees = { &bat, &oyun, &gan };
    cout << "\nНийт ажилтны тоо: " << employees.size() << endl;

    return 0;
}
