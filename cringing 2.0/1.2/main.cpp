#include "basement.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(0)));

    cout << "ТЕСТИРОВАНИЕ СТАТИЧЕСКОГО СЧЕТЧИКА ОБЪЕКТОВ" << endl;
    cout << "При входе в main создано объектов: " << Bow::getObjectCount() << endl;

    const int SIZE = 3;
    Bow bowArray[SIZE];
    cout << "После создания массива из " << SIZE << " объектов: " << Bow::getObjectCount() << endl;

    Bow* dynBow = new Bow();
    cout << "После динамического создания объекта: " << Bow::getObjectCount() << endl;

    delete dynBow;
    cout << "После удаления динамического объекта: " << Bow::getObjectCount() << endl;

    cout << "\nДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА Bow И ДРУЖЕСТВЕННОЙ ФУНКЦИИ" << endl;
    Bow myBow;
    myBow.test();
    myBow.restring("Кевлар");
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