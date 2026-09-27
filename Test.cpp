#include "Test.hpp"
#include "Values.hpp"
#include "Operators.hpp"
#include "Devices.hpp"

#include <iostream>
#include <format>
#include <chrono>

void TestValues() {
    std::cout << "Values testing\n";
    std::cout << "\n";
    Values::Ampere a(1.5);
    std::cout << "Electric current value: " << a.GetValue() << " A\n";

    std::cout << "\n";
    std::cout << "Try to input negative value" << "\n";
    try {
        Values::Volt v(-220.0);
    } catch (const std::invalid_argument& err) {
        std::cout << "Attempt to input negative value of volts: " << err.what() << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
}



void TestOperators() {
    std::cout << "Operators testing\n";
    std::cout << "\n";
    
    Values::Ampere current = Values::operator""_mA(500.0L);
    Values::Ohm resistance = Values::operator""_Ohm(10.0L);
    Values::Second time = Values::operator""_s(2.0L);
    //Values::Joule joule = Values::operator""_J(2.0L);
    //Values::Volt voltage = Values::operator""_V(2.0L);
    //Values::Watt watt = Values::operator""_W(2.0L);


    Values::Volt voltage = current * resistance;
    std::cout << "1) Ohms law: 500 mA * 10 Ohm = " << voltage.GetValue() << " B\n";


    Values::Watt power = voltage * current;
    std::cout << "2) Power: " << voltage.GetValue() << " B * 500 mA = " << power.GetValue() << " W\n";


    Values::Joule energy = power * time;
    std::cout << "3) Work: " << power.GetValue() << " Вт * 2 с = " << energy.GetValue() << " J\n";


    



    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
}



void TestDevices() {
    std::cout << "Devices testing\n";
    std::cout << "\n";
    

    Devices::Ammeter ammeter(0.0, 5.0, 1.5, "A-1");
    Devices::Voltmeter voltmeter(0.0, 300.0, 0.5, "V-1");
    Devices::Multimeter multimeter(0.0, 1000.0, 1.0, "M-1");

    std::cout << "Enter the values for devices: \n";
    std::cout << "\n";
    std::cout << "ammeter(0.0, 5.0, 1.5, \"A-1\")\n";
    std::cout << "voltmeter(0.0, 300.0, 0.5, \"V-1\")\n";
    std::cout << "multimeter(0.0, 1000.0, 1.0, \"M-1\")\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    auto measureAmp = ammeter.Measure();
    std::cout << "Ammeter: " << std::format("{}", measureAmp) << '\n';
    std::cout << "\n";
    
    auto measureVolt = voltmeter.Measure();
    std::cout << "Voltmeter: " << std::format("{}", measureVolt) << '\n';
    std::cout << "\n";



    auto measureOhm = multimeter.Measure<Values::Ohm>();
    std::cout << "Multimeter (Ohmmeter mode): " << std::format("{}", measureOhm) << '\n';

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
}