#pragma once
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

namespace LES {
	static const double eps = 1e-9;
	std::vector<int> space;
	std::vector<int> where;
	std::vector<double> res;
	std::vector<std::vector<double>> gauss;
	std::ofstream out;

	void getSpaceAlign(const std::vector<std::vector<double>> a) {
		space.assign(a[0].size(), 0);
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < a[i].size(); ++j) {
				int len = 2 + a[i][j].ToString("0.000")->Length;
				if (space[j] < len)
					space[j] = len;
			}
		}
	}

	void printMatrix(const std::vector<std::vector<double>> a) {
		out << std::fixed;
		getSpaceAlign(a);
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < a[i].size() - 1; ++j)
				out << std::right << std::setw(space[j]) << std::setprecision(3) << a[i][j] << " ";
			out << "|" << std::setw(space.back()) << std::setprecision(3) << a[i].back() << "\n";
		}
		out << std::endl;
	}

	std::vector<std::vector<double>> Gauss(std::vector<std::vector<double>> a) {
		out << " ------------ Running Gauss Elimination --------------\n\n";
		int n = a.size(), m = a[0].size() - 1;
		where.assign(m, -1);
		for (int col = 0, row = 0; row < n && col < m; ++col) {
			int select = row;
			for (int i = row; i < n; ++i)
				if (abs(a[i][col]) > abs(a[select][col]))
					select = i;
			if (abs(a[select][col]) < eps) {// col i row i -> n all zero, can't convert
				out << "Cot " << col + 1 << " khong the chuan hoa!\n";
				continue;
			}
			if (abs(a[row][col]) < eps) {
				out << "Hoan vi cot (" << row + 1 << ") <-> (" << select + 1 << ").\n";
				for (int j = 0; j < a[row].size(); ++j) // basic swap operator
					std::swap(a[row][j], a[select][j]);
			}
			where[col] = row;
			for (unsigned i = row + 1; i < n; ++i) { // elimination 
				out << "The dong (" << i + 1 << ") -> " << "[(" << i + 1 << ") - " << std::setw(3) << a[i][col] << "/" << a[row][col] << " * (" << row + 1 << ")]\n";
				double coef = a[i][col] / a[row][col];
				for (unsigned j = col; j < a[i].size(); ++j)
					a[i][j] -= coef * a[row][j];
			}
			++row;
			
			/// print step
			if (row < n) printMatrix(a);
		}
		return a;
	}

	int getResult(const std::vector<std::vector<double>>& a) {
		int n = a.size(), m = a[0].size() - 1; //number of equation, number of variable
		res.assign(m, 0);
		for (int col = m - 1; col >= 0; --col) {
			int row = where[col];
			if (row == -1) continue; //cot khong the chuan hoa (non row echelon form)
			res[col] = a[row].back();
			for (int i = col + 1; i < m; ++i)
				res[col] -= a[row][i] * res[i];
			res[col] /= a[row][col];
		}
		// check conflict
		for (int i = 0; i < n; ++i) {
			bool check = true;
			for (int j = 0; j < m; ++j)
				check &= abs(a[i][j]) < eps;
			if (check && abs(a[i].back()) > eps) {// 0x + 0y + 0z + ... = x (x != 0)
				out << "Mau thuan tai dong " << i + 1 << "\n";
				out << "Vo nghiem.";
				return 0;
			}
		}
		// check infinity
		for (int i = 0; i < m; ++i)
			if (where[i] == -1) {
				out << "Vo so nghiem.\n";
				return -1;
			}
		out << "Mot nghiem duy nhat:\n";
		for (int i = 0; i < m; ++i)
			out << "x" << i + 1 << " = " << res[i] << "\n";
		return 1;
	}

	void getGeneralSolution() {
		int n = gauss.size(), m = gauss[0].size() - 1;
		for (int col = m - 1; col >= 0; --col) {
			int row = where[col];
			out << "x" << col + 1 << " = ";
			if (row == -1) {
				out << "???\n";
				continue;
			}
			double temp = gauss[row].back();
			bool check = false;
			for (int j = col + 1; j < m; ++j) {
				if (where[j] == -1)
					check = true;
				else // khong dung vi cac x o truoc phu thuoc chu khong co gia tri cu the o res[j]
					temp -= res[j] * gauss[row][j];
			}
			if (check == true) {
				/*
				out << "(" << temp;
				for (int j = col + 1; j < m; ++j) 
					if (where[j] == -1) {
						if (gauss[row][j] >= 0)
							out << " - " << gauss[row][j] << "*x" << j + 1;
						else
							out << " + " << -gauss[row][j] << "*x" << j + 1;
					}
				out << ") / " << gauss[row][col] << "\n";
				*/
				out << "?\n";
			}
			else {
				out << res[col] << "\n";
			}
			
		}
	}

	int Solve(std::vector<std::vector<double>> a) {
		out.open("solution.txt");
		out << " -------------- Origin Linear Equation ---------------\n\n";
		printMatrix(a);

		gauss = Gauss(a);
		out << "\n ------------ After Gauss Elimination --------------\n\n";
		printMatrix(gauss);

		int state = getResult(gauss);
		if (state == -1) getGeneralSolution();
		out.close();
		return state;
	}
}