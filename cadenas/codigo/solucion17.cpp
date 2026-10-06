#include <iostream>
#include <format>
#include <string>
#include <string_view>
#include <charconv>
#include <optional>
using namespace std;
// from_chars: conversion sin excepciones ni locale; informa si fallo
optional<double> aReal(string_view s){
	double v;
	auto [fin, ec] = from_chars(s.data(), s.data() + s.size(), v);
	if (ec != errc{} || fin != s.data() + s.size()) return nullopt;
	return v;
}
int main(){
	struct Fila { string nombre; int unidades; double precio; };
	Fila filas[] = {{"Lapiz", 12, 1.5}, {"Cuaderno", 3, 6.25}, {"Mochila", 1, 89.9}};

	cout << format("{:<12}|{:>8}|{:>10}|{:>10}", "Producto", "Unid.", "Precio", "Subtotal") << endl;
	cout << string(43, '-') << endl;
	double total = 0;
	for (const auto &f : filas){
		double sub = f.unidades * f.precio;
		total += sub;
		cout << format("{:<12}|{:>8}|{:>10.2f}|{:>10.2f}", f.nombre, f.unidades, f.precio, sub) << endl;
	}
	cout << format("{:>43}", format("TOTAL: {:.2f}", total)) << endl;

	cout << format("{0} en hex: {0:#x}, binario: {0:#b}, con ceros: {0:06d}", 255) << endl;
	cout << format("Porcentaje: {:.1f}%", 0.4567 * 100) << endl;
	cout << format("Centrado: [{:^11}] Relleno: [{:*>8}]", "UNI", 42) << endl;

	for (string_view s : {"3.14", "2.5e3", "abc", "7x", ""}){
		if (auto v = aReal(s))
			cout << format("\"{}\" -> {}", s, *v) << endl;
		else
			cout << format("\"{}\" -> invalido", s) << endl;
	}
	char buf[32];
	auto r = to_chars(buf, buf + sizeof(buf), 12345);
	*r.ptr = '\0';
	cout << "to_chars: " << buf << endl;
	return 0;
}
