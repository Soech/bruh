#include "basement.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(0)));

    cout << "ТЕСТИРОВАНИЕ СТАТИЧЕСКОГО СЧЕТЧИКА ОБЪЕКТОВ" << endl;
    cout << "При входе в main создано объектов: " << Bow::getObjectCount() << endl;

    const int bowCount = 3;
    Bow bowArray[bowCount];
    cout << "После создания массива из " << bowCount << " объектов: " << Bow::getObjectCount() << endl;

    Bow* dynBow = new Bow();
    cout << "После динамического создания объекта: " << Bow::getObjectCount() << endl;

    delete dynBow;
    cout << "После удаления динамического объекта: " << Bow::getObjectCount() << endl;

    cout << "\nДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА Bow И ДРУЖЕСТВЕННОЙ ФУНКЦИИ" << endl;
    
    string initialMat = chooseBowString("Выберите ПЕРВОНАЧАЛЬНЫЙ материал тетивы для вашего лука:");
    double randomStr = 10.0 + (rand() % 310) / 10.0;
    Bow myBow(randomStr, initialMat);
    myBow.test();

    string newMat = chooseBowString("Выберите НОВЫЙ материал тетивы для замены:", myBow.getBowStringMat());
    myBow.restring(newMat);
    myBow.test();

    inspectBow(myBow);

    cout << "\n (Методы класса)" << endl;
    SelfManagedBow* smb = SelfManagedBow::createRandomObject();
    smb->test();
    SelfManagedBow::destroyObject(smb);

    cout << "\n (Внешние дружественные функции)" << endl;
    FriendManagedBow* fmb = createRandomFriendBow();
    fmb->test();
    destroyFriendBow(fmb);

    return 0;
}