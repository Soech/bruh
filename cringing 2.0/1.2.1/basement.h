#ifndef BASEMENT_H
#define BASEMENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

string chooseBowString(const string& prompt, const string& currentMat = "");

class Bow {
private:
    double strength;
    string BowStringMat;

    static int objectCount;

public:
    Bow();
    Bow(double str, string bsm);
    Bow(const Bow& other);
    ~Bow();

    double getStrength() const { return strength; }
    string getBowStringMat() const { return BowStringMat; }
    void setStrength(double str) { strength = str; }
    void setBowStringMat(string bsm) { BowStringMat = bsm; }

    void restring(string bsm);
    void test() const;

    static int getObjectCount();

    friend void inspectBow(const Bow& b);
};

class SelfManagedBow {
private:
    double strength;
    string BowStringMat;

    SelfManagedBow(double str, string bsm);
    ~SelfManagedBow();

public:
    static SelfManagedBow* createObject(double str, string bsm);
    static SelfManagedBow* createRandomObject();
    static void destroyObject(SelfManagedBow* ptr);

    void test() const;
};

class FriendManagedBow {
private:
    double strength;
    string BowStringMat;

    FriendManagedBow(double str, string bsm);
    ~FriendManagedBow();

    friend FriendManagedBow* createFriendBow(double str, string bsm);
    friend FriendManagedBow* createRandomFriendBow();
    friend void destroyFriendBow(FriendManagedBow* ptr);

public:
    void test() const;
};

FriendManagedBow* createFriendBow(double str, string bsm);
FriendManagedBow* createRandomFriendBow();
void destroyFriendBow(FriendManagedBow* ptr);

#endif