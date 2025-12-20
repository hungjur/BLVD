#include "Struct.h"
bool Bigger(Key k1, Key k2) {
    if (k1.date.y != k2.date.y) {
        return k1.date.y < k2.date.y;
    }

    // Годы совпали
    if (k1.date.m != k2.date.m) {
        return k1.date.m < k2.date.m;
    }

    // Месяцы совпали
    if (k1.date.d != k2.date.d) {
        return k1.date.d < k2.date.d;
    }

    // Даты полностью совпали
    if (k1.fio.f != k2.fio.f) {
        return k1.fio.f > k2.fio.f;
    }

    // Фамилии совпали
    if (k1.fio.i != k2.fio.i) {
        return k1.fio.i > k2.fio.i;
    }

    // Имена совпали
    if (k1.fio.o != k2.fio.o) {
        return k1.fio.o > k2.fio.o;
    }
    return false;
}