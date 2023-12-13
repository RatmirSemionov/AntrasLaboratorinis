#include "pch.h"
#include "gtest/gtest.h"
#include "mylib.h"
#include "mylib.cpp"

// Testas klasei Studentas
TEST(StudentasTest, HandlesInputOutput) {
    Studentas studentas;
    studentas.setvardas("John");
    studentas.setpavarde("Doe");
    studentas.setegzaminas(8);
    studentas.addPazymys(5);
    studentas.addPazymys(7);
    studentas.addPazymys(9);
    studentas.addPazymys(10);
    EXPECT_EQ("John", studentas.vardas());
    EXPECT_EQ("Doe", studentas.pavarde());
    EXPECT_EQ(8, studentas.egzaminas());
    EXPECT_EQ(4, studentas.pazymiai().size());
}

// Testas vidurkiui
TEST(VidurkisTest, HandlesAverageCalculation) {
    Studentas studentas;
    studentas.addPazymys(5);
    studentas.addPazymys(7);
    studentas.addPazymys(9);
    studentas.addPazymys(10);
    studentas.setegzaminas(8);
    Vidurkis(studentas);
    EXPECT_FLOAT_EQ(7.9, studentas.vidurkis());
}

// Testas medianai
TEST(MedianaTest, HandlesMedianCalculation) {
    Studentas studentas;
    studentas.addPazymys(5);
    studentas.addPazymys(7);
    studentas.addPazymys(9);
    studentas.addPazymys(10);
    Mediana(studentas);
    EXPECT_DOUBLE_EQ(8.0, studentas.mediana());
}
